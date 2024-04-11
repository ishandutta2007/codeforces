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

const int N = 2e5 + 5, M = 1005;

int n, fa[N], m, arr[N], X;
bool iscycle = 1, g[M][M];
ll sum, ans;

struct edge {
  int x, y, z;
} a[N];

std::vector<int> eg[N];

int cx(int x) {
  if (fa[x] != x) fa[x] = cx(fa[x]);
  return fa[x];
}

bool zm(int x, int y) {
  if ((x = cx(x)) != (y = cx(y))) return fa[y] = x, 1;
  return 0;
}

void disconnected() {
  for (int u = 1; u <= n; u++) {
  	std::sort(eg[u].begin(), eg[u].end());
  	for (int i = 0; i + 1 < eg[u].size(); i++)
  	  if (eg[u][i] + 1 < eg[u][i + 1])
  	    zm(u, eg[u][i] + 1), arr[eg[u][i] + 2]++, arr[eg[u][i + 1]]--;
  }
  for (int i = 3; i <= n; i++) arr[i] += arr[i - 1];
  for (int i = 2; i <= n; i++) if (arr[i]) zm(i, i - 1);
}

int main() {
  read(n); read(m);
  for (int i = 1; i <= n; i++) fa[i] = i,
    eg[i].push_back(0), eg[i].push_back(n + 1);
  for (int i = 1; i <= m; i++) {
  	read(a[i].x); read(a[i].y); read(a[i].z); X ^= a[i].z;
  	if (a[i].x > a[i].y) std::swap(a[i].x, a[i].y);
  	eg[a[i].x].push_back(a[i].y); eg[a[i].y].push_back(a[i].x);
  }
  std::sort(a + 1, a + m + 1, [&](edge u, edge v) {return u.z < v.z;});
  if (1ll * n * (n - 1) / 2 - m < n) {
  	iscycle = 0;
  	for (int i = 1; i <= m; i++) g[a[i].x][a[i].y] = 1;
  	for (int i = 1; i <= n; i++)
  	  for (int j = i + 1; j <= n; j++)
  	    if (!g[i][j] && !zm(i, j)) iscycle = 1;
  	for (int i = 1; i <= n; i++) fa[i] = i;
  }
  disconnected();
  for (int i = 1; i <= m; i++)
  	if (zm(a[i].x, a[i].y)) sum += a[i].z;
  if (iscycle) return std::cout << sum << std::endl, 0;
  ans = sum + X;
  if (n > 2) for (int x = 1; x <= n; x++)
    for (int y = x + 1; y <= n; y++)
      if (!g[x][y]) {
      	for (int i = 1; i <= n; i++) fa[i] = i;
      	ll nans = 0;
      	for (int i = 1; i <= n; i++)
      	  for (int j = i + 1; j <= n; j++)
      	    if (!g[i][j] && (i != x || j != y))
      	      zm(i, j);
      	for (int i = 1; i <= m; i++)
      	  if (zm(a[i].x, a[i].y)) nans += a[i].z;
      	if (nans < ans) ans = nans;
	  }
  return std::cout << ans << std::endl, 0;
}