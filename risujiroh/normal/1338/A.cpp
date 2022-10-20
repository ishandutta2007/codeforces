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
    int n;
    cin >> n;
    int d = 0, mx = -inf<int>;
    while (n--) {
      int a;
      cin >> a;
      d = max(d, mx - a);
      mx = max(mx, a);
    }
    cout << (d ? __lg(d) + 1 : 0) << '\n';
  }
}