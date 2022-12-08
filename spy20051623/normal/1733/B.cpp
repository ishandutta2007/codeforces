#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, x, y;
	std::cin >> n >> x >> y;
	if (x > y) std::swap(x, y);
	if (x || !y || (n - 1) % y) {
		std::cout << "-1\n";
		return;
	}
	for (int i = 2; i <= n; i += y) {
		for (int j = 0; j < y; ++j) {
			std::cout << i << ' ';
		}
	}
	std::cout << '\n';
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