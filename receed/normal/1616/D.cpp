#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
      cin >> a[i];
    cin >> x;
    rep(i, n)
      a[i] -= x;
    int inf = 1e8;
    vector<vector<int>> dp(n + 1, vector<int>(4, -inf));
    dp[0][0] = 0;
    rep(i, n) {
      dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0], max(dp[i][1], max(dp[i][2], dp[i][3]))));
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
      if (i > 0 && a[i] + a[i - 1] >= 0) {
        dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + 1);
        if (i > 1 && a[i] + a[i - 1] + a[i - 2] >= 0)
          dp[i + 1][3] = max(dp[i + 1][3], max(dp[i][2], dp[i][3]) + 1);
      }
    }
    int res = 0;
    rep(i, 4)
      res = max(res, dp[n][i]);
    cout << res << '\n';
  }
}