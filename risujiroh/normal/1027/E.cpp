#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

const lint mod = 998244353;
lint emod(lint a) { return (a % mod + mod) % mod; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<lint> a(n + 1), b(n + 1);
  VV<lint> dp; assign(dp, n + 1, n + 1);
  for (int i = 1; i < n + 1; i++) dp[i][0] = dp[i][1] = 1;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n; j++) {
      if (j - i >= 0) dp[i][j + 1] = (2 * dp[i][j] - dp[i][j - i]) % mod;
      else dp[i][j + 1] = 2 * dp[i][j] % mod;
    }
  }
  for (int i = 1; i < n + 1; i++) b[i] = dp[i][n];
  for (int i = 1; i < n + 1; i++) a[i] = (b[i] - b[i - 1]) % mod;
  lint res = 0;
  for (int i = 1; i < n + 1; i++) {
    int j = min((m + i - 1) / i - 1, n);
    res = (res + a[i] * b[j] % mod) % mod;
  }
  cout << emod(2 * res) << '\n';
}