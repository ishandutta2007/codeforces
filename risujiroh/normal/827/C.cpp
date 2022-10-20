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
  string s;
  cin >> s;
  int n = size(s);
  vector ft(11, vector(10, vector<fenwick<int>>(4)));
  for (int len = 1; len <= 10; ++len) {
    for (int rem = 0; rem < len; ++rem) {
      for (int k = 0; k < 4; ++k) {
        ft[len][rem][k] = fenwick<int>(n);
        for (int i = rem; i < n; i += len) {
          if (s[i] == "ATGC"[k]) {
            ft[len][rem][k].add(i, 1);
          }
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int i;
      char c;
      cin >> i >> c;
      --i;
      for (int len = 1; len <= 10; ++len) {
        ft[len][i % len][string("ATGC").find(s[i])].add(i, -1);
        ft[len][i % len][string("ATGC").find(c)].add(i, 1);
      }
      s[i] = c;
    } else {
      int l, r;
      string t;
      cin >> l >> r >> t;
      --l;
      int len = size(t), res = 0;
      for (int j = 0; j < len; ++j) {
        res += ft[len][(l + j) % len][string("ATGC").find(t[j])].sum(l, r);
      }
      cout << res << '\n';
    }
  }
}