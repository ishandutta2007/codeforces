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
    string s;
    cin >> s;
    int res = 0, t = 0;
    for (char c : s) {
      if (c == '(') {
        ++t;
      } else {
        --t;
      }
      res = max(res, -t);
    }
    cout << res << '\n';
  }
}