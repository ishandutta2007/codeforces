#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  auto calc = [](string x, int in) {
    int n = x.size();
    VV<V<lint>> dp; assign(dp, n + 1, 2, 5);
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) for (int d = 0; d < 10; d++) {
      dp[i + 1][0][min(j + !!d, 4)] += dp[i][0][j];
      if (d > x[i] - '0') continue;
      dp[i + 1][d == x[i] - '0'][min(j + !!d, 4)] += dp[i][1][j];
    }
    lint res = 0;
    for (int f = 0; f <= in; f++) for (int j = 0; j < 4; j++) res += dp[n][f][j];
    return res;
  };
  int t; cin >> t;
  for (int it = 0; it < t; it++) {
    string l, r; cin >> l >> r;
    cout << calc(r, 1) - calc(l, 0) << '\n';
  }
}