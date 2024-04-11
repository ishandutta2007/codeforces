#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 20200;
typedef long long ll;
const int mod = 998244353;
struct T {
	int to, nxt; char c;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y, char c) {
	way[++num] = {y, h[x], c}, h[x] = num;
	way[++num] = {x, h[y], c}, h[y] = num;
}
int n, q;
int st[20][maxn], dep[maxn], dfn[maxn], size[maxn], tot;
int fa[maxn]; char fc[maxn];
inline int min(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
inline void dfs0(int x, int fa = 0) {
	st[0][tot] = fa;
	dfn[x] = ++tot;
	dep[x] = dep[fa] + 1;
	::fa[x] = fa;
	size[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		fc[way[i].to] = way[i].c;
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
	}
}
inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
char s[maxn];
int len;
inline void select(int u, int v) {
	int l = lca(u, v), d = dep[u] + dep[v] - dep[l] * 2;
	len = 0;
	for(;u != l;) s[++len] = fc[u], u = fa[u];
	len = d;
	for(;v != l;) s[d] = fc[v], -- d, v = fa[v];
}
namespace _ {
	int head[maxn], next[maxn]; char c[maxn];
	inline void add(int fa, int x, int v) {
		next[x] = head[fa], head[fa] = x, c[x] = v;
	}
	int ans;
	inline void dfs0(int x, int d, int fa) {
#define go\
		if(v <= s[d]) { \
			if(v < s[d]) { \
				ans += dep[x] > dep[i] ? n - size[x] : size[i]; \
			} else { \
				if(d != len) { \
					++ ans; \
					dfs0(i, d + 1, x); \
				} \
			} \
		}
		for(int i = head[x];i;i = next[i]) if(i != fa) {
			const int v = c[i];
			go;
		}
		if(x != 1 && ::fa[x] != fa) {
			const int i = ::fa[x], v = fc[x];
			go;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep(i, 2, n) {
		int x, y; char c;
		cin >> x >> y >> c;
		link(x, y, c);
	}
	dfs0(1);
	rep(i, 2, n) _::add(fa[i], i, fc[i]);
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 < n;++j) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	rep(i, 1, q) {
		int x, y;
		cin >> x >> y;
		_::ans = 0;
		select(x, y);
		_::dfs0(x, 1, 0);
		cout << _::ans << '\n';
	}
}