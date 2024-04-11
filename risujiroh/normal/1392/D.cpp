#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

constexpr int inf = 0x3f3f3f3f;

int dp[2][2][2][2];
int ndp[2][2][2][2];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto cost = [&](int i, int v) { return s[i] != "LR"[v]; };
    for (int a : {0, 1})
      for (int b : {0, 1})
        for (int c : {0, 1})
          for (int d : {0, 1}) dp[a][b][c][d] = inf;
    for (int a : {0, 1})
      for (int b : {0, 1}) {
        dp[a][b][a][b] = cost(0, a) + cost(1, b);
      }
    for (int i = 2; i < n; ++i) {
      for (int a : {0, 1})
        for (int b : {0, 1})
          for (int c : {0, 1})
            for (int d : {0, 1}) ndp[a][b][c][d] = inf;
      for (int a : {0, 1})
        for (int b : {0, 1})
          for (int c : {0, 1})
            for (int d : {0, 1}) {
              for (int e : {0, 1}) {
                if (c == d and d == e) continue;
                ndp[a][b][d][e] =
                    min(ndp[a][b][d][e], dp[a][b][c][d] + cost(i, e));
              }
            }
      swap(dp, ndp);
    }
    int res = inf;
    for (int a : {0, 1})
      for (int b : {0, 1})
        for (int c : {0, 1})
          for (int d : {0, 1}) {
            if (c == d and d == a) continue;
            if (d == a and a == b) continue;
            res = min(res, dp[a][b][c][d]);
          }
    cout << res << '\n';
  }
}