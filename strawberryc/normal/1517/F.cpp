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

const int N = 305, M = N << 1, wd = 998244353;

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T, class D>
inline void add(T &a, const D &b) {if ((a += b) >= wd) a -= wd;}

int n, ecnt, nxt[M], adj[N], go[M], ans, f[N][N], g[N][N], md[N], xf[N], xg[N], h[N];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu, int r) {
  md[u] = 0;
  f[u][0] = g[u][0] = 1;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) {
      dfs(v, u, r);
      int m = Max(md[v] + 1, md[u]);
      for (int i = 0; i <= m; i++) xf[i] = xg[i] = 0;
      for (int i = 0; i <= md[u]; i++)
        for (int j = 0; j <= md[v]; j++) {
          add(xg[Max(i, j + 1)], 1ll * g[u][i] * g[v][j] % wd);
          add(xf[Min(i, j + 1)], 1ll * f[u][i] * f[v][j] % wd);
          add(i + j + 1 <= r ? xf[i] : xg[j + 1], 1ll * f[u][i] * g[v][j] % wd);
          add(i + j + 1 <= r ? xf[j + 1] : xg[i], 1ll * g[u][i] * f[v][j] % wd);
		}
	  for (int i = 0; i <= m; i++) f[u][i] = xf[i], g[u][i] = xg[i];
      md[u] = m;
	}
  
}

int main() {
  int x, y;
  read(n); ans = n - 1;
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  for (int i = 1; i < n; i++) {
  	dfs(1, 0, i);
  	for (int j = 0; j <= md[1]; j++) add(h[i], f[1][j]);
  }
  for (int i = 1; i < n - 1; i++) add(ans, 1ll * i * (h[i + 1] - h[i] + wd) % wd);
  for (int i = 1; i <= n; i++) ans = 499122177ll * ans % wd;
  return std::cout << ans << std::endl, 0;
}