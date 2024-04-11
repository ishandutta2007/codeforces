#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct fenwick {
  int n;
  vector<T> t;
  fenwick(int _n = -1) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] += a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  int kth(T k) const {
    int i = 0;
    for (int w = 1 << __lg(n); w; w >>= 1)
      if (i + w <= n and t[i + w] <= k) k -= t[i += w];
    return i;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> idx(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    idx[a[i]].push_back(i);
  }
  fenwick<int> ft(n);
  for (auto&& e : idx) {
    if (empty(e)) continue;
    ft.add(e[0], 1);
  }
  vector<vector<int>> ks(n + 1);
  for (int k = 1; k <= n; ++k) {
    ks[0].push_back(k);
  }
  vector<int> res(n + 1);
  for (int i = 0; i < n; ++i) {
    for (int k : ks[i]) {
      ++res[k];
      ks[ft.kth(k)].push_back(k);
    }
    ft.add(i, -1);
    auto it = next(lower_bound(begin(idx[a[i]]), end(idx[a[i]]), i));
    if (it == end(idx[a[i]])) continue;
    ft.add(*it, 1);
  }
  for (int k = 1; k <= n; ++k) {
    cout << res[k] << " \n"[k == n];
  }
}