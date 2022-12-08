#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k, r, c;
	std::cin >> n >> k >> r >> c;
	std::vector<std::string> m(n, std::string(n, '.'));
	int x = (r + c - 2) % k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % k == x) m[i][j] = 'X';
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << m[i] << '\n';
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