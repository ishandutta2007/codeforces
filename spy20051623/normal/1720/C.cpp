#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> mp(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> mp[i];
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sum += mp[i][j] - 48;
		}
	}
	int d = 2;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			int s = mp[i][j] + mp[i + 1][j] + mp[i][j + 1] + mp[i + 1][j + 1] - 48 * 4;
			if (s == 3) d = std::min(d, 1);
			else if (s <= 2) d = 0;
		}
	}
	std::cout << sum - d << '\n';
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