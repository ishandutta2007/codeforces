#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 100005;
const int lg = 18;
int n, q, a[N];
using pr = std::pair<int, int>;
inline pr un(const pr & x, const pr & y) {
	return pr(std::min(x.first, y.first), std::max(x.second, y.second));
}
struct PB {
	pr a[N];
	pr st[lg][N];
	inline pr qry(int l, int r) {
		const int lg = std::__lg(r - l);
		return un(st[lg][l], st[lg][r - (1 << lg)]);
	}
	inline void init() {
		for(int i = 1;i < n;++i) st[0][i] = a[i];
		for(int i = 1;i < lg;++i) {
			for(int j = 1;j < n;++j) {
				st[i][j] = un(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
} pb[lg * 2];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	for(int i = 1;i < n;++i)
		pb[0].a[i] = std::minmax(a[i], a[i + 1]);
	pb[0].init();
	for(int i = 1;i < lg * 2;++i) {
		for(int j = 1;j < n;++j) {
			pb[i].a[j] = pb[i - 1].qry(pb[i - 1].a[j].first, pb[i - 1].a[j].second);
		}
		pb[i].init();
	}
	using ll = long long;
	for(int i = 1, l, r;i <= q;++i) {
		cin >> l >> r;
		if(l == 1 && r == n) {
			cout << 0 << '\n';
			continue;
		}
		if(l == r) {
			cout << (n == 1 ? 0 : -1) << '\n';
			continue;
		}
		pr s(l, r);
		ll res = 0;
		for(int i = lg * 2 - 1;i >= 0;--i) {
			pr t = pb[i].qry(s.first, s.second);
			if(t != pr(1, n)) {
				s = t;
				res += 1ll << i;
			}
		}
		res += s != pr(1, n);
		if(res <= n * n) {
			cout << res << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}