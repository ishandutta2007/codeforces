#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::string s(m, 'B');
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		x = std::min(x, m + 1 - x);
		if (s[x - 1] == 'A') s[m - x] = 'A';
		else s[x - 1] = 'A';
	}
	std::cout << s << '\n';
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