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
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b) {
      cout << b << '\n';
    } else {
      a -= b;
      if (c <= d) {
        cout << "-1\n";
      } else {
        c -= d;
        cout << b + (a + c - 1) / c * (c + d) << '\n';
      }
    }
  }
}