#include <cstdio>

const int MAXN = 1E3 + 10;

int a[MAXN][MAXN];
int vis[MAXN], inf[MAXN];
double A[MAXN], B[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < n; ++i){
		A[i] = B[i] = 1;
		inf[i] = true;
	}
	B[n - 1] = 0;
	A[n - 1] = 0;
	inf[n - 1] = false;
	for (int i = 1; i < n; ++i){
		int u = 0;
		for (; u < n && (vis[u] || inf[u]); ++u);
		for (int j = u + 1; j < n; ++j)
			if (!vis[j] && !inf[j] && B[j] / (1.0 - A[j]) < B[u] / (1.0 - A[u]))
				u = j;
		if (u >= n)
			break;

		vis[u] = true;

		double t = B[u] / (1.0 - A[u]);
		for (int j = 0; j < n; ++j)
			if (!vis[j] && a[j][u]){
				inf[j] = false;
				B[j] += A[j] * a[j][u] / 100 * t;
				A[j] *= 1.0 - a[j][u] / 100.0;
			}
	}
	printf("%.10lf\n", B[0] / (1.0 - A[0]));
	return 0;
}