#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4200;

int dp[2][MAXN][MAXN]; // dp[i][j][k] -- max profit starting from candidate i, given a state w/ k ppl of aggr j

int ar[MAXN];
int cost[MAXN];
int reward[MAXN];
int ctz[MAXN];
int rr[MAXN][MAXN]; // rr[i][k] = reward[i] + reward[i + 1] + ... + reward[i + ctz(k + 1)]

// dp[i][a][c] -> dp[i - 1][a][c + 1] (when ar[i] = a)
//    weight = -cost[i] + rr[a][c];
// dp[i][a][c] -> dp[i][a + 1][c / 2]
//   weight = 0

const int inf = 1000 << 20;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> ar[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }
  for(int i = 1; i <= n + m; ++i) {
    cin >> reward[i];
  }
  for(int i = 1; i < MAXN; ++i) {
    ctz[i] = __builtin_ctz(i);
    ctz[i] = 0;
    int x = i;
    while (x % 2 == 0) {
      ++ctz[i];
      x /= 2;
    }
  }

  for(int i = 1; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      for(int k = 0; k <= ctz[j + 1]; ++k) {
        rr[i][j] += reward[i + k];
      }
    }
  }

  int ans = 0;
  for (int a = 1; a <= m; ++a) {
    for (int c = 0; c <= n; ++c) {
      dp[0][a][c] = -inf;
      dp[1][a][c] = -inf;
    }
    dp[0][a][0] = 0;
    dp[1][a][0] = 0;
  }
  for(int i = n; i >= 0; --i) {
    for(int a = 1; a <= m; ++a) {
      for (int c = 0; c <= n; ++c) {
        int cur = dp[i & 1][a][c];
        if (cur == -inf) break;
        ans = max(ans, cur);
        if (i == 0) continue;
        if (ar[i] == a) {
          int &v = dp[(i - 1) & 1][a][c + 1];
          int cand = cur - cost[i] + rr[a][c];
          v = max(v, cand);
        }
        int &v2 = dp[i & 1][a + 1][c / 2];
        v2 = max(v2, cur);
        int &v3 = dp[(i - 1) & 1][a][c];
        v3 = max(v3, cur);
      }
    }
  }

  cout << ans << "\n";
}