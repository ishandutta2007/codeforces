#include <bits/stdc++.h>

using namespace std;

long long d, m;

long long num[100];
long long dp[100][100];

void solve() {
	memset(dp, 0, sizeof dp);
	scanf("%lld%lld", &d, &m);
	++d;
	int x = 0;
	for (int i = 1; i < 35; ++i) {
		if (1LL << i <= d)
			num[i] = 1LL << (i - 1);
		else {
			num[i] = d - (1LL << (i - 1));
			x = i;
			break;
		}
	}
	dp[0][1] = 1;
	for (int i = 1; i <= x; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * num[i]) % m;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= x; ++i) {
		ans += dp[x][i];
	}
	printf("%lld\n", ans % m);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}