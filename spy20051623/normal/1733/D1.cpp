#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
	int n;
	i64 x, y;
	std::cin >> n >> x >> y;
	std::string s, t;
	std::cin >> s >> t;
	std::vector<int> a;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) a.push_back(i);
	}
	int m = a.size();
	if (m & 1) {
		std::cout << "-1\n";
		return;
	}
	if (x >= y) {
		if (m == 2 && a[0] + 1 == a[1]) std::cout << std::min(x, y + y) << '\n';
		else std::cout << m / 2 * y << '\n';
	} else {

	}
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