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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 505, M = 22, L = N * N, W = L << 2, INF = 0x3f3f3f3f;

int n, m, k, ecnt, nxt[W], adj[L], go[W], val[W], f[L][M];

void add_edge(int u, int v, int w) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

int o(int x, int y) {return (x - 1) * m + y;}

int main() {
  int x;
  read(n); read(m); read(k);
  if (k & 1) {
  	for (int i = 1; i <= n; i++) {
  	  for (int j = 1; j <= m; j++) printf("-1 ");
  	  puts("");
	}
	return 0;
  }
  k >>= 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < m; j++)
      read(x), add_edge(o(i, j), o(i, j + 1), x);
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++)
      read(x), add_edge(o(i, j), o(i + 1, j), x);
  memset(f, INF, sizeof(f));
  for (int i = 1; i <= n * m; i++) f[i][0] = 0;
  for (int i = 1; i <= k; i++)
    for (int u = 1; u <= n * m; u++)
      for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
        f[u][i] = Min(f[u][i], val[e] + f[v][i - 1]);
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= m; j++)
  	  printf("%d ", f[o(i, j)][k] << 1);
  	puts("");
  }
  return 0;
}