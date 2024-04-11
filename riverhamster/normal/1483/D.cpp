#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

using ll = long long;

const int N = 605;

ll dis[N][N];
ll to[N][N];
int e[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  memset(dis, 0x3f, sizeof(dis));
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    dis[u][v] = min<ll>(dis[u][v], w);
    dis[v][u] = min<ll>(dis[v][u], w);
    e[u][v] = e[v][u] = w;
  }
  for (int i = 1; i <= n; ++i) dis[i][i] = 0;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v, l;
    scanf("%d%d%d", &u, &v, &l);
    for (int i = 1; i <= n; ++i) {
      to[i][v] = max(to[i][v], l - dis[u][i]);
      to[i][u] = max(to[i][u], l - dis[v][i]);
    }
  }
  int res = 0;
  for (int u = 1; u <= n; ++u)
    for (int v = u + 1; v <= n; ++v)
      if (e[u][v])
        for (int t = 1; t <= n; ++t)
          if (to[u][t] - e[u][v] >= dis[v][t]) {
            ++res;
            break;
          }
  printf("%d\n", res);
  return 0;
}