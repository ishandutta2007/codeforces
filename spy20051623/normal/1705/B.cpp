#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	i64 sum = 0;
	int f = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (i < n - 1) {
			sum += a[i];
			if (a[i]) f = 1;
			if (!a[i] && f) ++sum;
		}
	}
	std::cout << sum << '\n';
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