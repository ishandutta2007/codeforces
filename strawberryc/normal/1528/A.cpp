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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Abs(const T &a) {return a > 0 ? a : -a;}

typedef long long ll;

const int N = 1e5 + 5, M = N << 1;

int n, l[N], r[N], ecnt, nxt[M], adj[N], go[M];
ll f[N][2];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu) {
  f[u][0] = f[u][1] = 0;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) {
      dfs(v, u);
      f[u][0] += Max(f[v][0] + Abs(l[u] - l[v]), f[v][1] + Abs(l[u] - r[v]));
      f[u][1] += Max(f[v][0] + Abs(r[u] - l[v]), f[v][1] + Abs(r[u] - r[v]));
	}
}

void yhjssa() {
  int x, y;
  ecnt = 0; read(n);
  for (int i = 1; i <= n; i++) adj[i] = 0, read(l[i]), read(r[i]);
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  dfs(1, 0);
  printf("%lld\n", Max(f[1][0], f[1][1]));
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}