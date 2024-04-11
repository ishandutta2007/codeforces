#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(3);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		a[i] %= 3;
		++b[a[i]];
	}
	if (b[0] >= b[1] + b[2]) {
		std::cout << "2\n";
		int c = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 0 && c++ < n / 2) std::cout << '0';
			else std::cout << '1';
		}
	} else {
		std::cout << "0\n";
		int c = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] != 0 && c++ < n / 2) std::cout << '0';
			else std::cout << '1';
		}
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