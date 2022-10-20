#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> c(n), s(n);
  for (int i = 0; i < n; i++) {
    string st;
    cin >> c[i] >> st;
    int t = 0;
    for (char ch : st) t += 1 << ch - 'A';
    s[i] = t;
  }
  const int inf = 2e9;
  VV<> dp; assign(dp, n + 1, 8, inf);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = dp[i];
    for (int bit = 0; bit < 8; bit++) {
      dp[i + 1][bit | s[i]] = min({dp[i + 1][bit | s[i]], dp[i][bit | s[i]], dp[i][bit] + c[i]});
    }
  }
  cout << (dp[n][7] != inf ? dp[n][7] : -1) << '\n';
}