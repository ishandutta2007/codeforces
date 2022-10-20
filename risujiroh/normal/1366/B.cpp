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
    int n, x, m;
    cin >> n >> x >> m;
    int a = x, b = x + 1;
    while (m--) {
      int l, r;
      cin >> l >> r;
      ++r;
      if (r <= a or b <= l) continue;
      a = min(a, l);
      b = max(b, r);
    }
    cout << b - a << '\n';
  }
}