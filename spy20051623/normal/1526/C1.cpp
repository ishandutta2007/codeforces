#include <bits/stdc++.h>

using namespace std;

long long a[2005];
long long dp[2005][2005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dp[i][j] == -1)
				continue;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
		}
	}
	int maxm = -1;
	for (int i = 0; i <= n; ++i) {
		if (dp[n][i] != -1)
			maxm = i;
	}
	printf("%d\n", maxm);
	return 0;
}