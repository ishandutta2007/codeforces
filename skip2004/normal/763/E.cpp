#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 600200;
typedef long long ll;
const int mod = 998244353;
int bit[maxn];
inline void add(int x, int v) {
	for(;x;x &= x - 1) {
		bit[x] += v;
	}
}
inline int ask(int x) {
	int o = 0;
	for(;x < maxn;x += x & - x) {
		o += bit[x];
	}
	return o;
}
int son[maxn][2], fa[maxn], min[maxn], val[maxn], tag[maxn];
int tot, u[maxn], v[maxn];
inline int get(int x, int p = 1){ return son[fa[x]][p] == x; }
inline int is_root(int x){ return !(get(x) || get(x, 0)); }
inline void put(int x) {
	std::swap(son[x][0], son[x][1]);
	tag[x] ^= 1;
}
inline void down(int x) {
	if(tag[x]) {
		put(son[x][0]);
		put(son[x][1]);
		tag[x] = 0;
	}
}
inline void pushdown(int x) {
	if(!is_root(x)) {
		pushdown(fa[x]);
	}
	down(x);
}
inline void up(int x) {
	min[x] = x;
	if(son[x][0] && val[min[son[x][0]]] < val[min[x]]) min[x] = min[son[x][0]];
	if(son[x][1] && val[min[son[x][1]]] < val[min[x]]) min[x] = min[son[x][1]];
}
inline void rotate(int x) {
	int y = fa[x], z = fa[y], b = get(x);
	if(!is_root(y)) son[z][get(y)] = x;
	son[y][b] = son[x][!b], son[x][!b] = y;
	fa[son[y][b]] = y, fa[y] = x, fa[x] = z;
	up(y);
}
inline void splay(int x) {
	for(pushdown(x);!is_root(x);rotate(x)) if(!is_root(fa[x]))
		rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
	up(x);
}
inline void access(int x) {
	for(int t = 0;x;son[x][1] = t, t = x, x = fa[x])
		splay(x);
}
inline void make_root(int x) {
	access(x), splay(x), put(x);
}
inline void split(int x, int y) {
	make_root(x), access(y), splay(y);
}
inline bool con(int x, int y) {
	split(x, y);
	for(;son[y][0];)
		down(y = son[y][0]);
	splay(y);
	return x == y;
}
inline void cut(int x, int y) {
	split(x, y);
	son[y][0] = fa[x] = 0;
	up(y);
}
inline void link(int x, int y, int v) {
	if(con(x, y)) {
		int e = min[x];
		if(val[e] >= v) return ;
		cut(e, u[e]);
		cut(e, ::v[e]);
		add(val[e], -1);
	}
	make_root(x);
	make_root(y);
	u[++tot] = x;
	::v[tot] = y;
	val[tot] = v;
	add(v, 1);
	up(tot);
	fa[x] = fa[y] = tot;
}
int n, k, m, q;
std::vector<int> edge[maxn];
std::vector<std::pair<int, int>> Q[maxn];
int ans[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k >> m, tot = n;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if(u > v) {
			std::swap(u, v);
		}
		edge[v].emplace_back(u);
	}
	rep(i, 1, n) {
		val[i] = 1e9;
		up(i);
	}
	cin >> q;
	rep(i, 1, q) {
		int l, r;
		cin >> l >> r;
		ans[i] = r - l + 1;
		Q[r].emplace_back(i, l);
	}
	rep(i, 1, n) {
		for(int x : edge[i]) {
			link(x, i, x);
		}
		for(std::pair<int, int> x : Q[i]) {
			ans[x.first] -= ask(x.second);
		}
	}
	rep(i, 1, q) {
		cout << ans[i] << '\n';
	}
}