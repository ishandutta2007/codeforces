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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 605;
const ll INF = 1e18;

int n, m, q, ans;
ll a[N][N], f[N][N], g[N][N], h[N];
bool res[N][N];

int main() {
  int x, y, z;
  read(n); read(m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) a[i][j] = f[i][j] = INF, g[i][j] = -INF;
  while (m--) read(x), read(y), read(z), a[x][y] = a[y][x] = f[x][y] = f[y][x] = z;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = Min(f[i][j], f[i][k] + f[k][j]);
  read(q);
  while (q--) read(x), read(y), read(z), g[x][y] = g[y][x] = z;
  for (int S = 1; S <= n; S++) {
  	for (int u = 1; u <= n; u++) {
  	  h[u] = -INF;
  	  for (int v = 1; v <= n; v++)
  	    h[u] = Max(h[u], g[S][v] - f[u][v]);
	}
	for (int u = 1; u <= n; u++)
	  for (int v = u + 1; v <= n; v++)
	    if (f[S][u] + a[u][v] <= h[v])
	      res[u][v] = 1;
  }
  for (int u = 1; u <= n; u++)
    for (int v = u + 1; v <= n; v++)
      if (res[u][v]) ans++;
  return std::cout << ans << std::endl, 0;
}