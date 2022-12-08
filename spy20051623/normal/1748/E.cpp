#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
const int mod = 1e9 + 7;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n + 2);
	std::vector<pii> b(n + 2);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		b[i] = {a[i], i};
	}
	std::sort(b.begin() + 1, b.begin() + n + 1, [&](pii x, pii y) {
		return x.first != y.first ? x.first < y.first : x.second > y.second;
	});
	std::vector<int> l(n + 2), r(n + 2), x(n + 2);
	std::vector<std::vector<i64>> dp(n + 2, std::vector<i64>(m + 1));
	std::vector<std::vector<i64>> s(n + 2, std::vector<i64>(m + 1));
	for (int i = 0; i <= n + 1; ++i) {
		l[i] = i + 1;
		r[i] = i - 1;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= m; ++i) {
		s[0][i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		int X = b[i].second, L = x[X - 1], R = x[X + 1];
		for (int j = 1; j <= m; ++j) {
			dp[X][j] = (dp[X][j - 1] + dp[L][j - 1] * s[R][j - 1] + dp[R][j] * s[L][j - 1]) % mod;
			s[X][j] = (s[X][j - 1] + dp[X][j]) % mod;
		}
		L = l[X - 1], R = r[X + 1];
		l[L] = l[R] = L, r[L] = r[R] = R, x[L] = x[R] = X;
	}
	std::cout << s[b[n].second][m] << '\n';
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
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}