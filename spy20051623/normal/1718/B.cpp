#include <bits/stdc++.h>

using i64 = long long;
i64 f[500], s[500], x[500], y[500];

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	i64 sum = 0;
	std::priority_queue<std::pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum += a[i];
		q.push({a[i], 1000});
	}
	int p = 0;
	while (s[p] < sum) ++p;
	if (s[p] > sum) {
		std::cout << "NO\n";
		return;
	}
	for (; p >= 0; --p) {
		auto v = q.top();
		q.pop();
		if (v.first < f[p] || v.second == p + 1) {
			std::cout << "NO\n";
			return;
		}
		q.push({v.first - f[p], p});
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
	f[0] = f[1] = s[0] = x[0] = y[1] = 1;
	s[1] = 2;
	for (int i = 2; i < 500; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		s[i] = s[i - 1] + f[i];
//		std::cout << "i=" << i << ", f[i]=" << f[i] << ", s[i]=" << s[i] << ", ";
//		if (i & 1 ^ 1) x[i] = x[i - 2] + f[i], std::cout << "x[i]=" << x[i] << "\n";
//		else y[i] = y[i - 2] + f[i], std::cout << "y[i]=" << y[i] << "\n";
		if (f[i] > 1e15) break;
	}
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}