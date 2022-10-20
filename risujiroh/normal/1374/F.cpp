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
    vector<pair<int, int>> a(n);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
      v.push_back(a[i].first);
    }
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    int invs = 0;
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < j; ++i) {
        invs += a[i] > a[j];
      }
    }
    if ((int)size(v) == n and invs & 1) {
      cout << "-1\n";
      continue;
    }
    if (invs & 1) {
      [&] {
        for (int j = 0; j < n; ++j) {
          for (int i = 0; i < j; ++i) {
            if (a[i].first == a[j].first) {
              swap(a[i], a[j]);
              return;
            }
          }
        }
      }();
    }
    vector<int> res;
    for (int l = 0; l < n - 2; ++l) {
      int mi = min_element(begin(a) + l, end(a)) - begin(a);
      while (mi >= l + 2) {
        res.push_back(mi - 1);
        swap(a[mi - 1], a[mi]);
        swap(a[mi - 2], a[mi - 1]);
        mi -= 2;
      }
      if (mi != l) {
        assert(mi == l + 1);
        for (int _ = 2; _--; ) {
          res.push_back(l + 1);
          swap(a[l + 1], a[l + 2]);
          swap(a[l], a[l + 1]);
        }
      }
    }
    int m = size(res);
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << res[i] << " \n"[i == m - 1];
    }
  }
}