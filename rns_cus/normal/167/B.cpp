#include <bits/stdc++.h>
using namespace std;
#define M 222

double p[M], dp[M][M][M];
int a[M], n, l, K;

int main(){
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d", &n, &l, &K);
  for (int i = 0; i < n; i++) scanf("%lf", p + i), p[i] /= 100;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  dp[0][0][0] = 1.;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i + 1][j + 1][min(k + a[i] + 1, n)] += dp[i][j][k] * p[i];
        dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i]);
      }
    }
  }
  double ans = 0.;
  for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) if (i >= l && K >= i - j) ans += dp[n][i][j];
  printf("%.20lf\n", ans);
}