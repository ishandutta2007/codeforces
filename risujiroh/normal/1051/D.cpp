#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

const lint mod = 998244353;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  VV<V<lint>> dp; assign(dp, n + 1, 2 * n + 1, 4);
  dp[1][1][0] = 1;
  dp[1][2][1] = 1;
  dp[1][2][2] = 1;
  dp[1][1][3] = 1;
  for (int i = 1; i < n; i++) for (int j = 0; j < 2 * n + 1; j++) {
    if (dp[i][j][0]) {
      (dp[i + 1][j][0] += dp[i][j][0]) %= mod;
      (dp[i + 1][j + 1][1] += dp[i][j][0]) %= mod;
      (dp[i + 1][j + 1][2] += dp[i][j][0]) %= mod;
      (dp[i + 1][j + 1][3] += dp[i][j][0]) %= mod;
    }
    if (dp[i][j][1]) {
      (dp[i + 1][j][0] += dp[i][j][1]) %= mod;
      (dp[i + 1][j][1] += dp[i][j][1]) %= mod;
      (dp[i + 1][j + 2][2] += dp[i][j][1]) %= mod;
      (dp[i + 1][j][3] += dp[i][j][1]) %= mod;
    }
    if (dp[i][j][2]) {
      (dp[i + 1][j][0] += dp[i][j][2]) %= mod;
      (dp[i + 1][j + 2][1] += dp[i][j][2]) %= mod;
      (dp[i + 1][j][2] += dp[i][j][2]) %= mod;
      (dp[i + 1][j][3] += dp[i][j][2]) %= mod;
    }
    if (dp[i][j][3]) {
      (dp[i + 1][j + 1][0] += dp[i][j][3]) %= mod;
      (dp[i + 1][j + 1][1] += dp[i][j][3]) %= mod;
      (dp[i + 1][j + 1][2] += dp[i][j][3]) %= mod;
      (dp[i + 1][j][3] += dp[i][j][3]) %= mod;
    }
  }
  cout << emod(accumulate(dp[n][k].begin(), dp[n][k].end(), 0LL)) << '\n';
}