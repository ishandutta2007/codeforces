#include <cstdio>

#define N 200005

const double EPS = 1e-12;

int n;
double a[N];

double calc_max(double x) {
	double rlt = 0, cur = 0;
	for (int i = 1; i <= n; i ++) {
		cur += a[i] - x;
		if (cur < 0) cur = 0;
		if (rlt < cur) rlt = cur;
	}
	return rlt;
}

double calc_min(double x) {
	double rlt = 0, cur = 0;
	for (int i = 1; i <= n; i ++) {
		cur += a[i] - x;
		if (cur > 0) cur = 0;
		if (rlt > cur) rlt = cur;
	}
	return rlt;
}

main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%lf", a + i);
	}
	double lo = -10000, hi = 10000;
	while (hi - lo > EPS) {
		double mid = (lo + hi) / 2;
		if (calc_max(mid) + calc_min(mid) < 0) hi = mid;
		else lo = mid;
	}
	printf("%.9lf\n", calc_max(hi));
}