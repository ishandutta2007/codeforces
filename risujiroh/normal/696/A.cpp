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
  using ll = long long;
  int q;
  cin >> q;
  map<ll, ll> fee;
  while (q--) {
    int type;
    cin >> type;
    ll u, v;
    cin >> u >> v;
    if (type == 1) {
      int w;
      cin >> w;
      while (u != v) {
        tie(u, v) = minmax({u, v});
        fee[v] += w;
        v >>= 1;
      }
    } else {
      ll res = 0;
      while (u != v) {
        tie(u, v) = minmax({u, v});
        if (fee.count(v)) {
          res += fee[v];
        }
        v >>= 1;
      }
      cout << res << '\n';
    }
  }
}