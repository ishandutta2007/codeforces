#include <cmath>
#include <cstdio>

#define N 100005

typedef __int64 LL;

int x[N], y[N];
LL d[N];

main() {
	int px, py, n;
	double r = 1e10, R = 0;
	scanf("%d %d %d", &n, &px, &py);
	for (int i = 0; i < n; i ++) {
		scanf("%d %d", x + i, y + i);
		d[i] = 1LL * (x[i] - px) * (x[i] - px) + 1LL * (y[i] - py) * (y[i] - py);
		double D = sqrt(d[i]);
		if (R < D) R = D;
		if (D < r) r = D;
	}
	for (int i = 0; i < n; i ++) {
		int j = (i + 1) % n;
		LL tmp = 1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j]);
		if (d[i] + tmp < d[j] || d[j] + tmp < d[i]) continue;
		LL area = 1LL * (px - x[i]) * (py - y[j]) - 1LL * (py - y[i]) * (px - x[j]);
		double D = fabs(area / sqrt(tmp));
		if (D < r) r = D;
	}
	printf("%.15lf\n", (R * R - r * r) * acos(-1));
}