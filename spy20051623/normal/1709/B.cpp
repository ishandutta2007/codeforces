#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<i64> a(n + 2), pre(n + 2), suf(n + 2);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		if (a[i] < a[i - 1]) pre[i] = pre[i - 1] + a[i - 1] - a[i];
		else pre[i] = pre[i - 1];
	}
	for (int i = n - 1; i >= 1; --i) {
		if (a[i] < a[i + 1]) suf[i] = suf[i + 1] + a[i + 1] - a[i];
		else suf[i] = suf[i + 1];
	}
	while (m--) {
		int x, y;
		std::cin >> x >> y;
		if (x > y) std::cout << suf[y] - suf[x] << '\n';
		else std::cout << pre[y] - pre[x] << '\n';
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