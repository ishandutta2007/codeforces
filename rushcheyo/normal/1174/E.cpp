#include <bits/stdc++.h>
using namespace std;

const int N = 1000005, P = 1000000007;
int n, k, dp[N][20][2], cnt[20][2];

int main() {
	scanf("%d", &n);
	while (1 << k + 1 <= n) ++k;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; !(i & ((1 << j) - 1)); ++j)
			for (int k = 0; k <= (i % 3 == 0); ++k)
				++cnt[j][k];
	dp[1][k][0] = 1;
	if (k && 3 << k - 1 <= n)
		dp[1][k - 1][1] = 1;
	for (int i = 1; i < n; ++i)
		for (int a = 0; a <= k; ++a)
			for (int b = 0; b < 2; ++b)
				if (dp[i][a][b]) {
					if (i != cnt[a][b])
						dp[i + 1][a][b] = (dp[i + 1][a][b] + 1LL * dp[i][a][b] * (cnt[a][b] - i)) % P;
					if (a)
						dp[i + 1][a - 1][b] = (dp[i + 1][a - 1][b] + 1LL * dp[i][a][b] * (cnt[a - 1][b] - cnt[a][b])) % P;
					if (b)
						dp[i + 1][a][b - 1] = (dp[i + 1][a][b - 1] + 1LL * dp[i][a][b] * (cnt[a][b - 1] - cnt[a][b])) % P;
				}
	printf("%d\n", dp[n][0][0]);
	return 0;
}