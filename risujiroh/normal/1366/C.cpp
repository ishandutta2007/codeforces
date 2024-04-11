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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto&& v : a) {
      for (auto&& e : v) {
        cin >> e;
      }
    }
    int res = 0;
    for (int k = 0; k < (n + m - 1) / 2; ++k) {
      int x = 0, y = 0;
      for (int i = 0; i < n; ++i) {
        int j = k - i;
        if (0 <= j and j < m) {
          DEBUG(i, j);
          ++(a[i][j] ? x : y);
        }
        j = n + m - 2 - k - i;
        if (0 <= j and j < m) {
          DEBUG(i, j);
          ++(a[i][j] ? x : y);
        }
      }
      DEBUG(k, x, y);
      res += min(x, y);
    }
    cout << res << '\n';
  }
}