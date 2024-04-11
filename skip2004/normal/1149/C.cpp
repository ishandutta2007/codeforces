#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
struct bit {
	int a[maxn];
	inline void add(int x, int v) {
		for(;x < maxn;x += x & -x) {
			a[x] += v;
		}
	}
	inline int test(int x) {
		int o = 0;
		for(;x;x &= x - 1) {
			o += a[x];
		}
		return o;
	}
} d;
int min[maxn << 2], tag[maxn << 2];
int n, q, N;
int v[maxn];
char s[maxn];
inline void put(int cur, int v) {
	min[cur] += v;
	tag[cur] += v;
}
inline void add(int ql, int qr, int v, int cur = 1, int l = 1, int r = N) {
	if(ql <= l && r <= qr) return put(cur, v);
	int mid = l + r >> 1;
	if(ql <= mid) add(ql, qr, v, cur << 1, l, mid);
	if(mid < qr) add(ql, qr, v, cur << 1 | 1, mid + 1, r);
	min[cur] = std::min(min[cur << 1], min[cur << 1 | 1]) + tag[cur];
}
inline void down(int & x, int y) {
	if(x > y) {
		x = y;
	}
}
inline int qry(int ql, int qr, int cur = 1, int l = 1, int r = N) {
	if(ql <= l && r <= qr) return min[cur];
	int mid = l + r >> 1, ret = 1e9;
	if(ql <= mid) ret = qry(ql, qr, cur << 1, l, mid);
	if(mid < qr) down(ret, qry(ql, qr, cur << 1 | 1, mid + 1, r));
	return ret + tag[cur];
}
inline int dis(int x, int y) {
	return d.test(x) + d.test(y) - qry(x, y) * 2;
}
inline int lca(int x, int y) {
	return qry(x, y) * 2;
}
struct list {
	int a, b, d;
} tree[maxn << 2];
int D[maxn], T[maxn], now;
inline list merge(const list&x, const list&y) {
	static int a[4], b[4], c[3]; int tot = 0;
	x.a && (a[tot++] = x.a), x.b && (a[tot++] = x.b);
	y.a && (a[tot++] = y.a), y.b && (a[tot++] = y.b);
	for(int i = 0;i < tot;++i) {
		if(T[a[i]] == now) {
			b[i] = D[a[i]];
		} else {
			D[a[i]] = b[i] = d.test(a[i]);
			T[a[i]] = now;
		}
	}
	for(int i = 0;i + 1 < tot;++i) {
		if(a[i] == x.a && a[i + 1] == x.b) c[i] = b[i] + b[i + 1] - x.d;
		else if(a[i] == y.a && a[i + 1] == y.b) c[i] = b[i] + b[i + 1] - y.d;
		else c[i] = lca(a[i], a[i + 1]);
	}
	list ans = {a[0], a[0], 0}; int len = 0;
	for(int i = 0;i + 1 < tot;++i) for(int j = i + 1, min = c[i];j < tot;++j){ 
		int d = b[i] + b[j] - min;
		if(d > len) {
			len = d;
			ans = {a[i], a[j], d};
		}
		if(j + 1 < tot) down(min, c[j]);
	}
	return ans;
}
inline void upt(int pos, int cur = 1, int l = 1,int r = N) {
	if(l == r) return ;
	int mid = l + r >> 1;
	pos <= mid ? upt(pos, cur << 1, l, mid) : upt(pos, cur << 1 | 1, mid + 1, r);
	tree[cur] = merge(tree[cur << 1], tree[cur << 1 | 1]);
}
inline void build(int cur = 1,int l = 1,int r = N) {
	if(l == r) return void(tree[cur] = {l, l, 0});
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	tree[cur] = merge(tree[cur << 1], tree[cur << 1 | 1]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	std::mt19937 rd(time(0));
	cin >> n >> q >> s + 1, N = n - 1 << 1;
	for(int i = 1;i <= N;++i) {
		v[i] = s[i] == '(' ? 1 : -1;
		d.add(i, v[i]);
		add(i, N, v[i]);
	}
	now = -1;
	build();
	cout << dis(tree[1].a, tree[1].b) << '\n';
	rep(i, 1, q) {
		now = i;
		int x, y;
		cin >> x >> y;
		if(v[x] != v[y]) {
			d.add(x, -v[x] * 2);
			d.add(y, -v[y] * 2);
			add(x, N, -v[x] * 2);
			add(y, N, -v[y] * 2);
			upt(x);
			upt(y);
			std::swap(v[x], v[y]);
		}
		cout << dis(tree[1].a, tree[1].b) << '\n';
	}
}