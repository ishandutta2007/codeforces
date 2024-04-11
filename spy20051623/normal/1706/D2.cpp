#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	const int inf = 1e9;
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> b(a[0] + 1);
	for (int i = 0; i < n; ++i) {
		std::vector<int> c;
		c.push_back(inf);
		for (int j = 1; j <= k; j = a[i] / (a[i] / j) + 1) {
			c.push_back(a[i] / j);
			if (j > a[i]) break;
		}
		c.push_back(-1);
		std::reverse(c.begin(), c.end());
		for (int j = 1; j < c.size(); ++j) {
			if (c[j - 1] + 1 <= a[0]) b[c[j - 1] + 1] = std::max(b[c[j - 1] + 1], c[j]);
		}
	}
	for (int i = 1; i <= a[0]; ++i) {
		b[i] = std::max(b[i - 1], b[i]);
	}
	int ans = inf;
	for (int i = 0; i <= a[0]; ++i) {
		ans = std::min(ans, b[i] - i);
	}
	std::cout << ans << '\n';
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