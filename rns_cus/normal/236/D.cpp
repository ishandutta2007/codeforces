#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n;
double p[N], x[N], y[N], f[N], g[N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i ++) y[i] = (y[i-1] + 1.0) * p[i];
	for (int i = 1; i <= n; i ++) x[i] = p[i] * x[i-1] + 2.0 * y[i] - p[i];

	for (int i = 1; i <= n; i ++) {
		g[i] = p[i] * g[i-1] + (1.0 - p[i]) * f[i-1];
		f[i] = x[i] + g[i];
	}
    printf("%.12lf\n", f[n]);
}