#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	std::vector<int> v(26);
	int c = 3, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!v[s[i] - 'a']) {
			if (c == 3) {
				c = 0;
				std::fill(v.begin(), v.end(), 0);
				++ans;
				++c;
			} else {
				++c;
			}
			v[s[i] - 'a'] = 1;
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