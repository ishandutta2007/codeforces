#include<bits/stdc++.h>
#define int long long
#define lc c[x][0]
#define rc c[x][1] 
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
int n, m, col[N], ans[N], ins[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
vector< pair<int, int> > q[N];
int c[N][2], f[N], s[N], si[N], s2i[N], lst[N];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
void dfs(int u, int fa) { lst[u] = fa; for(int i = head[u]; i; i = edge[i].nxt) if(edge[i].v != fa) dfs(edge[i].v, u); }
int chk(int x) { return c[f[x]][1] == x; }
int nroot(int x) { return c[f[x]][chk(x)] == x; }
void pushup(int x) { s[x] = s[lc] + s[rc] + si[x] + 1; }
void rotate(int x) {
	int y = f[x], z = f[y], k = chk(x), w = c[x][!k];
	if(nroot(y)) c[z][chk(y)] = x; c[x][!k] = y, c[y][k] = w;
	if(w) f[w] = y; f[y] = x, f[x] = z;
	pushup(y), pushup(x);
}
void splay(int x) {
	while(nroot(x)) {
		int y = f[x];
		if(nroot(y)) rotate(chk(x) ^ chk(y)? x : y);
		rotate(x);
	}
}
void access(int x) {
	for(int y = 0; x; x = f[y = x]) {
		splay(x);
		si[x] += s[rc], s2i[x] += s[rc] * s[rc];
		rc = y, si[x] -= s[rc], s2i[x] -= s[rc] * s[rc];
		pushup(x);
	}
}
void link(int x) { access(x), splay(x), access(lst[x]), splay(lst[x]), f[x] = lst[x], si[f[x]] += s[x], s2i[f[x]] += s[x] * s[x], pushup(f[x]); }
void cut(int x) { access(x), splay(x), lc = f[lc] = 0, pushup(x); }
int findroot(int x) { access(x), splay(x); while(lc) x = lc; splay(x);  return x; }
int query(int x) { int rt = c[findroot(x)][1]; return s[rt] * s[rt]; }
int update(int x) {
	int res = 0;
	if(!ins[x]) {
		res = query(x);
		cut(x), res -= s2i[x] + s[rc] * s[rc];
		if(!ins[lst[x]]) res -= query(lst[x]);
	}
	else {
		res = s2i[x] + s[rc] * s[rc];
		if(!ins[lst[x]]) res += query(lst[x]);
		link(x), res -= query(x);
	}
	ins[x] ^= 1; return res;
}

signed main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) col[i] = get(), q[col[i]].push_back(make_pair(i, 0));
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, n + 1);
	for(int i = 1; i <= m; i++) {
		int x = get(), y = get();
		q[col[x]].push_back(make_pair(x, i)), q[col[x] = y].push_back(make_pair(x, i));
	}
	for(int i = 1; i <= n; i++) s[i] = 1;
	for(int i = 1; i <= n; i++) link(i);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < q[i].size(); j++) ans[q[i][j].second] += update(q[i][j].first);
		for(int j = 0; j < q[i].size(); j++) update(q[i][j].first);
	}
	for(int i = 0; i <= m; i++) ans[i] += ans[i - 1], printf("%lld\n", ans[i]);
	return 0;
}