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

const int N = 2005, M = N << 1;

int n, wd, ecnt, nxt[M], adj[N], go[M], f[N][N], s[N][N], sl[N],
sr[N], fw[N][N], tot, son[N], ans[N], C[N][N];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu) {
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) dfs(v, u);
  for (int i = 1; i <= n; i++) f[u][i] = 1;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) for (int i = 1; i <= n; i++)
	  f[u][i] = 1ll * f[u][i] * s[v][i] % wd;
  if (u == 1) return;
  for (int i = 1; i <= n; i++) {
  	tot = 0;
  	for (int e = adj[u], v; e; e = nxt[e])
  	  if ((v = go[e]) != fu) son[++tot] = v, sl[tot] = sr[tot] = s[v][i];
  	sl[0] = sr[tot + 1] = 1;
  	for (int j = 1; j <= tot; j++) sl[j] = 1ll * sl[j - 1] * sl[j] % wd;
  	for (int j = tot; j >= 1; j--) sr[j] = 1ll * sr[j + 1] * sr[j] % wd;
  	for (int j = 1; j <= tot; j++) fw[son[j]][i] =
	  (1ll * sl[j - 1] * sr[j + 1] + fw[son[j]][i - 1]) % wd;
  }
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) for (int i = 1; i <= n; i++)
      f[u][i] = (1ll * f[v][i] * fw[v][i - 1] + f[u][i]) % wd;
  for (int i = 1; i <= n; i++) s[u][i] = (s[u][i - 1] + f[u][i]) % wd;
}

int main() {
  int x, y;
  read(n); read(wd);
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  for (int i = 0; i <= n; i++) C[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % wd;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) ans[i] = f[1][i];
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      ans[i] = (ans[i] - 1ll * ans[j] * C[i - 1][j - 1] % wd + wd) % wd;
  for (int i = 2; i <= n; i++) ans[i] = (ans[i] - ans[i - 1] + wd) % wd;
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
  return puts(""), 0;
}