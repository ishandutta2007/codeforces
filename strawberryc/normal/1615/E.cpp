#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 2e5 + 5, M = N << 1, L = M << 1;

int n, k, ecnt, nxt[M], adj[N], go[M], dfn[N], to[N], sze[N], ToT, add[L],
res[N], fa[N], dep[N];
bool vis[N];
ll ans = -1e18;

struct val {
  int maxv, maxp;
  
  friend inline val operator + (val u, val v) {
  	if (u.maxv > v.maxv) return u;
  	else return v;
  }
} T[L];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu) {
  to[dfn[u] = ++ToT] = u; sze[u] = 1; fa[u] = fu; dep[u] = dep[fu] + 1;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) dfs(v, u), sze[u] += sze[v];
}

void build(int l, int r, int p) {
  if (l == r) return (void) (T[p] = (val) {dep[to[l]], l});
  int mid = l + r >> 1;
  build(l, mid, p2); build(mid + 1, r, p3);
  T[p] = T[p2] + T[p3];
}

void change(int l, int r, int s, int e, int v, int p) {
  if (e < l || s > r) return;
  if (s <= l && r <= e) return (void) (add[p] += v, T[p].maxv += v);
  int mid = l + r >> 1;
  change(l, mid, s, e, v, p2); change(mid + 1, r, s, e, v, p3);
  T[p] = T[p2] + T[p3]; T[p].maxv += add[p];
}

int main() {
  int x, y;
  read(n); read(k);
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  dfs(1, 0); build(1, n, 1);
  for (int i = 1; i <= k; i++) {
  	val top = T[1];
  	if (top.maxv) {
  	  res[i] = res[i - 1] + top.maxv; int u = to[top.maxp];
  	  while (u && !vis[u]) change(1, n, dfn[u], dfn[u] + sze[u] - 1, -1, 1),
		vis[u] = 1, u = fa[u];
	}
	else res[i] = n;
	int b = n - res[i] < n / 2 ? n - res[i] : n / 2;
	if (1ll * b * b - 1ll * n * b + 1ll * i * (n - i) > ans)
	  ans = 1ll * b * b - 1ll * n * b + 1ll * i * (n - i);
  }
  return std::cout << ans << std::endl, 0;
}