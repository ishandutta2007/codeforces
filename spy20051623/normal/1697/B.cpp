#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<i64> a(n + 1), s(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end(), std::greater<>());
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		std::cout << s[x] - s[x - y] << '\n';
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
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}