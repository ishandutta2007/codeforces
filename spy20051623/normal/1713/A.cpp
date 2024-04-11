#include <bits/stdc++.h>

using i64 = long long;

#define sqr(x) ((x)*(x))

void solve() {
	int n;
	std::cin >> n;
	int l = 0, r = 0, u = 0, d = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		l = std::min(l, x);
		r = std::max(r, x);
		u = std::max(u, y);
		d = std::min(d, y);
	}
	std::cout << (r - l + u - d) * 2 << '\n';
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