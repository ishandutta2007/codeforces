#include<bits/stdc++.h>
#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, q;
struct Edge {
	int v, nxt;
} edge[N];
int head[N], k = 1;
int dep[N], sze[N], fa[N], son[N], seg[N], rev[N], top[N];
int sum[N << 2], L[N << 2], R[N << 2], add[N << 2], rt, val[N];

void pushup(int u) {
	sum[u] = sum[lc] + sum[rc];
}

void pushdown(int u) {
	if(!add[u]) return;
	add[lc] += add[u], add[rc] += add[u];
	sum[lc] += add[u] * (R[lc] - L[lc] + 1);
	sum[rc] += add[u] * (R[rc] - L[rc] + 1);
	add[u] = 0;
}

void build(int u, int l, int r) {
	L[u] = l, R[u] = r;
	if(l == r) { sum[u] = val[seg[l]]; return; }
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int a, int b, int v) {
	if(a == l && r == b) {
		sum[u] += (r - l + 1) * v, add[u] += v;
		return;
	}
	pushdown(u);
	if(b <= mid) update(lc, l, mid, a, b, v);
	else if(a > mid) update(rc, mid + 1, r, a, b, v);
	else update(lc, l, mid, a, mid, v), update(rc, mid + 1, r, mid + 1, b, v);
	pushup(u);
}

int query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return sum[u];
	pushdown(u);
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return query(lc, l, mid, a, mid) + query(rc, mid + 1, r, mid + 1, b);
}

void addedge(int u, int v) {
	edge[++k].nxt = head[u];
	edge[k].v = v;
	head[u] = k;
}

void insedge(int u, int v) {
	addedge(u, v), addedge(v, u);
}

void dfs(int u, int fath) {
	dep[u] = dep[fath] + 1, sze[u] = 1, fa[u] = fath;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fath) continue;
		dfs(v, u);
		sze[u] += sze[v];
		if(sze[v] > sze[son[u]]) son[u] = v;
	}
}

void df5(int u, int fath) {
	if(son[u]) 
		seg[++seg[0]] = son[u], rev[son[u]] = seg[0], top[son[u]] = top[u], df5(son[u], u);
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(top[v]) continue;
		seg[++seg[0]] = v, rev[v] = seg[0], top[v] = v, df5(v, u);
	}
}

int real_lca(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	return x;
}

int lca(int x, int y) {
	int l1 = real_lca(x, rt), l2 = real_lca(y, rt), l3 = real_lca(x, y);
	if(dep[l1] >= dep[l2] && dep[l1] >= dep[l3]) return l1;
	if(dep[l2] >= dep[l1] && dep[l2] >= dep[l3]) return l2;
	else return l3;
}

int jump(int x, int y) {
	while(top[x] != top[y] && fa[top[x]] != y) x = fa[top[x]];
	if(top[x] == top[y]) return seg[rev[y] + 1];
	else if(fa[top[x]] == y) return top[x];
}

void AddSubtree(int x, int v) {
	if(real_lca(x, rt) != x || rt == 1) { update(1, 1, seg[0], rev[x], rev[x] + sze[x] - 1, v); return; }
	else if(rt == x) { update(1, 1, seg[0], 1, seg[0], v); return; }
	int y = jump(rt, x);
	update(1, 1, seg[0], 1, seg[0], v), update(1, 1, seg[0], rev[y], rev[y] + sze[y] - 1, -v);
}

int QuerySubtree(int x) {
	if(real_lca(x, rt) != x || rt == 1) return query(1, 1, seg[0], rev[x], rev[x] + sze[x] - 1);
	else if(rt == x) return query(1, 1, seg[0], 1, seg[0]);
	int y = jump(rt, x);
	return query(1, 1, seg[0], 1, seg[0]) - query(1, 1, seg[0], rev[y], rev[y] + sze[y] - 1);
}

signed main() {
	n = get(), q = get();
	for(int i = 1; i <= n; i++) val[i] = get();
	for(int i = 1; i < n; i++) insedge(get(), get());
	dfs(rt = 1, 0);
	seg[1] = seg[0] = rev[1] = top[1] = 1;
	df5(1, 0);
	build(1, 1, seg[0]);
	while(q--) {
		int opt = get(), x, y, z;
		switch(opt) {
			case 1: x = get(), rt = x; break;
			case 2: x = get(), y = get(), z = get(), AddSubtree(lca(x, y), z); break;
			case 3: x = get(), printf("%lld\n", QuerySubtree(x)); break;
		}
	}
	return 0;
}