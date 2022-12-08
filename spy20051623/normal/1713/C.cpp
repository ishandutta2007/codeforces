#include <bits/stdc++.h>

using i64 = long long;

#define sqr(x) ((x)*(x))

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a;
	int q = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (q == -1) q = i ? sqr((int) __builtin_sqrt(i - 1) + 1) : 0;
		if (q - i > n - 1) {
			std::cout << "-1\n";
			return;
		}
		a.push_back(q - i);
		if (q - i == n - 1) {
			n = i;
			q = -1;
		}
	}
	std::reverse(a.begin(), a.end());
	for (int i: a) std::cout << i << ' ';
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