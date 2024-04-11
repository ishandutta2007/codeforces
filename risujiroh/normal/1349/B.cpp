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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    if (find(begin(a), end(a), k) == end(a)) {
      cout << "no\n";
      continue;
    }
    if (n == 1) {
      cout << "yes\n";
      continue;
    }
    vector<int> cum(n + 1);
    for (int i = n; i--; ) {
      cum[i] = (a[i] >= k ? +1 : -1) + cum[i + 1];
    }
    int mn = inf<int>;
    bool ok = false;
    for (int i = n - 2; i >= 0; --i) {
      mn = min(mn, cum[i + 2]);
      if (cum[i] - mn > 0) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "yes\n" : "no\n");
  }
}