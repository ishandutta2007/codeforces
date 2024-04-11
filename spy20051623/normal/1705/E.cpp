#include <bits/stdc++.h>

using i64 = long long;

#define pii std::pair<int,int>
#define ins(s, l, r) ((l)<=(r)?(s).emplace(l,r),0:1)
#define fdl(s, x) ((s).empty()||(s).begin()->first>=(x)?(s).end():--(s).lower_bound(pii{x,0}))
#define fdr(s, x) ((s).lower_bound(pii{(x)+1,0}))
#define fd(s, x) ((s).empty()||(s).begin()->first>(x)||(--(s).lower_bound(pii{(x)+1,0}))->second<(x)?(s).end():--(s).lower_bound(pii{(x)+1,0}))

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n), c(2e5 + 100);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		++c[a[i]];
	}
	for (int i = 0; i < 2e5 + 99; ++i) {
		c[i + 1] += c[i] / 2;
		c[i] %= 2;
	}
	std::set<pii > s;
	int fr = -1;
	for (int i = 0; i < 2e5 + 100; ++i) {
		if (c[i]) {
			if (fr == -1) fr = i;
		} else {
			if (fr != -1) ins(s, fr, i - 1), fr = -1;
		}
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		--x;
		auto it = fd(s, a[x]);
		if (it == s.end()) {
			auto itr = fdr(s, a[x]), itl = fdl(s, a[x]);
			int h = itr->first;
			ins(s, h + 1, itr->second);
			s.erase(itr);
			if (itl != s.end() && itl->second == a[x] - 1) ins(s, itl->first, h - 1), s.erase(itl);
			else { ins(s, a[x], h - 1); }
		} else {
			ins(s, it->first, a[x] - 1);
			ins(s, a[x] + 1, it->second);
			s.erase(it);
		}
		a[x] = y;
		it = fd(s, y);
		if (it == s.end()) {
			auto itr = fdr(s, a[x]), itl = fdl(s, a[x]);
			int l = y, r = y;
			if (itl != s.end() && itl->second == y - 1) l = itl->first, s.erase(itl);
			if (itr != s.end() && itr->first == y + 1) r = itr->second, s.erase(itr);
			ins(s, l, r);
		} else {
			ins(s, it->first, y - 1);
			y = it->second + 1;
			auto itr = fdr(s, y);
			if (itr != s.end() && itr->first == y + 1) ins(s, y, itr->second), s.erase(itr);
			else { ins(s, y, y); }
			s.erase(it);
		}
		std::cout << (--s.end())->second << '\n';
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
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}