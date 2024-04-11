#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const ld inf = 1e18;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    ld c, t;
    scanf("%d %lf %lf", &n, &c, &t);
    vector<pair<int, int>> a(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &a[i].first, &a[i].second);
      m += a[i].second;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>> ());
    vector<ld> power(n + 1);
    power[0] = 1;
    for (int i = 1; i <= n; ++i) {
      power[i] = power[i - 1] * 0.9;
    }
    vector<vector<ld>> dp(m + 1, vector<ld> (n + 1, inf));
    dp[0][0] = 0;
    for (auto p : a) {
      for (int i = m; i >= p.second; --i) {
        for (int j = n; j; --j) {
          dp[i][j] = min(dp[i][j], dp[i - p.second][j - 1] + p.first / power[j]);
        }
      }
    }
    int answer = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i][j] != inf) {
          ld s = max(sqrt(dp[i][j] / c), 1 / c);
          if (dp[i][j] / c / s + s - 1 / c + 10 * j <= t) {
            answer = i;
          }
        }
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}