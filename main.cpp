#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "timer.hpp"

static const size_t LEN = 128LL*1024LL*1024LL;

static int int_compare(const void *x_void, const void *y_void)
{
	const int *x = static_cast<const int*>(x_void);
	const int *y = static_cast<const int*>(y_void);
	return *x - *y;
}

int main()
{
	srand(0);
	std::vector<int> v_base(LEN);
	for (auto& i : v_base) {
		i = rand();
	}
	
	auto v = v_base;
	printf("Now sorting: std::sort\n");
	startPerfTimer();
	std::sort(std::begin(v), std::end(v));
	double stdsort_time = stopPerfTimer();

	v = v_base;
	printf("Now sorting: std::stable_sort\n");
	startPerfTimer();
	std::stable_sort(std::begin(v), std::end(v));
	double stable_sort_time = stopPerfTimer();

	v = v_base;
	printf("Now sorting: qsort\n");
	startPerfTimer();
	qsort(v.data(), v.size(), sizeof(int), int_compare);
	double qsort_time = stopPerfTimer();

	printf("std::sort %f -- std::stable_sort %f -- qsort %f\n", stdsort_time, stable_sort_time, qsort_time);
}
