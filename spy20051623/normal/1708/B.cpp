#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, l, r;
	std::cin >> n >> l >> r;
	std::vector<int> a;
	for (int i = 0; i < n; ++i) {
		int x = ((l - 1) / (i + 1) + 1) * (i + 1);
		if (x <= r) a.push_back(x);
		else {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << ' ';
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