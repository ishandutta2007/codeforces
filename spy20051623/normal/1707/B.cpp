#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::reverse(a.begin(), a.end());
	int c = 0;
	while (!a.empty() && a.back() == 0) ++c, a.pop_back();
	for (int i = 0; i < n - 1; ++i) {
		std::vector<int> b;
		int m = a.size();
		for (int j = 0; j < m - 1; ++j) {
			b.push_back(a[j] - a[j + 1]);
		}
		if (!a.empty() && c) b.push_back(a.back());
		if (c) --c;
		std::sort(b.begin(), b.end(), std::greater<>());
		while (!b.empty() && b.back() == 0) ++c, b.pop_back();
		a = b;
	}
	if (c) a.push_back(0);
	std::cout << a[0] << '\n';
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