#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	int p;
	std::cin >> p;
	std::vector<int> c(26);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		++c[s[i] - 'a'];
		sum += s[i] - 'a' + 1;
	}
	sum -= p;
	for (int i = 25; i >= 0; --i) {
		if (sum <= 0) break;
		int x = (sum - 1) / (i + 1) + 1;
		x = std::min(x, c[i]);
		c[i] -= x;
		sum -= (i + 1) * x;
	}
	for (int i = 0; i < n; ++i) {
		if (c[s[i] - 'a']) {
			std::cout << s[i];
			--c[s[i] - 'a'];
		}
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