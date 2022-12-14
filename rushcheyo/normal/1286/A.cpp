#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, p[N], dp[N][N][2];

int main() {
	scanf("%d", &n);
	int ans = 0;
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i);
		if (p[i]) {
			for (int j = 0; j <= n; ++j)
				for (int k = 0; k < 2; ++k)
					if (dp[i - 1][j][k] <= n)
						dp[i][j + (p[i] % 2 == 0)][p[i] % 2] = min(dp[i][j + (p[i] % 2 == 0)][p[i] % 2], dp[i - 1][j][k] + (k != p[i] % 2));
		} else {
			for (int j = 0; j <= n; ++j)
				for (int k = 0; k < 2; ++k)
					if (dp[i - 1][j][k] <= n) {
						dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i - 1][j][k] + (k == 1));
						dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][k] + (k == 0));
					}
		}
	}
	printf("%d\n", min(dp[n][n / 2][0], dp[n][n / 2][1]));
}