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

const int N = 1e5 + 5, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], a[N], d[N], tot;

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu) {
  if ((++tot) == 2) a[u] = -1, d[u] = 1;
  if (tot > 2) a[u] = d[fu], a[fu] -= a[u], d[u] = -a[u];
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) dfs(v, u);
}

void yhjssa() {
  ecnt = tot = 0;
  read(n);
  int x, y;
  for (int i = 1; i <= n; i++) adj[i] = 0;
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  a[1] = 1; d[1] = -1;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}