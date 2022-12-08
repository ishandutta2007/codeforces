#pragma GCC optimized(2)
#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, Base = 19260817, Invb = 494863259, mod = 998244353;
int n;
char s[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int base[N], invb[N];
int dfn[N], rev[N], tim, fa[N], top[N], sze[N], son[N], dep[N];
int hshu[N], hshd[N]; // hash value from root to i / from i to root

void add(int u, int v) { edge[++tot].v = v, edge[tot].nxt = head[u], head[u] = tot; }

void init() { // previously calculate base^i and base^-i
	base[0] = invb[0] = 1;
	for(int i = 1; i <= n; i++) base[i] = 1ll * base[i - 1] * Base % mod, invb[i] = 1ll * invb[i - 1] * Invb % mod;
}

#define v edge[i].v
void dfs(int u, int lst) {
	fa[u] = lst, sze[u] = 1, dep[u] = dep[lst] + 1;
	hshu[u] = (1ll * hshu[lst] * Base % mod + s[u]) % mod;
	hshd[u] = (1ll * base[dep[u] - 1] * s[u] % mod + hshd[lst]) % mod;
	for(int i = head[u]; i; i = edge[i].nxt) if(v != lst) dfs(v, u), sze[u] += sze[v], son[u] = sze[v] > sze[son[u]]? v : son[u];
}
void df5(int u, int lst) {
	top[u] = lst, dfn[u] = ++tim, rev[tim] = u; 
	if(son[u]) df5(son[u], lst);
	for(int i = head[u]; i; i = edge[i].nxt) if(!top[v]) df5(v, v);
}
#undef v

int LCA(int x, int y) {
	while(top[x] ^ top[y]) dep[top[x]] > dep[top[y]]? x = fa[top[x]] : y = fa[top[y]];
	return dep[x] < dep[y]? x : y;
}

int KthFa(int x, int k) {
	while(dep[x] - dep[top[x]] < k && x != 1) 
		k -= dep[x] - dep[top[x]] + 1, x = fa[top[x]];
	return rev[dfn[x] - k];
}

int GetFa(int x, int y, int lca, int k) {
	int disl = dep[x] - dep[lca] + 1;
	if(k <= disl) return KthFa(x, k - 1);
	else return KthFa(y, dep[x] + dep[y] - 2 * dep[lca] + 1 - k);
}

int GetVal(int x, int y) {
	int lca = LCA(x, y), lcaf = fa[lca];
	int disu = dep[x] - dep[lca] + 1, disd = dep[y] - dep[lca];
	int resu = 1ll * (hshd[x] - hshd[lcaf] + mod) * invb[dep[lcaf]] % mod;
	int resd = (hshu[y] - 1ll * hshu[lca] * base[disd] % mod + mod) % mod;
	return (resd + 1ll * resu * base[disd] % mod) % mod;
}

signed main() {
	n = get(), scanf("%s", s + 1);
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	init(); 
	dfs(1, 0), df5(1, 1);
	int q = get();
	while(q--) {
		int a = get(), b = get(), c = get(), d = get();
		int lca1 = LCA(a, b), lca2 = LCA(c, d);
		int len1 = dep[a] + dep[b] - 2 * dep[lca1] + 1, len2 = dep[c] + dep[d] - 2 * dep[lca2] + 1;
		int l = 1, r = min(len1, len2), ans = 0;
		while(l <= r) {
			int mid = l + r >> 1;
			int fa1 = GetFa(a, b, lca1, mid), fa2 = GetFa(c, d, lca2, mid);
			if((GetVal(a, fa1) + mod) % mod == (GetVal(c, fa2) + mod) % mod) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

/*
3
abc
1 2
2 3
348407747
*/