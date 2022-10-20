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
    int n;
    cin >> n;
    int m = __lg(n) + 1;
    vector<int> a(m);
    a[0] = 1;
    n -= m;
    for (int i = 1; i < m; ++i) {
      int t = min(n / (m - i), a[i - 1]);
      n -= t * (m - i);
      a[i] = a[i - 1] + t;
    }
    DEBUG(a);
    cout << m - 1 << '\n';
    for (int i = 1; i < m; ++i) {
      cout << a[i] - a[i - 1] << " \n"[i == m - 1];
    }
  }
}