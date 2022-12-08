#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;
	i64 x = 1;
	for (int i = 0; i < 100; ++i) {
		if (x * 10 > n) {
			std::cout << n - x << '\n';
			return;
		}
		x *= 10;
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