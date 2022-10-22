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

const int N = 1e5 + 5, M = N << 1, E = 20;

int n, m, X[M], Y[M], ecnt, nxt[M], adj[N], go[M], fa[N], dfn[N], sze[N],
ans[N], ToT, par[N][E], dep[N];
bool is[M];

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

bool zm(int x, int y) {
  if ((x = cx(x)) != (y = cx(y))) return fa[y] = x, 1;
  return 0;
}

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

int ao(int l, int r) {ans[l]++; ans[r + 1]--;}

void dfs(int u, int fu) {
  par[u][0] = fu; dep[u] = dep[fu] + 1;
  for (int i = 0; i < 17; i++) par[u][i + 1] = par[par[u][i]][i];
  dfn[u] = ++ToT; sze[u] = 1;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) dfs(v, u), sze[u] += sze[v];
}

int lst(int u, int v) {
  int d = dep[v] - dep[u] - 1;
  for (int i = 17; i >= 0; i--)
    if ((d >> i) & 1) v = par[v][i];
  return v;
}

int main() {
  read(n); read(m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
  	read(X[i]); read(Y[i]);
  	if (is[i] = zm(X[i], Y[i])) add_edge(X[i], Y[i]);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) if (!is[i]) {
  	int u = X[i], v = Y[i], w;
  	if (dfn[u] > dfn[v]) std::swap(u, v);
  	if (dfn[v] >= dfn[u] + sze[u]) ao(dfn[u], dfn[u] + sze[u] - 1),
  	  ao(dfn[v], dfn[v] + sze[v] - 1);
  	else ao(dfn[v], dfn[v] + sze[v] - 1),
	  w = lst(u, v), ao(1, dfn[w] - 1), ao(dfn[w] + sze[w], n);
  }
  for (int i = 2; i <= n; i++) ans[i] += ans[i - 1];
  for (int i = 1; i <= n; i++) putchar(ans[dfn[i]] == m - n + 1 ? '1' : '0');
  return 0;
}