#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), b;
	std::set<int> x;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		x.insert(i + 1);
	}
	if (n == 1) {
		std::cout << "-1\n";
		return;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != *x.begin()) b.push_back(*x.begin()), x.erase(x.begin());
		else b.push_back(*++x.begin()), x.erase(++x.begin());
	}
	b.push_back(*x.begin());
	if (a[n - 1] == b[n - 1]) std::swap(b[n - 1], b[n - 2]);
	for (int i = 0; i < n; ++i) {
		std::cout << b[i] << ' ';
	}
	std::cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
}