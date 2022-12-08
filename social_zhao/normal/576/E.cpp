#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, m, q, k, _x[N], _y[N];
int pre[N], nxt[N], _e[N], _c[N], col[N], toc[N], lst[N];
struct DSU {
	int fa[N << 1], sze[N << 1];
	struct Operate { int x, lst, tim; };
	stack<Operate> s;
	void init(int n) {
		for(int i = 1; i <= n; i++) fa[i] = i, sze[i] = 1;
	}
	int find(int x) { return x == fa[x]? x : find(fa[x]); }
	void merge(int x, int y, int tim) {
		int u = find(x), v = find(y);
		if(u == v) return;
		if(sze[u] < sze[v]) swap(u, v);
		s.push((Operate){ v, fa[v], tim }), fa[v] = u, sze[fa[v]] += sze[v];
	}
	void undo(int x, int lst) {
		sze[fa[x]] -= sze[x], fa[x] = lst;
	}
	void undo(int tim) {
		while(s.size() && s.top().tim == tim) undo(s.top().x, s.top().lst), s.pop();
	}
} dsu[55];

struct Query {
	int e, id;
};
vector<Query> t[N << 2];

#define lc (u << 1)
#define rc (u << 1 | 1)

void update(int u, int l, int r, int a, int b, Query v) {
	if(a == l && r == b) return t[u].push_back(v), void();
	int mid = (l + r) >> 1;
	if(b <= mid) update(lc, l, mid, a, b, v);
	else if(a > mid) update(rc, mid + 1, r, a, b, v);
	else update(lc, l, mid, a, mid, v), update(rc, mid + 1, r, mid + 1, b, v);
}

void dfs(int u, int l, int r) {
	for(int i = 0; i < t[u].size(); i++) {
		int e = t[u][i].e, c = col[t[u][i].id];
		if(c) dsu[c].merge(_x[e], _y[e] + n, u), dsu[c].merge(_x[e] + n, _y[e], u);
	}
	if(l == r) {
		int e = _e[l], c = _c[l];
		if(dsu[c].find(_x[e]) == dsu[c].find(_y[e])) printf("NO\n"), c = col[pre[l]];
		else printf("YES\n");
		col[l] = c;
	}
	else {
		int mid = (l + r) >> 1;
		dfs(lc, l, mid), dfs(rc, mid + 1, r);
	}
	for(int i = 1; i <= k; i++) dsu[i].undo(u);
}

int main() {
	n = get(), m = get(), k = get(), q = get();
	for(int i = 1; i <= m; i++) _x[i] = get(), _y[i] = get();
	for(int i = 1; i <= k; i++) dsu[i].init(n * 2);

	for(int i = 1; i <= q; i++) nxt[i] = q + 1;
	for(int i = 1; i <= q; i++) {
		_e[i] = get(), _c[i] = get();
		if(lst[_e[i]]) nxt[lst[_e[i]]] = i;
		pre[i] = lst[_e[i]], lst[_e[i]] = i;
	}
	for(int i = 1; i <= q; i++) {
		if(i + 1 <= nxt[i] - 1) update(1, 1, q, i + 1, nxt[i] - 1, (Query){ _e[i], i });
	}
	dfs(1, 1, q);
	return 0;
}