#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  VV<> res(10, V<>(10));
  constexpr int inf = 1e9;
  for (int y = 0; y < 10; ++y) for (int x = 0; x <= y; ++x) {
    V<> dp(100, inf);
    dp[0] = 0;
    for (int i = 0; i < 100; ++i) {
      if (i + x < 100) dp[i + x] = min(dp[i + x], dp[i] + 1);
      if (i + y < 100) dp[i + y] = min(dp[i + y], dp[i] + 1);
    }
    dp[0] = x and y ? inf : 1;
    VV<> v(10, V<>(10, inf));
    for (int a = 0; a < 10; ++a) for (int b = 0; b < 10; ++b) {
      for (int i = 0; i < 10; ++i) {
        if (10 * i + b - a < 0) continue;
        v[a][b] = min(v[a][b], dp[10 * i + b - a]);
      }
    }
    int curr = 0;
    for (int i = 0; i < n - 1; ++i) {
      int t = v[s[i] - '0'][s[i + 1] - '0'];
      if (t == inf) {
        curr = -1;
        break;
      }
      curr += t - 1;
    }
    res[x][y] = res[y][x] = curr;
  }
  for (const auto& v : res) for (int i = 0; i < 10; ++i) {
    cout << v[i] << " \n"[i == 9];
  }
}