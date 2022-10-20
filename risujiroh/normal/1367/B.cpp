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
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (i % 2 == 0 and a % 2 == 1) {
        ++x;
      }
      if (i % 2 == 1 and a % 2 == 0) {
        ++y;
      }
    }
    if (x != y) {
      cout << "-1\n";
    } else {
      cout << x << '\n';
    }
  }
}