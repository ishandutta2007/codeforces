#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	int w, m;
	std::cin >> w >> m;
	std::vector<int> a(n + 1);
	for (int i = 0; i < n; ++i) {
		a[i + 1] = a[i] + s[i] - '0';
	}
	std::vector<int> c[9];
	for (int i = w; i <= n; ++i) {
		c[(a[i] - a[i - w]) % 9].push_back(i - w + 1);
	}
	while (m--) {
		int l, r, k;
		std::cin >> l >> r >> k;
		int x = (a[r] - a[l - 1]) % 9;
		std::pair<int, int> ans = {n + 1, n + 1};
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if ((i * x + j) % 9 == k) {
					if (i == j && c[i].size() >= 2) {
						std::pair<int, int> now = {c[i][0], c[i][1]};
						ans = std::min(ans, now);
					}
					if (i != j && !c[i].empty() && !c[j].empty()) {
						std::pair<int, int> now = {c[i][0], c[j][0]};
						ans = std::min(ans, now);
					}
				}
			}
		}
		if (ans.first == n + 1) std::cout << "-1 -1\n";
		else std::cout << ans.first << ' ' << ans.second << '\n';
	}

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