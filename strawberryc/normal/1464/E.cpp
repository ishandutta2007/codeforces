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

const int N = 6e5 + 5, EI = 998244353;

int n, m, ecnt, nxt[N], adj[N], go[N], L = 1, H, T, Q[N], d[N], SG[N],
vis[N], f[N], ans;

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; d[v]++;
}

int qpow(int a, int b) {
  int res = 1;
  while (b) {
  	if (b & 1) res = 1ll * res * a % EI;
  	a = 1ll * a * a % EI;
  	b >>= 1;
  }
  return res;
}

int main() {
  int x, y;
  read(n); read(m);
  for (int i = 1; i <= m; i++) read(x), read(y), add_edge(x, y);
  for (int i = 1; i <= n; i++) if (!d[i]) Q[++T] = i;
  while (H < T) {
  	int u = Q[++H];
  	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
  	  if (!(--d[v])) Q[++T] = v;
  }
  for (int i = n; i >= 1; i--) {
  	int u = Q[i];
  	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
  	  vis[SG[v]] = i;
  	while (vis[SG[u]] == i) SG[u]++;
  }
  while (L <= m) L <<= 1;
  int in = qpow(n + 1, EI - 2);
  for (int i = 1; i <= n; i++) f[SG[i]] = (f[SG[i]] + in) % EI;
  for (int k = 1; k < L; k <<= 1)
    for (int i = 0; i < n; i += k << 1)
      for (int j = 0; j < k; j++) {
      	int u = f[i + j], v = f[i + j + k];
      	f[i + j] = (u + v) % EI;
      	f[i + j + k] = (u - v + EI) % EI;
	  }
  for (int i = 0; i < L; i++)
    ans = (ans + qpow((1 - f[i] + EI) % EI, EI - 2)) % EI;
  return std::cout << (1 - 1ll * ans * in % EI * qpow(L, EI - 2) % EI
    + EI) % EI << std::endl, 0;
}