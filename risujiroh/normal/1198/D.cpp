#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<string> s(n); for (auto&& e : s) cin >> e;

  static int dp[51][51][51][51];
  fill(dp[0][0][0], dp[50][0][0], 1e9);

  for (int li = n - 1; li >= 0; --li) for (int ri = li + 1; ri <= n; ++ri) {
    for (int lj = n - 1; lj >= 0; --lj) for (int rj = lj + 1; rj <= n; ++rj) {
      if (ri - li == 1 and rj - lj == 1) {
        dp[li][ri][lj][rj] = s[li][lj] == '#';
        continue;
      }
      dp[li][ri][lj][rj] = max(ri - li, rj - lj);
      for (int i = li + 1; i < ri; ++i) {
        dp[li][ri][lj][rj] = min(dp[li][ri][lj][rj], dp[li][i][lj][rj] + dp[i][ri][lj][rj]);
      }
      for (int j = lj + 1; j < rj; ++j) {
        dp[li][ri][lj][rj] = min(dp[li][ri][lj][rj], dp[li][ri][lj][j] + dp[li][ri][j][rj]);
      }
    }
  }

  cout << dp[0][n][0][n] << '\n';
}