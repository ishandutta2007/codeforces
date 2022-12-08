#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 x, y;
	std::cin >> x >> y;
	if (y == 1) std::cout << x - 1 << '\n';
	else std::cout << x * (y - 1) << '\n';
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