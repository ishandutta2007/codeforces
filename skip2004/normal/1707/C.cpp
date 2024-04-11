// 
#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 200005;
int n, m;
int u[N], v[N];
int anc[N];
inline int find(int x) {
	return anc[x] == x ? x : anc[x] = find(anc[x]);
}
struct edge {
	int to, nxt;
} e[N << 1];
int h[N], num;
inline void link(int x, int y) {
	e[++num] = {y, h[x]}, h[x] = num;
	e[++num] = {x, h[y]}, h[y] = num;
}
int st[20][N], dfn[N], tot;
inline int min(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]);
}
int size[N];
int jump[20][N];
inline void dfs0(int x, int fa = 0) {
	st[0][tot] = fa, dfn[x] = ++ tot;
	size[x] = 1;
	jump[0][x] = fa;
	for(int i = 1;i < 20;++i) jump[i][x] = jump[i - 1][jump[i - 1][x]];
	for(int i = h[x];i;i = e[i].nxt) if(e[i].to != fa) {
		dfs0(e[i].to, x);
		size[x] += size[e[i].to];
	}
}
int ok[N];
inline void add(int l, int r, int v) {
	ok[l] += v, ok[r] -= v;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) anc[i] = i;
	std::vector<std::pair<int, int>> e;
	for(int i = 1;i <= m;++i) {
		cin >> u[i] >> v[i];
		if(find(u[i]) != find(v[i])) {
			anc[find(u[i])] = find(v[i]);
			link(u[i], v[i]);
		} else {
			e.emplace_back(u[i], v[i]);
		}
	}
	dfs0(1);
	for(int i = 1;i < 20;++i)
		for(int j = 1;j + (1 << i) - 1 < n;++j) 
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	for(auto [x, y] : e) {
		int l = lca(x, y);
		if(dfn[x] > dfn[y]) std::swap(x, y);
		if(l == x) {
			add(1, n + 1, 1);
			add(dfn[y], dfn[y] + size[y], 1);
			for(int i = 19;i >= 0;--i) if(dfn[jump[i][y]] > dfn[x]) y = jump[i][y];
			add(dfn[y], dfn[y] + size[y], -1);
		} else {
			add(dfn[x], dfn[x] + size[x], 1);
			add(dfn[y], dfn[y] + size[y], 1);
		}
	}
	for(int i = 1;i <= n;++i) ok[i] += ok[i - 1];
	for(int i = 1;i <= n;++i) {
		cout << (ok[dfn[i]] == e.size());
	}
}