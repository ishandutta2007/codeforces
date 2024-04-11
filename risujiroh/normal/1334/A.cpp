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
    vector<int> p(n), c(n);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      cin >> p[i] >> c[i];
      int dp = p[i] - (i ? p[i - 1] : 0);
      int dc = c[i] - (i ? c[i - 1] : 0);
      if (dp < 0 or dc < 0 or dp < dc) {
        ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}