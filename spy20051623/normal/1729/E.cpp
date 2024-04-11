#include <bits/stdc++.h>

using i64 = long long;

i64 qry(i64 x) {
	std::cout << "? 1 " << x << std::endl;
	i64 a, b;
	std::cin >> a;
	if (a == -1) return -1;
	std::cout << "? " << x << " 1" << std::endl;
	std::cin >> b;
	if (a == b) return 0;
	return a + b;
}

void solve() {
	for (int i = 2; i <= 26; ++i) {
		i64 x = qry(i);
		if (x == -1) {
			std::cout << "! " << i - 1 << std::endl;
			return;
		}
		if (x > 0) {
			std::cout << "! " << x << std::endl;
			return;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
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