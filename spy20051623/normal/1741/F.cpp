#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

struct seg {
	int l{}, r{}, c{};
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<seg> a, b;
	std::map<int, int> m;
	for (int i = 0; i < n; ++i) {
		seg s;
		std::cin >> s.l >> s.r >> s.c;
		a.push_back(s);
		m[s.l];
//		if (s.l != s.r) m[s.l + 1];
//		if (s.l != s.r) m[s.r - 1];
		m[s.r];
	}
	b = a;
	std::sort(b.begin(), b.end(), [&](seg &x, seg &y) { return x.l < y.l; });
	int p = 0;
	std::multiset<int> s;
	std::priority_queue<pii, std::vector<pii>, std::greater<>> q;
	for (auto &i: m) {
		while (p < n && b[p].l <= i.first) {
			s.insert(b[p].c);
			q.emplace(b[p].r, b[p].c);
			++p;
		}
		if (*s.begin() == *--s.end()) i.second = *s.begin();
		else i.second = 0;
		while (!q.empty() && q.top().first <= i.first) s.erase(s.find(q.top().second)), q.pop();
	}
	std::vector<std::vector<int>> v(n + 1), u(n + 1);
	std::set<int> x;
	for (auto i: m) {
		v[i.second].push_back(i.first);
		x.insert(i.first);
	}
	for (int i = 0; i < n; ++i) {
		u[a[i].c].push_back(i);
	}
	std::vector<int> ans(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j: v[i]) x.erase(j);
		for (int j: u[i]) {
			auto l = x.lower_bound(a[j].l), r = x.upper_bound(a[j].r);
			if (l != r) ans[j] = 0;
			else {
				int z = 2e9;
				if (l != x.begin()) z = std::min(z, a[j].l - *std::prev(l));
				if (r != x.end()) z = std::min(z, *r - a[j].r);
				ans[j] = z;
			}
		}
		for (int j: v[i]) x.insert(j);
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << ' ';
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