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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 2e5 + 5, M = N << 1;

int n, h[N], ecnt, nxt[M], adj[N], go[M], mx, fm[N], gm[N], tot, son[N],
prem[N], sufm[N], S;
ll ans = 1e18, f[N], g[N], pre[N], suf[N];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu) {
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) {
      dfs(v, u); fm[u] = Max(fm[u], fm[v]);
      f[u] += f[v];
	}
  if (h[u] > fm[u]) f[u] += h[u] - fm[u], fm[u] = h[u];
}

void dfs2(int u, int fu) {
  tot = 0;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) son[++tot] = v;
  prem[0] = sufm[tot + 1] = 0; pre[0] = suf[tot + 1] = 0;
  for (int i = 1; i <= tot; i++)
    prem[i] = Max(prem[i - 1], fm[son[i]]),
    pre[i] = pre[i - 1] + f[son[i]];
  for (int i = tot; i >= 1; i--)
    sufm[i] = Max(sufm[i + 1], fm[son[i]]),
    suf[i] = suf[i + 1] + f[son[i]];
  for (int i = 1; i <= tot; i++) {
  	int v = son[i];
  	gm[v] = Max(Max(prem[i - 1], sufm[i + 1]), gm[u]);
  	g[v] = pre[i - 1] + suf[i + 1] + g[u];
  	if (h[u] > gm[v]) g[v] += h[u] - gm[v], gm[v] = h[u];
  }
  ll res = g[u];
  for (int i = 1; i <= tot; i++) res += f[son[i]];
  if (u != S) ans = Min(ans, res);
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) dfs2(v, u);
}

int main() {
  int x, y;
  read(n);
  for (int i = 1; i <= n; i++)
    if (read(h[i]), h[i] > mx) mx = h[i], S = i;
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  dfs(1, 0); dfs2(1, 0);
  return std::cout << ans + mx << std::endl, 0;
}