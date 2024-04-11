#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> mp(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> mp[i];
	}
	int al = 1e9, ar = -1e9, bl = 1e9, br = -1e9;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == 'B') {
				al = std::min(al, i + j);
				ar = std::max(ar, i + j);
				bl = std::min(bl, i - j);
				br = std::max(br, i - j);
			}
		}
	}
	int x, y, ans = 1e9;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (std::max(std::max(abs(i + j - al), abs(i + j - ar)),
						 std::max(abs(i - j - bl), abs(i - j - br))) < ans) {
				ans = std::max(std::max(abs(i + j - al), abs(i + j - ar)),
							   std::max(abs(i - j - bl), abs(i - j - br)));
				x = i, y = j;
			}
		}
	}
	std::cout << x + 1 << ' ' << y + 1 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
}