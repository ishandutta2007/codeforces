#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct range_add {
  static constexpr T inf = numeric_limits<T>::max() / 2;
  struct node { T delta = 0, min = inf, max = -inf, len = 0, sum = 0; };
  static node op(const node& l, const node& r) {
    return {
      l.delta + r.delta,
      std::min(l.min, l.delta + r.min), std::max(l.max, l.delta + r.max),
      l.len + r.len, l.sum + l.delta * r.len + r.sum
    };
  }
  static node make_node(T a) { return {a, a, a, 1, a}; }
  const int n;
  vector<node> t;
  range_add(const vector<T>& v) : n(v.size() + 1), t(2 * n) {
    for (int i = n - 1; i--; ) t[n + i] = make_node(v[i] - (i ? v[i - 1] : 0));
    for (int i = n; i-- > 1; ) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
  node fold(int l, int r) const {
    node a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = op(a, t[l++]);
      if (r & 1) b = op(t[--r], b);
    }
    return op(a, b);
  }
  T get(int i) const { return fold(0, i + 1).delta; }
  T min(int l, int r) const { return get(l - 1) + fold(l, r).min; }
  T max(int l, int r) const { return get(l - 1) + fold(l, r).max; }
  T sum(int l, int r) const { return get(l - 1) * (r - l) + fold(l, r).sum; }
  void set(int i, const node& a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
  void add(int l, int r, T a) {
    set(l, make_node(t[n + l].delta + a));
    set(r, make_node(t[n + r].delta - a));
  }
};

auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> l(n), r(n), t(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i] >> t[i];
    --t[i];
  }
  vector<int> v{0};
  v.insert(end(v), begin(l), end(l));
  v.insert(end(v), begin(r), end(r));
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
  int m = size(v);
  for (auto&& e : l) e = lower_bound(begin(v), end(v), e) - begin(v);
  for (auto&& e : r) e = lower_bound(begin(v), end(v), e) - begin(v);
  vector<vector<int>> idx(m);
  for (int i = 0; i < n; ++i) {
    idx[r[i]].push_back(i);
  }
  vector dp(2, vector<int>(m));
  vector<range_add<int>> ra(2, vector<int>(m, 0));
  for (int j = 1; j < m; ++j) {
    chmax(dp[0][j], dp[0][j - 1]);
    chmax(dp[1][j], dp[1][j - 1]);
    for (int i : idx[j]) {
      ra[t[i] ^ 1].add(0, l[i], 1);
    }
    chmax(dp[0][j], ra[1].max(0, j));
    chmax(dp[1][j], ra[0].max(0, j));
    ra[0].add(j, j + 1, dp[0][j]);
    ra[1].add(j, j + 1, dp[1][j]);
  }
  cout << max(dp[0].back(), dp[1].back()) << '\n';
}