#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	if (n == 2) std::cout << "2 1\n";
	else if (n == 3) std::cout << "-1\n";
	else {
		std::cout << n - 1 << ' ' << n << ' ';
		for (int i = 1; i <= n - 2; ++i) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
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