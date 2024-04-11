#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

using ll = long long;
int f(ll s, ll e, int g) {
  if (g) {
    if (e / 2 < s) {
      return (e - s) & 1;
    } else {
      if (~e & 1 or e / 2 & 1) {
        return f(s, e / 2, e & 1);
      } else {
        if (s == e / 2) {
          return 1;
        } else {
          return f(s, e / 2 - 1, 1);
        }
      }
    }
  } else {
    if (e / 2 < s) {
      return 1;
    } else {
      return f(s, e / 2, 1);
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> s(n), e(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> e[i];
  }
  for (int gg : {1, 0}) {
    int g = gg;
    for (int i = n; i--; ) {
      g = !f(s[i], e[i], g);
    }
    cout << !g << "\n "[gg];
  }
}