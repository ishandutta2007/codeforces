#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int h[10][10];
  for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) {
    cin >> h[i][j];
  }
  V< pair<int, int> > ij;
  int ord[10][10];
  {
    int t = 0;
    for (int i = 9; i >= 0; --i) {
      if (i & 1) {
        for (int j = 0; j < 10; ++j) {
          ij.emplace_back(i, j);
          ord[i][j] = t++;
        }
      } else {
        for (int j = 9; j >= 0; --j) {
          ij.emplace_back(i, j);
          ord[i][j] = t++;
        }
      }
    }
  }
  long double dp[100];
  fill(dp, dp + 100, 0);
  for (int t = 98; t >= 0; --t) {
    int i, j;
    tie(i, j) = ij[t];
    long double c = 0;
    for (int d = 1; d <= 6; ++d) {
      if (t + d >= 100) continue;
      c += 1;
      int x, y;
      tie(x, y) = ij[t + d];
      if (h[x][y]) {
        dp[t] += min(dp[t + d], dp[ord[x - h[x][y]][y]]);
      } else {
        dp[t] += dp[t + d];
      }
    }
    dp[t] /= c;
    dp[t] += 6 / c;
  }
  cout << fixed << setprecision(15) << dp[0] << '\n';
}