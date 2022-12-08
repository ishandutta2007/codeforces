#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int s = 0;
	for (int i = 0; i < 4; ++i) {
		int x;
		std::cin >> x;
		s += x;
	}
	if (s == 0) std::cout << "0\n";
	else if (s == 4) std::cout << "2\n";
	else std::cout << "1\n";
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