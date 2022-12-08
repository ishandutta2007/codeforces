#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		std::vector<int> c(10);
		int v = 0;
		for (int j = i; j < n && j < i + 100; ++j) {
			if (!c[s[j] - '0']) ++v;
			++c[s[j] - '0'];
			if (*std::max_element(c.begin(), c.end()) <= v) ++ans;
		}
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