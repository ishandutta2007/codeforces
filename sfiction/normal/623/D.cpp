#include <cstdio>

const int MAXN = 1E2 + 10, MAXR = 1E6;

int n;
double p[MAXN], f[MAXN];

int main(){
	scanf("%d", &n);
	if (n == 1){
		puts("1");
		return 0;
	}
	double tot = 1.0;
	for (int i = 0 ; i < n; ++i){
		scanf("%lf", &p[i]);
		tot *= p[i] /= 100.0;
		f[i] = 1 - p[i];
	}
	double ans = MAXR + 1 + n - tot;
	for (int i = 0; i < MAXR; ++i){
		int u = 0;
		for (int j = 1; j < n; ++j)
			if (p[u] * f[u] * (1 - f[j]) < p[j] * f[j] * (1 - f[u]))
				u = j;
		tot /= 1 - f[u];
		f[u] *= 1 - p[u];
		tot *= 1 - f[u];
		ans -= tot;
	}
	printf("%.12f\n", ans);
	return 0;
}