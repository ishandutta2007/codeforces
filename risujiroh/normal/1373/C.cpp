#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    long long res = size(s);
    int t = 0, mn = 0;
    for (int i = 0; i < (int)size(s); ++i) {
      if (s[i] == '+') {
        ++t;
      } else {
        --t;
      }
      if (chmin(mn, t)) {
        res += i + 1;
      }
    }
    cout << res << '\n';
  }
}