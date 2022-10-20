#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  const string t = "RGB";
  VV<> dp; assign(dp, n + 1, 3, 1e9);
  fill(begin(dp[0]), end(dp[0]), 0);
  VV<int> prev; assign(prev, n + 1, 3, -1);
  for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) {
    for (int k = 0; k < 3; ++k) if (k != j) {
      int curr = dp[i][k] + (s[i] != t[j]);
      if (curr < dp[i + 1][j]) {
        dp[i + 1][j] = curr;
        prev[i + 1][j] = k;
      }
    }
  }
  auto itr = min_element(begin(dp[n]), end(dp[n]));
  cout << *itr << '\n';
  int j = itr - begin(dp[n]);
  string res(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    res[i] = t[j];
    j = prev[i + 1][j];
  }
  cout << res << '\n';
}