#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int n = size(s), m = size(t);
  vector<int> cum(n + 1);
  for (int i = n; i--; ) {
    cum[i] = (s[i] == '.') + cum[i + 1];
  }
  vector dp(n + 1, vector(m + 1, -inf<int>));
  dp[0][0] = 0;
  vector<int> last(2 * n + 1, -1);
  int h = n;
  last[h] = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      last[h] = -1;
      --h;
    } else {
      ++h;
    }
    dp[i + 1] = dp[i];
    for (int j = 0; j <= m; ++j) {
      if (s[i] == '.' and last[h] != -1) {
        chmax(dp[i + 1][j], dp[last[h]][j] + 2 * (cum[last[h]] - cum[i + 1]));
      } else if (j and s[i] == t[j - 1]) {
        chmax(dp[i + 1][j], dp[i][j - 1] + 1);
      }
    }
    last[h] = i + 1;
  }
  cout << n - dp[n][m] << '\n';
}