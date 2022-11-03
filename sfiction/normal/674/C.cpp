#include <cstdio>

const int MAXN = 2E5 + 10, MAXM = 51;

int n, m;
int a[MAXN];
double s0[MAXN];
double s1[MAXN], s2[MAXN];

double x[MAXN], y[MAXN];
double f[MAXM][MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i){
		s0[i] = s0[i - 1] + a[i];
		s1[i] = s1[i - 1] + 1.0 / a[i];
		s2[i] = s2[i - 1] + s0[i] / a[i];
		f[1][i] = s2[i];
	}

	for (int k = 2; k <= m; ++k){
		int head = 0, tail = 0;
		y[0] = 0.0, x[0] = 0.0;
		for (int i = 1; i <= n; ++i){
			for (; head < tail && y[head] + s1[i] * (x[head + 1] - x[head]) > y[head + 1]; ++head);
			f[k][i] = y[head] - x[head] * s1[i] + s2[i];

			double ty = f[k - 1][i] - s2[i] + s0[i] * s1[i];
			double tx = s0[i];
			for (; tail > 0 && (x[tail] - tx) * (y[tail - 1] - ty) - (x[tail - 1] - tx) * (y[tail] - ty) > 0; --tail);
			x[++tail] = tx;
			y[tail] = ty;
		}
	}
	printf("%.8f\n", f[m][n]);
	return 0;
}