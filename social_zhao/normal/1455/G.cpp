#include<bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, S = N * 30, L = 200000, inf = 0x3f3f3f3f3f3f3f3f;
int n, s, st[N], top;
char opt[10];
struct Node { int y, v; } t[N];
vector<int> adj[N];

int T[N], tag[S], lc[S], rc[S], mn[S], node;

void pushup(int u) {
	mn[u] = inf;
	if(lc[u]) mn[u] = min(mn[u], mn[lc[u]]);
	if(rc[u]) mn[u] = min(mn[u], mn[rc[u]]);
}

void pusht(int u, int v) { mn[u] += v, tag[u] += v; }

void pushdown(int u) {
	if(lc[u]) pusht(lc[u], tag[u]);
	if(rc[u]) pusht(rc[u], tag[u]);
	tag[u] = 0;
}

void modify(int &u, int l, int r, int x, int v) {
	if(!u) u = ++node;
	if(l == r) return mn[u] = v, void();
	pushdown(u);
	if(x <= mid) modify(lc[u], l, mid, x, v);
	else modify(rc[u], mid + 1, r, x, v);
	pushup(u);
}

int query(int u, int l, int r, int x) {
	if(!u) return inf;
	if(l == r) return mn[u];
	pushdown(u);
	if(x <= mid) return query(lc[u], l, mid, x);
	else return query(rc[u], mid + 1, r, x);
}

int merge(int u, int v, int l, int r) {
	if(!u || !v) return u + v;
	if(l != r) pushdown(u), pushdown(v), lc[u] = merge(lc[u], lc[v], l, mid), rc[u] = merge(rc[u], rc[v], mid + 1, r);
	mn[u] = min(mn[u], mn[v]);
	return u;
}

void dfs(int u) {
	modify(T[u], 0, L, t[u].y, 0);
	for(auto v : adj[u]) {
		if(t[v].v > 0) { // set
			if(t[v].y == s) pusht(T[u], t[v].v);
			else {
				int p = mn[T[u]];
				pusht(T[u], t[v].v), modify(T[u], 0, L, t[v].y, p);
			}
		}
		else { // if
			int val = query(T[u], 0, L, t[v].y);
			if(val == inf) continue;
			dfs(v);
			pusht(T[v], val), modify(T[u], 0, L, t[v].y, inf), T[u] = merge(T[u], T[v], 0, L);
		}
	}
}

main() {
	n = get(), s = get();
	st[++top] = 0, t[0].y = 0, t[0].v = -1;
	for(int i = 1; i <= n; i++) {
		scanf("%s", opt + 1);
		if(opt[1] == 's') {
			t[i].y = get(), t[i].v = get();
			adj[st[top]].push_back(i);
		}
		else if(opt[1] == 'i') {
			t[i].y = get(), t[i].v = -1;
			adj[st[top]].push_back(i), st[++top] = i;
		}
		else if(opt[1] == 'e') st[top--] = 0;
	}
	dfs(0);
	printf("%lld\n", mn[T[0]]);
	return 0;
}