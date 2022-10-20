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
    int l, r;
    cin >> l >> r;
    if (2 * l > r) {
      cout << "-1 -1\n";
    } else {
      cout << l << ' ' << 2 * l << '\n';
    }
  }
}