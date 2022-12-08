#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	b[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (b[i - 1] && i + a[i] <= n) b[i + a[i]] = 1;
		if (i - a[i] - 1 >= 0 && b[i - a[i] - 1]) b[i] = 1;
	}
	if (b[n]) std::cout << "YES\n";
	else std::cout << "NO\n";
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