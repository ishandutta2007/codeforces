#include <bits/stdc++.h>

using namespace std;
const int N = 5005;
const int mod = 998244353;
int a[N], multiply[N], divide[N];
long long dp[N][N], add[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int p = 0, i = 1; i <= n; ++i) {
		while (a[p + 1] * 2 <= a[i]) ++p;
		divide[i] = p;
	}
	for (int p = n + 1, i = n; i >= 1; --i) {
		while (a[p - 1] >= a[i] * 2) --p;
		multiply[i] = p;
	}
	divide[0] = -1;
	multiply[0] = 1;
	dp[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			add[j] += add[j - 1];
			dp[i][j] += add[j];
			dp[i][j] %= mod;
		}
		memset(add, 0, sizeof add);
		for (int j = 0; j <= n; ++j) {
			dp[i + 1][j] += (divide[j] - i + 1) * dp[i][j];
			add[multiply[j]] += dp[i][j];
		}
	}
	printf("%lld\n", dp[n][n]);
	return 0;
}