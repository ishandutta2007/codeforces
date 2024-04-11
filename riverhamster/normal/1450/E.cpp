#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 205;
int d[N][N];
vector<int> G[N];
int c[N];

void dfs(int x) {
  for (int v : G[x]) {
    if (!c[v]) c[v] = 3 - c[x], dfs(v);
    else if (c[v] != 3 - c[x]) {
      puts("NO");
      exit(0);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  memset(d, 0x3f, sizeof d);
  for (int i = 1; i <= n; ++i) d[i][i] = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v, dir;
    cin >> u >> v >> dir;
    G[u].push_back(v); G[v].push_back(u);
    if (dir) d[u][v] = 1, d[v][u] = -1;
    else d[u][v] = d[v][u] = 1;
  }
  for (int i = 1; i <= n; ++i)
    if (!c[i]) c[i] = 1, dfs(i);
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 1; i <= n; ++i)
    if (d[i][i] < 0) {
      puts("NO");
      return 0;
    }
  int res = 0, s = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      if (d[i][j] > res) s = i, res = d[i][j];
  }
  puts("YES");
  printf("%d\n", res);
  for (int i = 1; i <= n; ++i)
    printf("%d ", d[s][i]);
  return 0;
}