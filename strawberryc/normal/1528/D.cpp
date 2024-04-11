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

const int N = 605, M = N << 1, INF = 0x3f3f3f3f;

int n, m, d[N][N], val[M];
ll f[N];
bool vis[N];

void calc(int u, int rem) {
  for (int i = 0; i < n; i++) val[(i + rem) % n] = d[u][i], val[i + n] = INF;
  for (int i = 1; i < (n << 1); i++)
    val[i] = Min(val[i], val[i - 1] + 1);
  for (int i = 0; i < n; i++) val[i] = Min(val[i], val[i + n]);
}

int main() {
  int x, y, z;
  read(n); read(m);
  memset(d, INF, sizeof(d));
  while (m--) read(x), read(y), read(z), d[x][y] = z;
  for (int S = 0; S < n; S++) {
  	for (int i = 0; i < n; i++) f[i] = i == S ? 0 : 1e18;
  	memset(vis, 0, sizeof(vis));
  	for (int T = 1; T < n; T++) {
  	  int u = -1; ll ds = 1e18;
  	  for (int i = 0; i < n; i++)
  	    if (!vis[i] && f[i] < ds) ds = f[i], u = i;
  	  vis[u] = 1; calc(u, f[u] % n);
  	  for (int v = 0; v < n; v++)
  	    f[v] = Min(f[v], f[u] + val[v]);
	}
	for (int i = 0; i < n; i++) printf("%d ", f[i]);
	puts("");
  }
  return 0;
}