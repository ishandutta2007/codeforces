#include <bits/stdc++.h>

using i64 = long long;
const int mod = 998244353;
i64 dp[2][2][2][200005];
std::string s;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

const int v[6][3] = {{1, 0, 0},
					 {0, 1, 0},
					 {0, 1, 1},
					 {1, 0, 1},
					 {0, 0, 0},
					 {1, 1, 1}};
const int cnt[4] = {6, 2, 4, 4};

i64 dfs(int x, int y, int z, int p) {
	if (p == -1) return 1;
	if (dp[x][y][z][p] != -1) return dp[x][y][z][p];
	if (!x && !y && !z) return dp[x][y][z][p] = quickpow(6, p + 1);
	dp[x][y][z][p] = 0;
	for (auto i: v) {
		if (x && s[p] == '0' && i[0]) continue;
		if (y && s[p] == '0' && i[1]) continue;
		if (z && s[p] == '0' && i[2]) continue;
		i64 nxt = dfs(x && s[p] - '0' == i[0],
					  y && s[p] - '0' == i[1],
					  z && s[p] - '0' == i[2], p - 1);
		dp[x][y][z][p] = (dp[x][y][z][p] + nxt) % mod;
	}
	return dp[x][y][z][p];
}

void solve() {
	memset(dp, -1, sizeof dp);
	std::cin >> s;
	int n = s.length();
	i64 val = 0;
	for (int i = 0; i < n; ++i) {
		val = (val * 2 + s[i] - '0') % mod;
	}
	val = (val + 1) % mod;
	std::reverse(s.begin(), s.end());
	i64 A0 = dfs(1, 1, 1, n - 1);
	i64 A1 = val * (val - 1) % mod * 2 % mod;
	i64 A2 = val;
	i64 tot = val * (val - 1) % mod * (val - 2) % mod;
	i64 ans = tot - (A0 - A1 - A2) * 3;
	ans = (ans % mod + mod) % mod;
	std::cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}