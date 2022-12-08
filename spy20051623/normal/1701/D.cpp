#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1), l(n + 1), r(n + 1);
	std::vector<std::vector<int>> g(n + 1, std::vector<int>());
	std::set<int> s;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		s.insert(i);
		l[i] = i / (a[i] + 1) + 1;
		r[i] = a[i] ? i / a[i] : n;
		g[l[i]].push_back(i);
	}
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
	for (int i = 1; i <= n; ++i) {
		for (int j: g[i]) {
			q.emplace(r[j], j);
		}
		std::pair<int, int> p = q.top();
		q.pop();
		b[p.second] = i;
	}
	for (int i = 1; i <= n; ++i) {
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