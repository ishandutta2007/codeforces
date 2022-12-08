#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), s(n + 1);
	i64 ans = 0;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		if (a[i] < i) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1];
		if (a[i] < i && a[i] - 1 >= 0 && a[i] - 1 <= n) ans += s[a[i] - 1];
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