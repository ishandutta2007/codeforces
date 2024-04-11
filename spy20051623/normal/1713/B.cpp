#include <bits/stdc++.h>

using i64 = long long;

#define sqr(x) ((x)*(x))

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	i64 ans = 0, now = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > now) ans += a[i] - now;
		now = a[i];
	}
	std::sort(a.begin(), a.end());
	i64 ans1 = 0, now1 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > now1) ans1 += a[i] - now1;
		now1 = a[i];
	}
	if (ans == ans1) std::cout << "YES\n";
	else std::cout << "NO\n";
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