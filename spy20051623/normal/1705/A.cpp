#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + n);
	for (int i = 0; i < n + n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		if (a[i + n] - a[i] < k) {
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