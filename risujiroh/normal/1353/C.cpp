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
    auto res = 0LL;
    for (auto i = 1LL; 2 * i < n; ++i) {
      res += 8 * i * i;
    }
    cout << res << '\n';
  }
}