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

int n, ecnt = 1, nxt[M], adj[N], go[M], fib[N], to[N], sze[N], tot, pts[N], fm[N];
bool vis[M];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu) {
  pts[++tot] = u; sze[u] = 1;
  for (int e = adj[u], v; e; e = nxt[e])
    if (!vis[e] && (v = go[e]) != fu)
      dfs(v, u), sze[u] += sze[v], fm[v] = e;
}

bool judge(int u) {
  tot = 0; dfs(u, 0);
  if (sze[u] == 1) return 1;
  if (!to[sze[u]]) return 0;
  int u1 = 0, u2 = 0, th = to[sze[u]], tmp;
  for (int i = 2; i <= tot; i++)
    if (sze[pts[i]] == fib[th - 1] || sze[pts[i]] == fib[th - 2])
      (u1 ? u2 : u1) = pts[i];
  if (!u1 && !u2) return 0;
  if (!u2) return vis[fm[u1]] = vis[fm[u1] ^ 1] = 1,
    tmp = fm[u1], judge(u1) && judge(go[tmp ^ 1]);
  if (sze[u1] > sze[u2]) std::swap(u1, u2);
  vis[fm[u1]] = vis[fm[u1] ^ 1] = vis[fm[u2]] = vis[fm[u2] ^ 1] = 1;
  tmp = fm[u2];
  return judge(u1) && judge(u2) && judge(go[tmp ^ 1]);
}

int main() {
  int x, y;
  read(n); fib[0] = fib[1] = 1;
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  for (int i = 2; fib[i - 1] <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
  for (int i = 1; fib[i] <= n; i++) to[fib[i]] = i;
  puts(judge(1) ? "Yes" : "No");
  return 0;
}