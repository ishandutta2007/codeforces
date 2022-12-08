#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::multiset<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		while ((x & 1) == 0) x >>= 1;
		s.insert(x);
	}
	bool ans = true;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		bool ok = false;
		while (x) {
			auto it = s.find(x);
			if (it != s.end()) {
				s.erase(it);
				ok = true;
				break;
			}
			x >>= 1;
		}
		if (!ok) ans = false;
	}
	if (!ans) std::cout << "NO\n";
	else std::cout << "YES\n";
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