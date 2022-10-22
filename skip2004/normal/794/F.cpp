#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
const int L = 1 << 17;

struct ints { ll a[10]; };
const ints E = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, zr = {};

int a[maxn], n, q;
ints tag[maxn << 2], sum[maxn << 2];
inline ll ask(const ints & x) {
	ll ret = 0;
	for(int i = 0;i < 10;++i) ret += x.a[i] * i;
	return ret;
}

inline void add(ints & x, const ints & y) { for(int i = 0;i < 10;++i) x.a[i] += y.a[i]; }
inline void update(int cur) { add(sum[cur] = sum[cur << 1], sum[cur << 1 | 1]); }
inline void put(int cur, const ints& t) {
	static ints x; x = zr;
	for(int i = 0;i < 10;++i) {
		x.a[t.a[i]] += sum[cur].a[i];
		tag[cur].a[i] = t.a[tag[cur].a[i]];
	}
	sum[cur] = x;
}
inline void pushdown(int cur) {
	put(cur << 1, tag[cur]);
	put(cur << 1 | 1, tag[cur]);
	tag[cur] = E;
}
inline void upt(int ql, int qr, const ints & v, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return put(cur, v);
	int mid = l + r >> 1; pushdown(cur);
	if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline ll ask(int ql, int qr, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return ask(sum[cur]);
	int mid = l + r >> 1; ll ans = 0; pushdown(cur);
	if(ql <= mid) ans += ask(ql, qr, cur << 1, l, mid);
	if(mid < qr) ans += ask(ql, qr, cur << 1 | 1, mid + 1, r);
	return ans;
}
inline void build(int cur, int l, int r) {
	tag[cur] = E;
	if(l == r) {
		for(int x = a[l], v = 1;x;x /= 10) {
			sum[cur].a[x % 10] += v;
			v *= 10;
		}
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	update(cur);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	for(int i = 0, opt, l, r, x, y;i < q;++i) {
		cin >> opt >> l >> r;
		if(opt == 1) {
			ints tag = E;
			cin >> x >> y;
			tag.a[x] = y;
			upt(l, r, tag);
		} else {
			cout << ask(l, r) << '\n';
		}
	}
}