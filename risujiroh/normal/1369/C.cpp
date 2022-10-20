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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), w(k);
    for (auto&& e : a) cin >> e;
    for (auto&& e : w) cin >> e, --e;
    sort(rbegin(a), rend(a));
    sort(begin(w), end(w));
    auto res = accumulate(begin(a), begin(a) + k, 0LL);
    auto it = begin(a) + k;
    for (int i = 0; i < k; ++i) {
      int e = w[i];
      for (int _ = e; _--; ) {
        ++it;
      }
      if (e) {
        res += *prev(it);
      } else {
        res += a[i];
      }
    }
    cout << res << '\n';
  }
}