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
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  int res = 0;
  for (int m = -30; m <= 30; ++m) {
    int mn = 0, cum = 0;
    for (auto e : a) {
      if (e > m) {
        mn = cum = 0;
      } else {
        cum += e;
        res = max(res, cum - mn - m);
        mn = min(mn, cum);
      }
    }
  }
  cout << res << '\n';
}