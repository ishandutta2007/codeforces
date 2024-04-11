#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	int mn = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] < b[mn]) mn = i;
		if (a[i] > b[i]) {
			std::cout << "NO\n";
			return;
		}
	}
	for (int i = (mn + n - 1) % n; i != mn; i = (i + n - 1) % n) {
		if (a[i] < b[i] && b[i] > b[(i + 1) % n] + 1) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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