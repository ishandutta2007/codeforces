#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a;
	for (int i = n; i > 1; i -= 2) {
		a.push_back(i - 1);
		a.push_back(i);
	}
	if (n & 1) a.push_back(1);
	std::reverse(a.begin(), a.end());
	for (int i: a) {
		std::cout << i << ' ';
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