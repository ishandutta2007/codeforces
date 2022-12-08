#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s, t;
	std::cin >> s >> t;
	if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
		std::cout << "-1\n";
		return;
	}
	s += '0';
	t += '0';
	std::vector<std::pair<int, int>> a, b;
	int p = -1;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == '1' && p == -1) p = i;
		if (s[i] == '0' && p != -1) a.emplace_back(p, i - 1), p = -1;
	}
	for (int i = 0; i <= n; ++i) {
		if (t[i] == '1' && p == -1) p = i;
		if (t[i] == '0' && p != -1) b.emplace_back(p, i - 1), p = -1;
	}
	if (a.size() != b.size()) {
		std::cout << "-1\n";
		return;
	}
	int m = a.size();
	i64 ans = 0;
	for (int i = 0; i < m; ++i) {
		ans += abs(a[i].first - b[i].first) + abs(a[i].second - b[i].second);
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