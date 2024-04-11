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
    int n;
    cin >> n;
    if (n < 31) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      vector<vector<int>> vs{{6, 10, 14}, {6, 10, 15}};
      for (auto&& v : vs) {
        int s = accumulate(begin(v), end(v), 0);
        if (find(begin(v), end(v), n - s) == end(v)) {
          auto res = v;
          res.push_back(n - s);
          sort(begin(res), end(res));
          for (int i = 0; i < 4; ++i) {
            cout << res[i] << " \n"[i == 3];
          }
          break;
        }
      }
    }
  }
}