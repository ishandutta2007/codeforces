#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string s, t;
	std::cin >> s >> t;
	std::set<int> p[3];
	for (int i = 0; i < n; ++i) {
		p[s[i] - 'a'].insert(i);
	}
	for (int i = 0; i < n; ++i) {
		if (p[t[i] - 'a'].empty()) {
			std::cout << "NO\n";
			return;
		}
		if (*p[t[i] - 'a'].begin() == i) p[t[i] - 'a'].erase(p[t[i] - 'a'].begin());
		else if (t[i] == 'b') {
			auto it = p[1].begin();
			if (p[2].empty() || *p[2].begin() > *it) {
				p[0].erase(p[0].begin());
				p[0].insert(*it);
				p[1].erase(it);
			} else {
				std::cout << "NO\n";
				return;
			}
		} else if (t[i] == 'c') {
			auto it = p[2].begin();
			if (p[0].empty() || *p[0].begin() > *it) {
				p[1].erase(p[1].begin());
				p[1].insert(*it);
				p[2].erase(it);
			} else {
				std::cout << "NO\n";
				return;
			}
		} else {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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