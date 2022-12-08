#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::set<int> s;
	int pre = 0, ans = n;
	for (int i = 0; i < n; ++i) {
		if (!a[i] || s.count(a[i] ^ pre)) {
			s.clear();
			pre = 0;
			--ans;
		} else {
			pre ^= a[i];
			s.insert(a[i] ^ pre);
		}
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