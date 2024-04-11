#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    vector<int> cc(30);
    for (int i = 0; i < r - l + 1; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 30; j++) {
        cc[j] += (x >> j) & 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < 30; i++) {
      if (cc[i] > (r - l + 1) - cc[i]) {
        ans += (1 << i);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}