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
    vector b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i) {
          ++b[i - 1][j];
        }
        if (i + 1 < n) {
          ++b[i + 1][j];
        }
        if (j) {
          ++b[i][j - 1];
        }
        if (j + 1 < m) {
          ++b[i][j + 1];
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int a;
        cin >> a;
        if (a > b[i][j]) {
          ok = false;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << b[i][j] << " \n"[j == m - 1];
        }
      }
    } else {
      cout << "NO\n";
    }
  }
}