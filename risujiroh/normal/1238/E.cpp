#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  string s; cin >> s;
  VV<> c(m, V<>(m));
  for (int i = 0; i < n - 1; ++i) {
    ++c[s[i] - 'a'][s[i + 1] - 'a'];
    ++c[s[i + 1] - 'a'][s[i] - 'a'];
  }
  V<> dp(1 << m, 1e9);
  dp[0] = 0;
  for (int S = 0; S < 1 << m; ++S) {
    int t = 0;
    for (int i = 0; i < m; ++i) if (S >> i & 1) {
      for (int j = 0; j < m; ++j) if (~S >> j & 1) {
        t += c[i][j];
      }
    }
    for (int i = 0; i < m; ++i) if (~S >> i & 1) {
      dp[S | 1 << i] = min(dp[S | 1 << i], dp[S] + t);
    }
  }
  cout << dp.back() << '\n';
}