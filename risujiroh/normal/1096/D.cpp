#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  const string t = "hard";
  VV<lint> dp; assign(dp, 5, n + 1, 0);
  for (int i = 0; i < n; ++i) {
    dp[1][i + 1] = dp[1][i] + (s[i] == 'h' ? a[i] : 0);
  }
  for (int j = 1; j < 4; ++j) {
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[j]) {
        dp[j + 1][i + 1] = dp[j + 1][i];
      } else {
        dp[j + 1][i + 1] = min(dp[j + 1][i] + a[i], dp[j][i]);
      }
    }
  }
  cout << dp[4][n] << '\n';
}