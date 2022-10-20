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
    using ll = long long;
    ll a, b, n;
    cin >> a >> b >> n;
    ll res = 0;
    while (max(a, b) <= n) {
      if (a > b) {
        swap(a, b);
      }
      a += b;
      ++res;
    }
    cout << res << '\n';
  }
}