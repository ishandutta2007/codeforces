#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 3e5 + 5, M = 20;

int n, a[N], b[N], sze[N], dfn[N], lst[N], ecnt, nxt[N], adj[N], go[N], res, ans,
fa[N][M];
bool vis[N];

struct BIT {
  int A[N];
  
  void change(int x, int v) {
  	for (; x <= n; x += x & -x)
  	  A[x] += v;
  }
  
  int query(int x) {
  	int res = 0;
  	for (; x; x -= x & -x)
  	  res += A[x];
  	return res;
  }
  
  int ask(int l, int r) {return query(r) - query(l - 1);}
  
  int subt(int u) {return ask(dfn[u], dfn[u] + sze[u] - 1);}
} T;

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void dfs(int u) {
  int t_res = res;
  if (!T.subt(u)) {
  	res++;
  	int v = u;
  	for (int k = 18; k >= 0; k--)
  	  if (fa[v][k] && !T.subt(fa[v][k])) v = fa[v][k];
  	if (v > 1 && vis[b[v]] && T.subt(b[v]) == 1) res--;
  }
  T.change(dfn[u], 1);
  vis[u] = 1; if (res > ans) ans = res;
  for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
    dfs(v);
  T.change(dfn[u], -1);
  res = t_res; vis[u] = 0;
}

void yhjssa() {
  read(n); ecnt = ans = 0;
  for (int i = 2; i <= n; i++) read(a[i]);
  for (int i = 2; i <= n; i++) read(b[i]);
  for (int i = 1; i <= n; i++) sze[i] = 1, adj[i] = 0;
  for (int i = n; i >= 2; i--) sze[b[i]] += sze[i];
  dfn[1] = 1; lst[1] = 2;
  for (int i = 2; i <= n; i++)
    dfn[i] = lst[b[i]], lst[i] = dfn[i] + 1, lst[b[i]] = dfn[i] + sze[i];
  for (int i = 2; i <= n; i++) add_edge(a[i], i);
  for (int i = 1; i <= n; i++) T.A[i] = 0, fa[i][0] = b[i];
  for (int k = 0; k < 18; k++)
    for (int u = 1; u <= n; u++) fa[u][k + 1] = fa[fa[u][k]][k];
  printf("%d\n", (dfs(1), ans));
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}