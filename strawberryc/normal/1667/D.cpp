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

int n, ecnt, nxt[M], adj[N], go[M], d[N], anst, X[N], Y[N];

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
  d[u]++; d[v]++;
}

int dfs(int u, int fu) {
  int tmp, tl = 0, tr = 0;
  std::vector<int> sons, ano;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu)
	  sons.push_back(v), ano.push_back(dfs(v, u));
  for (int i = 0; i < ano.size(); i++) if (ano[i] == -1) return -1;
  std::vector<int> son1, son2, son2s;
  for (int i = 0; i < sons.size(); i++)
    if (ano[i]) son2.push_back(sons[i]), son2s.push_back(ano[i]);
    else son1.push_back(sons[i]);
  while (tl < son1.size() || tr < son2.size())
    if (d[u] & 1) {
      if (tl >= son1.size()) break;
      X[++anst] = u; Y[anst] = son1[tl++];
      d[u]--;
	}
	else {
	  if (tr >= son2.size()) break;
	  X[++anst] = u; Y[anst] = son2[tr];
	  X[++anst] = son2[tr]; Y[anst] = son2s[tr++];
	  d[u]--;
	}
  if (tr < son2.size() || tl + 1 < son1.size()) return -1;
  if (tl >= son1.size()) return 0;
  return son1[tl];
}

void yhjssa() {
  int x, y; ecnt = anst = 0;
  read(n);
  for (int i = 1; i <= n; i++) adj[i] = d[i] = 0;
  for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
  if (dfs(1, 0) || anst < n - 1) return (void) puts("NO");
  puts("YES");
  for (int i = 1; i < n; i++) printf("%d %d\n", X[i], Y[i]);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}