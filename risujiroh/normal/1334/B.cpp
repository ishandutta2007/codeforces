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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    sort(rbegin(a), rend(a));
    vector<long long> c(n + 1);
    for (int i = 0; i < n; ++i) {
      c[i + 1] = c[i] + a[i];
    }
    for (int m = n; m >= 0; --m) {
      if (c[m] >= (long long)x * m) {
        cout << m << '\n';
        break;
      }
    }
  }
}