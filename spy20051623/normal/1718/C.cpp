#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 5;
std::vector<int> pn[N];

void pre_calc() {
	for (int i = 2; i < N; ++i) {
		if (!pn[i].empty()) continue;
		for (int j = i; j < N; j += i) {
			pn[j].push_back(i);
		}
	}
//	for (int i = 1; i < N; ++i) {
//		for (int j = i + i; j < N; j += i) {
//			pn[j].push_back(i);
//		}
//	}
//	int mx = 0, id;
//	for (int i = 0; i < N; ++i) {
//		if (mx < pn[i].size()) mx = pn[i].size(), id = i;
//	}
//	std::cerr << mx << " " << id << "\n";
}

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int m = pn[n].size();
	std::vector<std::vector<i64>> s(m);
	std::multiset<i64> ans;
	for (int i = 0; i < m; ++i) {
		int sz = n / pn[n][i];
		s[i].resize(sz);
		for (int j = 0; j < n; ++j) {
			s[i][j % sz] += 1ll * a[j] * sz;
		}
		for (i64 j: s[i]) ans.insert(j);
	}
	std::cout << *--ans.end() << "\n";
	while (q--) {
		int p, x;
		std::cin >> p >> x;
		--p;
		int d = x - a[p];
		a[p] = x;
		for (int i = 0; i < m; ++i) {
			int sz = n / pn[n][i], pos = p % sz;
			ans.erase(ans.find(s[i][pos]));
			s[i][pos] += 1ll * d * sz;
			ans.insert(s[i][pos]);
		}
		std::cout << *--ans.end() << "\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	pre_calc();
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}