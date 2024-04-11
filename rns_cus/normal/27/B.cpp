#include <bits/stdc++.h>
using namespace std;

#define N 101
#define inf 1000000

bool vis[N][N];
int n, a, b, f[N][N];

int main() {
//  freopen("b.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) if (i != j) f[i][j] = inf;
  }
  for (int i = 1; i < n * (n - 1) / 2; i ++) {
    scanf("%d %d", &a, &b);
    f[a][b] = 0;
    vis[a][b] = vis[b][a] = 1;
  }
  for (int k = 1; k <= n; k ++) {
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= n; j ++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
  }
  for (int i = 1; i < n; i ++) {
    for (int j = i + 1; j <= n; j ++) {
      if (!vis[i][j]) {
        if (!f[i][j]) printf("%d %d\n", i, j);
        else printf("%d %d\n", j, i);
        return 0;
      }
    }
  }
}