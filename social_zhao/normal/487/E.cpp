#include<bits/stdc++.h>
#define pii pair<int, int> 
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m, _, w[N], node;
struct Edge { int v, nxt; } edge[N];
int head[N], tot;
vector<int> adj[N];
int low[N], dfn[N], tim, st[N], tp;
int sze[N], son[N], seg[N], rev[N], top[N], dep[N], fa[N];
struct Heap {
	priority_queue<int, vector<int>, greater<int> > p, q;
	
	void maintain() { while(!q.empty() && p.top() == q.top()) p.pop(), q.pop(); }
	void push(int x) { maintain(), p.push(x); }
	void pop(int x) { maintain(), q.push(x); }
	int top() { maintain(); return p.top(); }
} q[N];

void add(int u, int v) { edge[++tot] = { v, head[u] }, head[u] = tot; }

void tarjan(int u) {
	low[u] = dfn[u] = ++tim, st[++tp] = u;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(!dfn[v]) {
			tarjan(v), low[u] = min(low[u], low[v]);
			if(low[v] == dfn[u]) {
				++node;
				for(int x = 0; x != v; tp--)
					x = st[tp], adj[x].push_back(node), adj[node].push_back(x);
				adj[u].push_back(node), adj[node].push_back(u);
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

#define v adj[u][i]
void dfs(int u, int lst) {
	dep[u] = dep[lst] + 1, sze[u] = 1, fa[u] = lst;
	for(int i = 0; i < adj[u].size(); i++) if(v != lst) dfs(v, u), sze[u] += sze[v], son[u] = sze[v] > sze[son[u]]? v : son[u];
}

void df5(int u, int lst) {
	seg[++seg[0]] = u, rev[u] = seg[0], top[u]= lst;
	if(son[u]) df5(son[u], lst);
	for(int i = 0; i < adj[u].size(); i++) if(!top[v]) df5(v, v);
}
#undef v

namespace SegmentTree {
	#define lc (u << 1)
	#define rc (u << 1 | 1)
	int mx[N << 2];
	void pushup(int u) { mx[u] = min(mx[lc], mx[rc]); }
	void build(int u, int l, int r) {
		mx[u] = 0x3f3f3f3f;
		if(l == r) return;
		int mid = (l + r) >> 1;
		build(lc, l, mid), build(rc, mid + 1, r);
	}
	void update(int u, int l, int r, int x, int v) {
		if(l == r) return void(mx[u] = v);
		int mid = (l + r) >> 1;
		if(x <= mid) update(lc, l, mid, x, v);
		else update(rc, mid + 1, r, x, v);
		pushup(u);
	}
	int query(int u, int l, int r, int a, int b) {
		if(a == l && r == b) return mx[u];
		int mid = (l + r) >> 1;
		if(b <= mid) return query(lc, l, mid, a, b);
		else if(a > mid) return query(rc, mid + 1, r, a, b);
		else return min(query(lc, l, mid, a, mid), query(rc, mid + 1, r, mid + 1, b));
	}
}

int query(int x, int y) {
	int res = 0x3f3f3f3f;
	while(top[x] ^ top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		res = min(res, SegmentTree::query(1, 1, seg[0], rev[top[x]], rev[x])), x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	res = min(res, SegmentTree::query(1, 1, seg[0], rev[x], rev[y]));
	if(x > n) res = min(res, w[fa[x]]);
	return res;
}

void update(int x, int y) {
	if(fa[x]) q[fa[x]].pop(w[x]);
	w[x] = y;
	if(fa[x]) q[fa[x]].push(w[x]);
	SegmentTree::update(1, 1, seg[0], rev[x], w[x]);
	if(fa[x]) SegmentTree::update(1, 1, seg[0], rev[fa[x]], q[fa[x]].top());
}

int main() {
	n = get(), m = get(), _ = get(), node = n;
	for(int i = 1; i <= n; i++) w[i] = get();
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), add(u, v), add(v, u);
	tarjan(1);
	dfs(1, 0), df5(1, 1), SegmentTree::build(1, 1, seg[0]);
	for(int i = 1; i <= n; i++) if(fa[i] > n) q[fa[i]].push(w[i]);
	for(int i = 1; i <= node; i++) SegmentTree::update(1, 1, seg[0], rev[i], (i <= n)? w[i] : q[i].top());
	for(int i = 1; i <= _; i++) {
		char opt; scanf("%s", &opt); int x = get(), y = get();
		if(opt == 'A') printf("%d\n", query(x, y));
		if(opt == 'C') update(x, y);
	}
	return 0;
}