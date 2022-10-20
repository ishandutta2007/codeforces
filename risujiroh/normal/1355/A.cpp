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
    long long a, k;
    cin >> a >> k;
    --k;
    while (k--) {
      auto s = to_string(a);
      int mn = *min_element(begin(s), end(s)) - '0';
      int mx = *max_element(begin(s), end(s)) - '0';
      if (mn == 0) break;
      a += mn * mx;
    }
    cout << a << '\n';
  }
}