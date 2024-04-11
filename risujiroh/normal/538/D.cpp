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
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto&& e : s) cin >> e;
  vector<string> res(2 * n - 1, string(2 * n - 1, 'x'));
  res[n - 1][n - 1] = 'o';
  for (int si = 0; si < n; ++si) {
    for (int sj = 0; sj < n; ++sj) {
      if (s[si][sj] != 'o') continue;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (s[i][j] != '.') continue;
          res[(n - 1) + (i - si)][(n - 1) + (j - sj)] = '.';
        }
      }
    }
  }
  vector<string> t(n, string(n, '.'));
  for (int si = 0; si < n; ++si) {
    for (int sj = 0; sj < n; ++sj) {
      if (s[si][sj] != 'o') continue;
      t[si][sj] = 'o';
    }
  }
  for (int si = 0; si < n; ++si) {
    for (int sj = 0; sj < n; ++sj) {
      if (s[si][sj] != 'o') continue;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (t[i][j] == '.' and res[(n - 1) + (i - si)][(n - 1) + (j - sj)] == 'x') {
            t[i][j] = 'x';
          }
        }
      }
    }
  }
  if (s == t) {
    cout << "YES\n";
    for (auto e : res) {
      cout << e << '\n';
    }
  } else {
    cout << "NO\n";
  }
}