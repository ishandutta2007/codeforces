#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int p = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] - '0') {
			if (p != -1 && a[p] > a[i]) {
				std::swap(s[p], s[i]);
				p = i;
			}
		} else p = i;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] - '0') ans += a[i];
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