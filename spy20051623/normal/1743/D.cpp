#include <bits/stdc++.h>

using i64 = long long;

int cmp(std::bitset<1000000> x, std::bitset<1000000> y) {
	for (int i = 999999; i >= 0; --i) {
		if (x[i] != y[i]) return x[i] < y[i];
	}
	return 0;
}

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::reverse(s.begin(), s.end());
	std::bitset<1000000> b, ans;
	for (int i = 0; i < n; ++i) {
		b[i] = s[i] - '0';
	}
	int tt = std::min(n, 10);
	for (int i = 0; i < tt; ++i) {
		ans = std::max(ans, b | b >> i, cmp);
	}
	bool f = false;
	for (int i = 999999; i >= 0; --i) {
		if (ans[i]) f = true;
		if (f || !i) std::cout << ans[i];
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
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}