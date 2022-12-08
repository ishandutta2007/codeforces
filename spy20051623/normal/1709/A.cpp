#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x;
	std::cin >> x;
	std::vector<int> a(4);
	for (int i = 1; i <= 3; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < 2; ++i) {
		x = a[x];
	}
	if (x) std::cout << "YES\n";
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