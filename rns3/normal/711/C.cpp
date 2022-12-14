#include <bits/stdc++.h>
using namespace std;

const int M = 101;

long long f[M][M][M];
int a[M][M];
int c[M];

const long long inf = 1e18;

int main() {
  ///freopen("3.in", "r", stdin);
  int n, m, K;
  scanf("%d %d %d", &n, &m, &K);
  for(int i = 1; i <= n; i ++) scanf("%d", &c[i]);
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
  }
  for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) for(int k = 0; k < K; k ++) f[i][j][k] = inf;
  if(c[1] == 0) {
    for(int i = 1; i <= m; i ++) f[1][i][0] = a[1][i];
  }
  else {
    f[1][c[1]][0] = 0;
  }
  for(int i = 2; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      if(c[i] && c[i] != j) continue;
      for(int k = 0; k < K; k ++) {
        for(int r = 1; r <= m; r ++) {
          if(!k && r != j) continue;
          if(c[i]) f[i][j][k] = min(f[i][j][k], f[i-1][r][k-(r!=j)]);
          else f[i][j][k] = min(f[i][j][k], f[i-1][r][k-(r!=j)] + a[i][j]);
        }
      }
    }
  }
  long long ans = inf;
  for(int i = 1; i <= m; i ++) ans = min(ans, f[n][i][K-1]);
  if(ans == inf) puts("-1");
  else printf("%I64d\n", ans);
}