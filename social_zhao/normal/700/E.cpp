#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5, S = N * 60;
int n, ans = 1;
char s[N];
struct State { int ch[26], len, fa; } st[N];
int lst = 1, tot = 1, T[N], bin[N], top, f[N], g[N], mx[N];
vector<int> adj[N];

namespace SGT {
	#define mid ((l + r) >> 1)
	int lc[S], rc[S], sze[S], tot;
	
	void update(int &u, int l, int r, int x) {
		if(!u) u = ++tot;
		sze[u]++;
		if(l == r) return;
		if(x <= mid) update(lc[u], l, mid, x);
		else update(rc[u], mid + 1, r, x);
	}
	
	int merge(int u, int v, int l, int r) {
		if(!u || !v) return u + v;
		int now = ++tot; sze[now] = sze[u] + sze[v];
		if(l == r) return now;
		lc[now] = merge(lc[u], lc[v], l, mid), rc[now] = merge(rc[u], rc[v], mid + 1, r);
		return now;
	}
	
	int query(int u, int l, int r, int a, int b) {
		if(a > b || !u) return 0;
		if(a == l && r == b) return sze[u];
		if(b <= mid) return query(lc[u], l, mid, a, b);
		else if(a > mid) return query(rc[u], mid + 1, r, a, b);
		else return query(lc[u], l, mid, a, mid) + query(rc[u], mid + 1, r, mid + 1, b);
	}
}

void insert(int c) {
	int p = lst, np = lst = ++tot;
	st[np].len = st[p].len + 1, SGT::update(T[np], 1, n, mx[np] = st[np].len);
	while(p && !st[p].ch[c]) st[p].ch[c] = np, p = st[p].fa;
	if(!p) st[np].fa = 1;
	else {
		int q = st[p].ch[c];
		if(st[q].len == st[p].len + 1) st[np].fa = q;
		else {
			int nq = ++tot;
			st[nq] = st[q], st[nq].len = st[p].len + 1, st[q].fa = st[np].fa = nq;
			while(p && st[p].ch[c] == q) st[p].ch[c] = nq, p = st[p].fa;
		}
	}
}

void dfs(int u) {
	bin[++top] = u;
	for(auto v : adj[u]) 
		dfs(v), T[u] = SGT::merge(T[u], T[v], 1, n), mx[u] = max(mx[u], mx[v]);
}

int main() {
	n = get();
	scanf("%s", s + 1);
	
	for(int i = 1; i <= n; i++) insert(s[i] - 'a');
	for(int i = 2; i <= tot; i++) adj[st[i].fa].emplace_back(i);
	dfs(1);
	
	for(int t = 1; t <= top; t++) {		int u = bin[t];
		if(u == 1) continue;
		f[u] = 1, g[u] = u;
		if(st[u].fa == 1) continue;
		int lst = g[st[u].fa];
		if(SGT::query(T[lst], 1, n, mx[u] - st[u].len + st[st[lst].fa].len + 1, mx[u] - 1))
			f[u] = f[lst] + 1, g[u] = u;
		else f[u] = f[lst], g[u] = lst;
		ans = max(ans, f[u]);
	}
	
	cout << ans << endl;
	return 0;
}