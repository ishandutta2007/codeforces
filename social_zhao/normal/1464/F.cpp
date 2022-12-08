#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, q;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int dep[N], f[N][20];
int fa[N], top[N], dfn[N], rev[N], sze[N], son[N], tim;
int active, tag[N];
multiset<pair<int, int>> nw;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int lst) {
	fa[u] = lst, dep[u] = dep[lst] + 1, sze[u] = 1, f[u][0] = lst;
	for(int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u), sze[u] += sze[v], son[u] = sze[v] > sze[son[u]]? v : son[u];
	}
}

void df5(int u, int lst) {
	top[u] = u, dfn[u] = ++tim, rev[tim] = u;
	if(son[u]) df5(son[u], lst);
	for(int i = head[u]; i; i = edge[i].nxt) if(!top[edge[i].v]) df5(edge[i].v, edge[i].v);
}

int GetLCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int GetLA(int x, int y) {
	if(dep[x] <= y) return 1;
	for(int i = 19; i >= 0; i--) if(y >> i & 1) x = f[x][i];
	return x;
}

int GetDis(int x, int y) { return dep[x] + dep[y] - 2 * dep[GetLCA(x, y)]; }

struct Node {
	int x, y, d;
	Node() { x = y = 0, d = -1; }
	Node(int a) { x = y = a, d = 0; }
	Node(int a, int b, int c) { x = a, y = b, d = c; }
	bool operator <(Node b) const { return d < b.d; }
	Node operator +(Node b) {
		Node res = max(*this, b);
		if(x && b.x) res = max(res, Node(x, b.x, GetDis(x, b.x)));
		if(x && b.y) res = max(res, Node(x, b.y, GetDis(x, b.y)));
		if(y && b.x) res = max(res, Node(y, b.x, GetDis(y, b.x)));
		if(y && b.y) res = max(res, Node(y, b.y, GetDis(y, b.y)));
		return res;
	}
} t[N << 2];

#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)

void pushup(int u) { t[u] = t[lc] + t[rc]; }

void update(int u, int l, int r, int x, int type) {
	if(l == r) return t[u] = (type? Node(rev[l]) : Node()), void();
	if(x <= mid) update(lc, l, mid, x, type);
	else update(rc, mid + 1, r, x, type);
	pushup(u);
}

Node queryMax(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return t[u];
	if(b <= mid) return queryMax(lc, l, mid, a, b);
	else if(a > mid) return queryMax(rc, mid + 1, r, a, b);
	else return queryMax(lc, l, mid, a, mid) + queryMax(rc, mid + 1, r, mid + 1, b);
}

int sum[N];
int lowbit(int x) { return x & (-x); }
void add(int u, int l, int r, int x, int v) { while(x <= n) sum[x] += v, x += lowbit(x); }
int querySum(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
int querySum(int u, int a, int b, int l, int r) { return querySum(r) - querySum(l - 1); }

void insert(int x, int y) {
	int lca = GetLCA(x, y);
	add(1, 1, n, dfn[x], 1), add(1, 1, n, dfn[y], 1), add(1, 1, n, dfn[lca], -1);
	if(!tag[lca]) update(1, 1, n, dfn[lca], 1);
	++tag[lca], ++active, nw.insert({ dep[lca], lca });
}

void erase(int x, int y) {
	int lca = GetLCA(x, y);
	add(1, 1, n, dfn[x], -1), add(1, 1, n, dfn[y], -1), add(1, 1, n, dfn[lca], 1);
	--tag[lca], --active, nw.erase(nw.find({ dep[lca], lca }));
	if(!tag[lca]) update(1, 1, n, dfn[lca], 0);
}

int ask(int d) {
	int imp = nw.rbegin() -> second;
	int y = GetLA(imp, d), x = GetLA(y, d);
	if(querySum(1, 1, n, dfn[x], dfn[x] + sze[x] - 1) != active) return 0;
	Node res = queryMax(1, 1, n, dfn[x], dfn[x] + sze[x] - 1);
	if(res.x && GetDis(y, res.x) > d) return 0;
	if(res.y && GetDis(y, res.y) > d) return 0;
	return 1;
}

int main() {
	n = get(), q = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0), df5(1, 1);
	for(int t = 1; t <= q; t++) {
		int op = get();
		if(op == 1) {
			int x = get(), y = get();
			insert(x, y);
		}
		else if(op == 2) {
			int x = get(), y = get();
			erase(x, y);
		}
		else {
			int x = get(), res = ask(x);
			if(res) printf("Yes\n");
			else printf("No\n"); 
		}
	}
	return 0;
}

/*
10 6
1 2
2 3
3 4
4 7
7 10
2 5
5 6
6 8
8 9
1 9 9
1 9 8
1 8 5
3 1
*/