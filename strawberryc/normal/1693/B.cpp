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

typedef long long ll;

const int N = 2e5 + 5;

int n, l[N], r[N], ecnt, nxt[N], adj[N], go[N];
ll val[N];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

int dfs(int u) {
  int res = 0; val[u] = 0;
  for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
    res += dfs(v), val[u] += val[v];
  if (val[u] >= r[u]) val[u] = r[u];
  else if (val[u] < l[u]) val[u] = r[u], res++;
  return res;
}

int main() {
  int T; read(T);
  while (T--) {
  	int x;
  	read(n); ecnt = 0;
  	for (int i = 1; i <= n; i++) adj[i] = 0;
  	for (int i = 2; i <= n; i++) read(x), add_edge(x, i);
  	for (int i = 1; i <= n; i++) read(l[i]), read(r[i]);
  	printf("%d\n", dfs(1));
  }
  return 0;
}