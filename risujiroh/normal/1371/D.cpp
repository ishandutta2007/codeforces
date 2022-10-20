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
    int n, k;
    cin >> n >> k;
    cout << 2 * !!(k % n) << '\n';
    vector<string> res(n, string(n, '0'));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (k-- > 0) {
          res[(i + j) % n][j] = '1';
        }
      }
    }
    for (auto e : res) {
      cout << e << '\n';
    }
  }
}