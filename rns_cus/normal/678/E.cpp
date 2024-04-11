#include <bits/stdc++.h>
using namespace std;

double p[18][18], dp[1<<18][18];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%lf", &p[i][j]);
  dp[1][0] = 1.;
  for (int i = 2; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) if (i & (1 << j)) {
      for (int k = 0; k < n; k++) if ((k != j) && (i << (1 << k))) {
        dp[i][j] = max(dp[i][j], p[j][k]*dp[i ^ (1 << k)][j] + p[k][j] * dp[i ^ (1 << j)][k]);
      }
    }
  }
  double ans = 0.;
  for (int i = 0; i < n; i++) ans = max(ans, dp[(1 << n) - 1][i]);
  printf("%.12lf\n", ans);
}