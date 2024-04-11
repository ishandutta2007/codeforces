#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	std::set<std::string> a;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
		a.insert(v[i]);
	}
	for (std::string &s: v) {
		int len = s.length();
		bool ok = false;
		for (int i = 1; i < len; ++i) {
			if (a.count(s.substr(0, i)) && a.count(s.substr(i))) {
				ok = true;
				break;
			}
		}
		if (ok) std::cout << '1';
		else std::cout << '0';
	}
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