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
    int n, m;
    cin >> n >> m;
    if (n & 1 and m & 1) {
      cout << (n * m + 1) / 2 << '\n';
    } else {
      cout << n * m / 2 << '\n';
    }
  }
}