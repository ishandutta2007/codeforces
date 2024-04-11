#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::cout << std::max(0, sum - m) << '\n';
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