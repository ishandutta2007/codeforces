#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 5;
int a[2][N], s[2][N];

void solve() {
	int m;
	std::cin >> m;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}
	s[0][m - 1] = a[1][m - 1];
	s[1][m - 1] = a[0][m - 1];
	for (int i = m - 2; i >= 0; --i) {
		s[0][i] = std::max({s[0][i + 1] - 1, a[0][i + 1], a[1][i] - (m - i - 1) * 2});
		s[1][i] = std::max({s[1][i + 1] - 1, a[1][i + 1], a[0][i] - (m - i - 1) * 2});
	}
	int ans = 2e9, now = 0;
	for (int i = 0; i < m; ++i) {
		int f = i & 1;
		ans = std::min(ans, std::max(now, s[f][i]) + (m - i - 1) * 2 + 1);
		now = std::max({now + 2, a[f ^ 1][i] + 2, a[f ^ 1][i + 1] + 1});
	}
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
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}