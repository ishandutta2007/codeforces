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
    vector<int> a(n);
    int nxt = 1;
    while (find(begin(a), end(a), 0) != end(a)) {
      vector<int> c(n + 1);
      for (int i = n; i--; ) {
        if (a[i] == 0) {
          c[i] = 1 + c[i + 1];
        }
      }
      vector<pair<int, int>> p;
      for (int i = 0; i < n; ++i) {
        if (a[i]) continue;
        if (i == 0 or a[i - 1]) {
          p.emplace_back(c[i], -i);
        }
      }
      sort(rbegin(p), rend(p));
      for (auto [l, i] : p) {
        if (l != p[0].first) break;
        i = -i;
        a[i + (l - 1) / 2] = nxt++;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}