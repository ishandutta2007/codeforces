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

const int N = 2e5 + 5, M = N << 1;

int n, m, fa[N], orz[N], ecnt, nxt[M], adj[N], go[M], val[M], d[N];
bool haveAns;

void add_edge(int u, int v, int w) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

int cx(int x) {
  int z;
  if (fa[x] != x) z = cx(fa[x]), orz[x] ^= orz[fa[x]], fa[x] = z;
  return fa[x];
}

bool zm(int x, int y, int z) {
  int ix = cx(x), iy = cx(y);
  if (ix != iy) return fa[iy] = ix, orz[iy] = z ^ orz[x] ^ orz[y], 1;
  return !(orz[x] ^ orz[y] ^ z);
}

void dfs(int u, int fu) {
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) {
      if (val[e] != -1) printf("%d %d %d\n", u, v, val[e]);
      else printf("%d %d %d\n", u, v, (d[u] ^ d[v]) ? 1 : 3);
      dfs(v, u);
	}
}

void yhjssa() {
  int x, y, z; haveAns = 1;
  read(n); read(m); ecnt = 0;
  for (int i = 1; i <= n; i++) adj[i] = 0, fa[i] = i, orz[i] = 0;
  for (int i = 1; i < n; i++) {
  	read(x); read(y); read(z); int zl = 0;
  	for (int T = 0; T < 30; T++) if ((z >> T) & 1) zl ^= 1;
  	if (z != -1) zm(x, y, zl);
  	add_edge(x, y, z);
  }
  while (m--) if (read(x), read(y), read(z), !zm(x, y, z)) haveAns = 0;
  if (!haveAns) return (void) puts("NO");
  puts("YES");
  for (int i = 1; i <= n; i++) if (fa[i] == i) d[i] = 0;
  for (int i = 1; i <= n; i++) if (fa[i] != i) cx(i), d[i] = orz[i];
  for (int s = 1; s <= n; s++) if (fa[s] == s) {dfs(s, 0); break;}
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}