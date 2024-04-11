#include <bits/stdc++.h>

using namespace std;
const int N = 85;
int a[N], b[N], c[N];
int dp[N][N][N * (N - 1) / 2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int cur = 0, cnt = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i]) b[++cnt] = cur, c[cnt] = c[cnt - 1] + b[cnt], cur = 0;
		else ++cur, ++sum;
	}
	b[++cnt] = cur, c[cnt] = c[cnt - 1] + b[cnt];
	memset(dp, 63, sizeof dp);
//	for (int i = 0; i <= n * (n - 1) / 2; ++i) {
//		dp[0][0][i] = 0;
//	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= cnt; ++i) {
		for (int j = 0; j <= sum; ++j) {
			for (int k = 0; k <= n * (n - 1) / 2; ++k) {
				dp[i][j][k] = dp[i - 1][j][k];
			}
			for (int k = 0; k <= j; ++k) {
				int s = abs(c[i] - j);
				for (int l = 0; l <= n * (n - 1) / 2 - s; ++l) {
					dp[i][j][l + s] = min(dp[i][j][l + s], dp[i - 1][k][l] + (j - k) * (j - k));
				}
			}
			for (int k = 1; k <= n * (n - 1) / 2; ++k) {
				dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1]);
			}
		}
	}
	for (int i = 0; i <= n * (n - 1) / 2; ++i) {
		int d = dp[cnt][sum][i];
		int res = sum * sum - d;
		printf("%d ", res / 2);
	}
	return 0;
}