#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int N = 405;
int dp[N][4][N], dp2[N][4][N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, M;
  cin >> n >> M;
  dp[2][0][1] = 1;
  dp[2][1][2] = 1;
  dp[1][3][0] = 1;
  for (int w = 3; w <= n; w++) {
    for (int x = 2; x <= w; x++) {
      for (int last = 1; last <= x; last++) {
        dp2[x][3][0] += dp[x][0][last];
        dp2[x][3][0] += dp[x][1][last];
        dp2[x][3][0] += dp[x][2][last];
        dp2[x][3][0] %= M;
      }
      for (int last = 1; last <= x; last++) {
        dp2[x][1][last] += dp2[x][1][last - 1];
        dp2[x][1][last] += dp[x - 1][0][last - 1];
        dp2[x][1][last] += dp[x - 1][1][last - 1];
        dp2[x][1][last] += dp[x - 1][2][last - 1];
        dp2[x][1][last] %= M;
        dp2[x][2][last] += dp[x - 1][3][0];
        dp2[x][2][last] %= M;
      }

      for (int last = x; last >= 1; last--) {
        dp2[x][0][last] += dp2[x][0][last + 1];
        dp2[x][0][last] += dp[x - 1][0][last];
        dp2[x][0][last] %= M;
        dp2[x][0][last] += dp[x - 1][2][last];
        dp2[x][0][last] %= M;
      }
    }

    for (int x = 0; x < N; x++) {
      for (int t = 0; t < 4; t++) {
        for (int l = 0; l < N; l++) {
          dp[x][t][l] = dp2[x][t][l];
          dp2[x][t][l] = 0;
        }
      }
    }
  }
  int ans = 0;
  for (int x = 1; x <= n; x++) {
    for (int t = 0; t <= 2; t++) {
      for (int l = 1; l <= x; l++) {
        ans += dp[x][t][l];
        ans %= M;
      }
    }
  }
  cout << ans << '\n';

}