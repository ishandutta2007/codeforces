#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	std::map<int, int> mn, mx;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (!mn.count(a[i])) mn[a[i]] = i;
		mx[a[i]] = i;
	}
	while (k--) {
		int x, y;
		std::cin >> x >> y;
		if (mn.count(x) && mn.count(y) && mn[x] <= mx[y]) std::cout << "YES\n";
		else std::cout << "NO\n";
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