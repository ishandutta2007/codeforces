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

typedef long long ll;

const int N = 2e5 + 5;

int n, m, q, ecnt, nxt[N], adj[N], st[N], go[N], val[N], bel[N], top, stk[N],
dfn[N], low[N], ToT, tot;
ll f[N], g[N];

ll Abs(ll x) {return x < 0 ? -x : x;}

void add_edge(int u, int v, int w) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; st[ecnt] = u; go[ecnt] = v; val[ecnt] = w;
}

void dfs(int u) {
  dfn[stk[++top] = u] = low[u] = ++ToT;
  for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
    if (!dfn[v]) {
      f[v] = f[u] + val[e]; dfs(v);
      low[u] = Min(low[u], low[v]);
	}
	else if (!bel[v]) low[u] = Min(low[u], dfn[v]);
  if (dfn[u] == low[u]) {
  	bel[u] = ++tot; int v;
  	while (v = stk[top--], v != u) bel[v] = tot;
  }
}

int main() {
  int x, y, z;
  read(n); read(m);
  while (m--) read(x), read(y), read(z), add_edge(x, y, z);
  for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i);
  for (int e = 1; e <= ecnt; e++)
    if (bel[st[e]] == bel[go[e]] && f[go[e]] - f[st[e]] != val[e])
      g[bel[st[e]]] = std::__gcd(g[bel[go[e]]], Abs(f[go[e]] - f[st[e]] - val[e]));
  read(q);
  while (q--) {
  	read(x); read(y); read(z);
  	puts(!y || (g[bel[x]] && y % std::__gcd(1ll * z, g[bel[x]]) == 0)
      ? "YES" : "NO");
  }
  return 0;
}