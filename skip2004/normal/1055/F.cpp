#include<bits/stdc++.h>
typedef unsigned long long u64, * ptr;
using std::cin;
using std::cout;
const int maxn = 1000100;
int n;
u64 k, val[maxn];
struct range {
	ptr l, r;
	u64 lv, rv;
	inline range() { }
	inline range(u64 a, u64 b) {
		lv = a, rv = b;
		l = std::lower_bound(val + 1, val + n + 1, a);
		r = std::lower_bound(val + 1, val + n + 1, b);
	}
	inline u64 len() const 
	{ return r - l; }
};
int tot = 0;
inline void init(range & a, range & b, const range & c) {
	u64 mid = c.lv + c.rv >> 1;
	a.r = b.l = std::lower_bound(a.l = c.l, b.r = c.r, mid);
	a.lv = c.lv, b.rv = c.rv, a.rv = b.lv = mid;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> k;
	for(int i = 2, f;i <= n;++i) {
		u64 w;
		cin >> f >> w;
		val[i] = val[f] ^ w;
	}
	std::vector<range> c(1 + n), d(1 + n), cl(1 + n), cr(1 + n), dl(1 + n), dr(1 + n);
	std::sort(val + 1, val + n + 1);
	tot = 1;
	c[tot] = d[tot] = range(0, 1ll << 62);
	u64 ans = 0;
	for(int i = 61;i >= 0;--i) {
		u64 su = 0;
		const int m = tot;
		for(int j = 1;j <= m;++j) {
			init(cl[j], cr[j], c[j]);
			init(dl[j], dr[j], d[j]);
			su += cl[j].len() * dl[j].len() + cr[j].len() * dr[j].len();
		}
		tot = 0;
		const auto ins = [&](const range& x, const range& y) {
			if(x.len() && y.len()) {
				c[++tot] = x, d[tot] = y;
			}
		};
		if(k <= su) {
			for(int i = 1;i <= m;++i) {
				ins(cl[i], dl[i]);
				ins(cr[i], dr[i]);
			}
		} else {
			for(int i = 1;i <= m;++i) {
				ins(cl[i], dr[i]);
				ins(cr[i], dl[i]);
			}
			ans |= 1ull << i;
			k -= su;
		}
	}
	cout << ans << '\n';
}