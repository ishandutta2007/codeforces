#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr lint mod = 998244353;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  V< VV<lint> > dp; assign(dp, 2, 200, 3);
  if (a[0] == -2) for (int j = 0; j < 200; ++j) dp[1][j][1] = 1;
  else dp[1][a[0]][1] = 1;
  for (int i = 1; i < n; ++i) {
    assign(dp[i + 1 & 1], 200, 3, 0LL);
    VV<lint> cum; assign(cum, 3, 201);
    for (int k = 0; k < 3; ++k) for (int j = 0; j < 200; ++j) cum[k][j + 1] = (cum[k][j] + dp[i & 1][j][k]) % mod;
    if (a[i] == -2) {
      for (int j = 0; j < 200; ++j) {
        dp[i + 1 & 1][j][0] = accumulate(begin(dp[i & 1][j]), end(dp[i & 1][j]), 0LL) % mod;
        dp[i + 1 & 1][j][1] = (cum[0][j] + cum[1][j] + cum[2][j]) % mod;
        dp[i + 1 & 1][j][2] = (cum[0][200] - cum[0][j + 1] + cum[2][200] - cum[2][j + 1]) % mod;
      }
    } else {
      dp[i + 1 & 1][a[i]][0] = accumulate(begin(dp[i & 1][a[i]]), end(dp[i & 1][a[i]]), 0LL) % mod;
      dp[i + 1 & 1][a[i]][1] = (cum[0][a[i]] + cum[1][a[i]] + cum[2][a[i]]) % mod;
      dp[i + 1 & 1][a[i]][2] = (cum[0][200] - cum[0][a[i] + 1] + cum[2][200] - cum[2][a[i] + 1]) % mod;
    }
  }
  lint res = 0;
  for (int j = 0; j < 200; ++j) res += dp[n & 1][j][0] + dp[n & 1][j][2];
  cout << emod(res) << '\n';
}