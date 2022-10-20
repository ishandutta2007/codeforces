#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct sparse_table {
  vector<vector<T>> t;
  sparse_table(const vector<T>& v = {}) : t{v} {
    for (int k = 1, n = size(v); 1 << k <= n; ++k) {
      t.emplace_back(n - (1 << k) + 1);
      for (int i = 0; i + (1 << k) <= n; ++i)
        t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }
  }
  T fold(int l, int r) const {
    assert(l < r);
    int k = __lg(r - l);
    return min(t[k][l], t[k][r - (1 << k)]);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, lim;
    cin >> n >> k >> lim;
    vector<int> d(n);
    for (auto&& e : d) cin >> e;
    if (*max_element(begin(d), end(d)) > lim) {
      cout << "No\n";
      continue;
    }
    vector<int> pos{-1}, _add(n), _sub(n);
    for (int i = 0; i < n; ++i) {
      if (d[i] + k <= lim) {
        pos.push_back(i);
      }
      _add[i] = (lim - d[i]) + i;
      _sub[i] = (lim - d[i]) - i;
    }
    sparse_table add(_add), sub(_sub);
    pos.push_back(n);
    bool ok = true;
    for (int t = 1; t < (int)size(pos); ++t) {
      int l = pos[t - 1] + 1, r = pos[t];
      if (l == r) continue;
      bool any = false;
      for (int i = l; i < r; ++i) {
        if (add.fold(l, i + 1) < i or sub.fold(i, r) < -i) continue;
        any = true;
        break;
      }
      if (not any) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}