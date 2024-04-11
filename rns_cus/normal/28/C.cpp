///	C : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, m, mx, a[N];
long double f[N][N][N];

long double calc(int i, int j, int r) {
	long double rlt = 1;
	for (int k = 1; k <= r; k ++) rlt *= 1.0 * (j - r + k) / k / i;
	for (int k = 1; k <= j - r; k ++) rlt *= 1.0 * (i - 1) / i;
	return rlt;
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) scanf("%d", &a[i]);
	for (int j = 0; j <= n; j ++) {
		f[1][j][(j+a[1]-1)/a[1]] = 1;
	}
	for (int i = 2; i <= m; i ++) {
		f[i][0][0] = 1;
		for (int j = 1; j <= n; j ++) {
			for (int r = 0; r <= j; r ++) {
				for (int k = 0; k <= j - r; k ++) {
					mx = max(k, (r + a[i] - 1) / a[i]);
					f[i][j][mx] += f[i-1][j-r][k] * calc(i, j, r);
				}
			}
		}
	}
	double ans = 0;
	for (int k = 0; k <= n; k ++) ans += f[m][n][k] * k;
	printf("%.12lf\n", ans);
	return 0;
}