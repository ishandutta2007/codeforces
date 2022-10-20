#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  auto f = [](auto x, auto y, auto z) {
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<long long> r(nr), g(ng), b(nb);
    for (auto&& e : r) cin >> e;
    for (auto&& e : g) cin >> e;
    for (auto&& e : b) cin >> e;
    sort(begin(r), end(r));
    sort(begin(g), end(g));
    sort(begin(b), end(b));
    auto res = inf<long long>;
    for (int _ = 2; _--; ) {
      for (auto e : r) {
        auto it = lower_bound(begin(g), end(g), e);
        if (it != end(g)) {
          auto nit = lower_bound(begin(b), end(b), (e + *it + 1) / 2);
          if (nit != end(b)) {
            res = min(res, f(e, *it, *nit));
          }
          nit = upper_bound(begin(b), end(b), (e + *it) / 2);
          if (nit != begin(b)) {
            res = min(res, f(e, *it, *prev(nit)));
          }
        }
        it = upper_bound(begin(g), end(g), e);
        if (it != begin(g)) {
          --it;
          auto nit = lower_bound(begin(b), end(b), (e + *it + 1) / 2);
          if (nit != end(b)) {
            res = min(res, f(e, *it, *nit));
          }
          nit = upper_bound(begin(b), end(b), (e + *it) / 2);
          if (nit != begin(b)) {
            res = min(res, f(e, *it, *prev(nit)));
          }
        }
      }
      swap(g, b);
    }
    cout << res << '\n';
  }
}