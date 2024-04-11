#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = size(s);
  vector dp(4, vector<bool>(n));
  dp[2][n - 2] = true;
  dp[3][n - 3] = true;
  vector<string> res;
  for (int i = n; i-- > 5; ) {
    if (i + 2 <= n and not dp[2][i]) {
      dp[2][i] = dp[3][i + 2] or (s.substr(i, 2) != s.substr(i + 2, 2) and dp[2][i + 2]);
    }
    if (i + 3 <= n and not dp[3][i]) {
      dp[3][i] = dp[2][i + 3] or (s.substr(i, 3) != s.substr(i + 3, 3) and dp[3][i + 3]);
    }
    if (dp[2][i]) {
      res.push_back(s.substr(i, 2));
    }
    if (dp[3][i]) {
      res.push_back(s.substr(i, 3));
    }
  }
  sort(begin(res), end(res));
  res.erase(unique(begin(res), end(res)), end(res));
  cout << size(res) << '\n';
  for (auto e : res) {
    cout << e << '\n';
  }
}