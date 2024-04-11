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
    long long n, r;
    cin >> n >> r;
    r = min(r, n);
    if (r < n) {
      cout << r * (r + 1) / 2 << '\n';
    } else {
      cout << r * (r - 1) / 2 + 1 << '\n';
    }
  }
}