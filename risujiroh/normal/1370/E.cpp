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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int h = 0, mn = 0, mx = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    if (s[i] == '0') {
      ++h;
    } else {
      --h;
    }
    mn = min(mn, h);
    mx = max(mx, h);
  }
  if (h) {
    cout << "-1\n";
  } else {
    cout << mx - mn << '\n';
  }
}