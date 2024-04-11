#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 2e5 + 5, M = N << 1, L = M << 1, wd = 998244353;

int n, ecnt, nxt[M], adj[N], go[M], tot, pri[N], minp[N], X[M], Y[M],
res[N], ans, inv[N], cnt[N], mxc[N];
bool mark[N];

void sieve() {
  inv[1] = 1;
  for (int i = 2; i <= 200000; i++)
    inv[i] = 1ll * (wd - wd / i) * inv[wd % i] % wd;
  for (int i = 2; i <= 200000; i++) {
  	if (!mark[i]) pri[++tot] = i, minp[i] = i;
  	for (int j = 1; j <= tot; j++) {
  	  if (1ll * i * pri[j] > 200000) break;
  	  mark[i * pri[j]] = 1; minp[i * pri[j]] = pri[j];
  	  if (i % pri[j] == 0) break;
	}
  }
}

int qpow(int a, int b) {
  int res = 1;
  while (b) {
  	if (b & 1) res = 1ll * res * a % wd;
  	a = 1ll * a * a % wd;
  	b >>= 1;
  }
  return res;
}

void add_edge(int u, int v, int x, int y) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; X[ecnt] = x; Y[ecnt] = y;
  nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; X[ecnt] = y; Y[ecnt] = x;
}

void dfs(int u, int fu) {
  ans = (ans + res[u]) % wd;
  for (int e = adj[u], v; e; e = nxt[e])
    if ((v = go[e]) != fu) {
      int x = X[e], y = Y[e];
	  res[v] = 1ll * res[u] * y % wd * inv[x] % wd;
	  for (int z = x; z > 1; z /= minp[z])
	    if ((++cnt[minp[z]]) > mxc[minp[z]]) mxc[minp[z]] = cnt[minp[z]];
	  for (int z = y; z > 1; z /= minp[z]) cnt[minp[z]]--;
	  dfs(v, u);
	  for (int z = x; z > 1; z /= minp[z]) cnt[minp[z]]--;
	  for (int z = y; z > 1; z /= minp[z]) cnt[minp[z]]++;
    }
}

void yhjssa() {
  int u, v, x, y;
  read(n); ecnt = ans = 0; res[1] = 1;
  for (int i = 1; i <= n; i++) adj[i] = mxc[i] = 0;
  for (int i = 1; i < n; i++) {
  	read(u); read(v); read(x); read(y);
  	int g = std::__gcd(x, y); x /= g; y /= g;
  	add_edge(u, v, x, y);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) ans = 1ll * ans * qpow(i, mxc[i]) % wd;
  printf("%d\n", ans);
}

int main() {
  int T; read(T); sieve();
  while (T--) yhjssa();
  return 0;
}