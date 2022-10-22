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

const int N = 1010, M = 4e6 + 5, INF = 0x3f3f3f3f;

int n, m, a[N], S = 1, T = 2, ecnt = 1, nxt[M], adj[N], cur[N], st[M], go[M],
cap[M], cnt, len, que[N], lev[N], ans, A[N], B[N];

void add_edge(int u, int v, int w) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; st[ecnt] = u; go[ecnt] = v; cap[ecnt] = w;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; st[ecnt] = v; go[ecnt] = u; cap[ecnt] = 0;
}

bool bfs() {
  for (int i = 1; i <= n + 2; i++) lev[i] = -1, cur[i] = adj[i];
  lev[que[len = 1] = S] = 0;
  for (int i = 1; i <= len; i++) {
  	int u = que[i];
  	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
  	  if (cap[e] && lev[v] == -1)
  	    lev[que[++len] = v] = lev[u] + 1;
  }
  return lev[T] != -1;
}

int dinic(int u, int flow) {
  if (u == T) return flow;
  int res = 0;
  for (int &e = cur[u], v = go[e]; e; e = nxt[e], v = go[e])
    if (lev[u] < lev[v]) {
  	  int delta = dinic(v, Min(cap[e], flow - res));
  	  cap[e] -= delta; cap[e ^ 1] += delta;
  	  res += delta; if (res == flow) return res;
    }
  if (res < flow) lev[u] = -1;
  return res;
}

int main() {
  read(n); read(m);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) if (a[i] >= (m + 1 >> 1))
    return puts("-1"), 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i] > m / 3 && a[j] <= m / 3 && a[i] % a[j] == 0 && a[i] * 2 + a[j] <= m)
        add_edge(i + 2, j + 2, 1);
  for (int i = 1; i <= n; i++)
    if (a[i] > m / 3) add_edge(S, i + 2, 1), cnt++;
    else add_edge(i + 2, T, 1);
  while (bfs()) cnt -= dinic(S, INF);
  if (cnt) return puts("-1"), 0;
  for (int e = 2; e <= ecnt; e += 2) {
  	int u = st[e], v = go[e];
  	if (u == S) continue;
  	if (v == T && cap[e]) A[++ans] = a[u - 2] * 3, B[ans] = a[u - 2] * 2;
  	else if (v > T && !cap[e])
	  A[++ans] = a[u - 2] * 2 + a[v - 2], B[ans] = a[u - 2] + a[v - 2];
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d %d\n", A[i], B[i]);
  return 0;
}