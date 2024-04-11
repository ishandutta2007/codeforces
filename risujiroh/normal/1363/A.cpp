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
    int n, x;
    cin >> n >> x;
    int odd = 0;
    for (int _ = n; _--; ) {
      int a;
      cin >> a;
      odd += a & 1;
    }
    bool ok = false;
    for (int i = 1; i <= x; i += 2) {
      int j = x - i;
      if (i <= odd and j <= n - odd) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}