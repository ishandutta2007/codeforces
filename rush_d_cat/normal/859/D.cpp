#include <bits/stdc++.h>
using namespace std;
const int N = (1<<6) + 1;
int n;
double f[N][N][N], w[N][N][N];
double p[N][N];
void solve(int l, int r, int dep) {
	if (l == r) {
		w[l][r][l] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid, dep - 1); solve(mid + 1, r, dep - 1);
	for (int i = l; i <= mid; i ++) {
		for (int j = mid + 1; j <= r; j ++) {
			w[l][r][i] += w[l][mid][i] * w[mid+1][r][j] * p[i][j];
			w[l][r][j] += w[l][mid][i] * w[mid+1][r][j] * p[j][i];
		}
	}
	for (int i = l; i <= mid; i ++) {
		for (int j = mid + 1; j <= r; j ++) {
			f[l][r][i] = max(f[l][r][i], f[l][mid][i] + f[mid+1][r][j] + (1<<(dep-1)) * w[l][r][i]);
			f[l][r][j] = max(f[l][r][j], f[l][mid][i] + f[mid+1][r][j] + (1<<(dep-1)) * w[l][r][j]);
		}
	}
	for (int i = l; i <= r; i ++) {
		// printf("f[%d][%d][%d] = %.6f\n", l, r, i, f[l][r][i]);
	}
}
int main() {
	scanf("%d", &n); 
	for (int i = 1; i <= 1<<n; i ++) {
		for (int j = 1; j <= 1<<n; j ++) {
			scanf("%lf", &p[i][j]); p[i][j] /= 100;
		}
	}
	// printf("# %.5f %.5f\n", p[1][2], p[2][1]);
	solve(1, 1<<n, n);
	double ans = 0;
	for (int i = 1; i <= 1<<n; i ++) ans = max(ans, f[1][1<<n][i]);
	printf("%.10f\n", ans);

}