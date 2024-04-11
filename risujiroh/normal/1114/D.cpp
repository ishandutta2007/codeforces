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
  V<> c(n); for (int i = 0; i < n; ++i) cin >> c[i];
  V<> s;
  for (int i = 0; i < n; ++i) {
    if (i == 0 or c[i] != c[i - 1]) {
      s.push_back(c[i]);
    }
  }
  auto t = s;
  reverse(begin(t), end(t));
  n = s.size();
  VV<> dp; assign(dp, n + 1, n + 1, 0);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    dp[i + 1][j + 1] = max({dp[i][j] + (s[i] == t[j]), dp[i + 1][j], dp[i][j + 1]});
  }
  int l = 0;
  for (int i = 0; i < n; ++i) {
    l = max(l, dp[i][n - 1 - i]);
  }
  cout << n - 1 - l << '\n';
}