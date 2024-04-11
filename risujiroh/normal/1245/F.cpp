#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int l, r; cin >> l >> r;
    lint dp[2][2][2][2];
    fill(dp[0][0][0], dp[2][0][0], 0);
    dp[1][1][1][1] = 1;
    for (int k = 29; k >= 0; --k) {
      int a = l >> k & 1, b = r >> k & 1;
      lint ndp[2][2][2][2];
      fill(ndp[0][0][0], ndp[2][0][0], 0);
      for (int fl : {0, 1}) for (int fr : {0, 1}) for (int gl : {0, 1}) for (int gr : {0, 1}) {
        for (int x : {0, 1}) for (int y : {0, 1}) {
          if (x == 1 and y == 1) continue;
          if (fl and x < a) continue;
          if (fr and x > b) continue;
          if (gl and y < a) continue;
          if (gr and y > b) continue;
          ndp[fl and x == a][fr and x == b][gl and y == a][gr and y == b] += dp[fl][fr][gl][gr];
        }
      }
      swap(dp, ndp);
    }
    lint res = 0;
    for (int fl : {0, 1}) for (int fr : {0, 1}) for (int gl : {0, 1}) for (int gr : {0, 1}) {
      res += dp[fl][fr][gl][gr];
    }
    cout << res << '\n';
  }
}