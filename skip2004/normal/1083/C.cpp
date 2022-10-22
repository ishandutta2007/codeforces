#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++i)
using std::cin;
using std::cout;
const int maxn = 200200;
int n, q, p[maxn], ip[maxn];
int head[maxn], next[maxn];
inline void add(int fa, int x) {
	next[x] = head[fa], head[fa] = x;
}
int st[20][maxn], dfn[maxn], dep[maxn], tot;
inline int min(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
inline void dfs0(int x, int fa) {
	st[0][tot] = fa, dfn[x] = ++ tot, dep[x] = dep[fa] + 1;
	for(int i = head[x];i;i = next[i]) {
		dfs0(i, x);
	}
}
inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
struct list {
	int good, x, y;
};

inline int dis(int x, int y) {
	return dep[x] + dep[y] - dep[lca(x, y)] * 2;
}
inline int in(int x, int y, int z) {
	return dis(x, y) == dis(x, z) + dis(z, y);
}
inline list merge(const list & x, const list & y) {
	if(!x.good || !y.good)
		return (list) {0, 0, 0};
	int a[4] = {x.x, x.y, y.x, y.y};
	for(int i = 0;i < 4;++i) {
		for(int j = i + 1;j < 4;++j) {
			int yes = 1;
			for(int k = 0;k < 4;++k) {
				yes = yes && in(a[i], a[j], a[k]);
			}
			if(yes)
				return (list){1, a[i], a[j]};
		}
	}
	return (list) {0, 0, 0};
}

list tree[maxn << 2];
inline void update(int cur) {
	tree[cur] = merge(tree[cur << 1], tree[cur << 1 | 1]);
}
inline void build(int cur, int l, int r) {
	if(l == r) {
		tree[cur] = {1, ip[l], ip[l]};
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline void upt(int pos, int v, int cur = 1, int l = 1, int r = n) {
	if(l == r) {
		tree[cur] = {1, v, v};
		return ;
	}
	int mid = l + r >> 1;
	pos <= mid ? upt(pos, v, cur << 1, l, mid) : upt(pos, v, cur << 1 | 1, mid + 1, r);
	update(cur);
}
inline int test(int cur = 1, int l = 1, int r = n) {
	list x = {1, ip[1], ip[1]};
	for(;l != r;) {
		int mid = l + r >> 1;
		if(merge(tree[cur << 1], x).good) {
			x = merge(x, tree[cur << 1]);
			cur = cur << 1 | 1;
			l = mid + 1;
		} else {
			cur <<= 1;
			r = mid;
		}
	}
	x = merge(x, tree[cur]);
	return l - 1 + x.good;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> p[i], ++ p[i];
		ip[p[i]] = i;
	}
	for(int i = 2, f;i <= n;++i) {
		cin >> f;
		add(f, i);
	}
	dfs0(1, 0);
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 < n;++j) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	build(1, 1, n);
	cin >> q;
	for(int i = 1;i <= q;++i) {
		int t, x, y;
		cin >> t;
		if(t == 1) {
			cin >> x >> y;
			std::swap(ip[p[x]], ip[p[y]]);
			std::swap(p[x], p[y]);
			upt(p[x], x);
			upt(p[y], y);
		} else {
			cout << test() << '\n';
		}
	}
}