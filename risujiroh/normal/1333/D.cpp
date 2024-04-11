#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct segtree {
  const int n;
  vector<T> t;
  segtree(int _n = 0) : n(_n), t(2 * n) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = t[2 * i] * t[2 * i + 1]; }
  T fold(int l, int r) const {
    T a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = a * t[l++];
      if (r & 1) b = t[--r] * b;
    }
    return a * b;
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = t[2 * i] * t[2 * i + 1];
  }
};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

template <class T> struct minimum {
  T v = inf<T>;
  int i = -1;
  minimum operator*(minimum b) const {
    return b.v < v ? b : *this;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int a = count(begin(s), end(s), 'L');
  vector<int> g(n + 1), c(n + 1);
  for (int i = 0; i < n; ++i) {
    g[i + 1] = g[i] + (i < a ? 1 : -1);
    c[i + 1] = c[i] + (s[i] == 'L' ? 1 : -1);
  }
  DEBUG(g);
  DEBUG(c);
  segtree<minimum<int>> seg(n + 1);
  for (int i = 1; i < n; ++i) {
    if (c[i] < g[i]) {
      seg[i] = {c[i], i};
    }
  }
  seg.build();
  map<int, vector<int>> mp;
  int cnt = 0;
  while (true) {
    auto x = seg.fold(1, n);
    if (x.v == inf<int>) {
      break;
    }
    mp[x.v].push_back(x.i);
    x.v += 2;
    if (x.v == g[x.i]) {
      x.v = inf<int>;
    }
    seg.set(x.i, x);
    ++cnt;
  }
  DEBUG(mp);
  DEBUG(cnt);
  if (k < (int)size(mp) or k > cnt) {
    cout << "-1\n";
    exit(0);
  }
  vector<vector<int>> res(k);
  int cur = size(mp), ptr = 0;
  for (auto&& [h, v] : mp) {
    int sz = size(v);
    for (int t = 0; t < sz; ++t) {
      res[ptr].push_back(v[t]);
      if (t < sz - 1 and cur < k) {
        ++ptr;
        ++cur;
      }
    }
    ++ptr;
  }
  for (auto&& v : res) {
    int sz = size(v);
    cout << sz;
    for (int i : v) {
      cout << ' ' << i;
    }
    cout << '\n';
  }
}