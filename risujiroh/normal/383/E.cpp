#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> void fzt(vector<T>& a) {
  int n = __lg(a.size());
  assert((int)a.size() == 1 << n);
  for (int i = 0; i < n; ++i)
    for (int bt = 0; bt < 1 << n; ++bt)
      if (bt >> i & 1) {
        a[bt] += a[bt ^ 1 << i];
      }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  constexpr int n = 24;
  vector<vector<int>> dp(4);
  for (int c = 1; c <= 3; ++c) {
    dp[c].resize(1 << n);
  }
  int m;
  cin >> m;
  while (m--) {
    string s;
    cin >> s;
    sort(begin(s), end(s));
    s.erase(unique(begin(s), end(s)), end(s));
    for (int x = 1; x < 1 << size(s); ++x) {
      int bt = 0;
      for (int i = 0; i < (int)size(s); ++i) {
        if (~x >> i & 1) continue;
        bt |= 1 << (s[i] - 'a');
      }
      ++dp[__builtin_popcount(x)][bt];
    }
  }
  for (int c = 1; c <= 3; ++c) {
    fzt(dp[c]);
  }
  int res = 0;
  for (int bt = 0; bt < 1 << n; ++bt) {
    int cur = dp[1][bt] - dp[2][bt] + dp[3][bt];
    res ^= cur * cur;
  }
  cout << res << '\n';
}