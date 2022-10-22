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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int x = (int) (min_element(a.begin(), a.end()) - a.begin());
    if (a[x] == 1) {
      int p = 1;
      bool ok = true;
      for (int i = 1; i < n; i++) {
        x = (x + 1) % n;
        if (a[x] < 2 || a[x] > p + 1) {
          ok = false;
          break;
        }
        p = a[x];
      }
      cout << (ok ? "YES" : "NO") << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}