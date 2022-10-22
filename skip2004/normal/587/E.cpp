#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int M = 30;
const int N = 200200;
struct base {
	int a[M];
	inline void ins(int x) {
		for(int i = M - 1;i >= 0;--i)
			if(x >> i & 1) {
				if(a[i]) x ^= a[i];
				else return void(a[i] = x);
			}
	}
	inline int count() {
		return M - std::count(a, a + M, 0);
	}
};
inline base merge(base x, const base & y) {
	for(int i = 0;i < M;++i) if(y.a[i]) x.ins(y.a[i]);
	return x;
}
int n, q;
int a[N], b[N];
base seg[N << 2], EP;
inline void update(int cur) {
	seg[cur] = merge(seg[cur << 1], seg[cur << 1 | 1]);
}
inline void build(int cur, int l, int r) {
	if(l == r) {
		seg[cur].ins(b[l]);
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline void upt(int pos, int v, int cur = 1, int l = 1, int r = n) {
	if(l == r) {
		(seg[cur] = EP).ins(v);
		return ;
	}
	int mid = l + r >> 1;
	pos <= mid ? upt(pos, v, cur << 1, l, mid) : upt(pos, v, cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline base ask(int ql, int qr, int cur = 1, int l = 1, int r = n) {
	if(ql <= l && r <= qr) return seg[cur];
	int mid = l + r >> 1;
	base A = EP;
	if(ql <= mid) A = merge(ask(ql, qr, cur << 1, l, mid), A);
	if(mid < qr) A = merge(ask(ql, qr, cur << 1 | 1, mid + 1, r), A);
	return A;
}
int bit[N];
inline void add(int x, int v) {
	for(;x < N;x += x & - x) bit[x] ^= v;
}
inline int ask(int x) {
	int res = 0;
	for(;x;x &= x - 1) res ^= bit[x];
	return res;
}
inline void mdf(int pos, int v) {
	if(pos <= n) b[pos] ^= v, add(pos, v), upt(pos, b[pos]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	rep(i, 1, n) cin >> a[i], b[i] = a[i] ^ a[i - 1], add(i, b[i]);
	build(1, 1, n);
	rep(i, 1, q) {
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1) {
			int v;
			cin >> v;
			mdf(l, v), mdf(r + 1, v);
		} else {
			base A = l == r ? EP : ask(l + 1, r);
			A.ins(ask(l));
			cout << (1 << A.count()) << '\n';
		}
	}
}