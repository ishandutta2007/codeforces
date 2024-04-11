#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> ans;
	if (n & 1) {
		ans.push_back(1);
		ans.push_back(2);
		ans.push_back(3);
		for (int i = n - 2; i >= 4; --i) {
			ans.push_back(i);
		}
		ans.push_back(n - 1);
		ans.push_back(n);
	} else {
		for (int i = n - 2; i >= 1; --i) {
			ans.push_back(i);
		}
		ans.push_back(n - 1);
		ans.push_back(n);
	}
	for (int i: ans) std::cout << i << ' ';
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