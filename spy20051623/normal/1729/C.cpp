#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	std::vector<int> p[26];
	for (int i = 1; i < n - 1; ++i) {
		p[s[i] - 'a'].push_back(i + 1);
	}
	int ss = s[0] < s[n - 1] ? 1 : -1;
	std::vector<int> ans;
	ans.push_back(1);
	for (int i = s[0] - 'a'; i != s[n - 1] - 'a'; i += ss) {
		for (int j: p[i]) ans.push_back(j);
	}
	for (int j: p[s[n - 1] - 'a']) ans.push_back(j);
	ans.push_back(n);
	std::cout << abs(s[0] - s[n - 1]) << ' ' << ans.size() << '\n';
	for (int i: ans) std::cout << i << ' ';
	std::cout << '\n';
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