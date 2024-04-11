#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto&& e : a) cin >> e;
    for (auto&& e : b) cin >> e;
    int min_a = *min_element(begin(a), end(a));
    int min_b = *min_element(begin(b), end(b));
    auto res = 0LL;
    for (int i = 0; i < n; ++i) {
      res += max(a[i] - min_a, b[i] - min_b);
    }
    cout << res << '\n';
  }
}