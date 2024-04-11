#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int p = 0;
	for (int i = 0; i < n; ++i) {
		if ((a[i] + a[0]) % 2 == 0) p = i;
	}
	std::vector<pii> ans;
	for (int i = 0; i < p; ++i) {
		if ((a[i] + a[0]) % 2 == 0) ans.emplace_back(i, p);
	}
	for (int i = 0; i < n; ++i) {
		if ((a[i] + a[0]) % 2 == 1) ans.emplace_back(0, i);
	}
	std::cout << ans.size() << '\n';
	for (auto i: ans) std::cout << i.first + 1 << ' ' << i.second + 1 << '\n';
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