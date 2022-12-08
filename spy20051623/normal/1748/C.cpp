#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	i64 f = 0, s = 0, ans = 0;
	std::map<i64, int> mp;
	for (int i = 0; i <= n; ++i) {
		s += a[i];
		if (a[i]) ++mp[s];
		else if (!f) {
			ans += mp[0];
			mp.clear();
			mp[0] = 1;
			f = 1;
			s = 0;
		} else {
			int mx = 0;
			for (auto j: mp) mx = std::max(mx, j.second);
			ans += mx;
			mp.clear();
			mp[0] = 1;
			s = 0;
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