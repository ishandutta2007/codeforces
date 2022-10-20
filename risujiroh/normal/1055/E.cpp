#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct MaxMonoid {
  using T = int;
  static T op(const T& lhs, const T& rhs) { return max(lhs, rhs); }
  static constexpr T e() { return numeric_limits<T>::min(); }
};

template<class Monoid> struct SegmentTree {
  using T = typename Monoid::T;

  const int n;
  V<T> val;

  SegmentTree(int n) : n(n), val(2 * n, Monoid::e()) {}
  template<class Itr> SegmentTree(Itr first, Itr last) : n(distance(first, last)), val(2 * n, Monoid::e()) {
    copy(first, last, next(begin(val), n));
    build();
  }

  void build() {
    for (int i = n - 1; i > 0; --i) val[i] = Monoid::op(val[2 * i], val[2 * i + 1]);
  }

  T get(int l, int r) const {
    T resl = Monoid::e(), resr = Monoid::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = Monoid::op(resl, val[l++]);
      if (r & 1) resr = Monoid::op(val[--r], resr);
    }
    return Monoid::op(resl, resr);
  }

  void set(int i, const T& a) {
    for (val[i += n] = a, i >>= 1; i > 0; i >>= 1) val[i] = Monoid::op(val[2 * i], val[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, s, m, k; cin >> n >> s >> m >> k, --k;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<> l(s), r(s); for (int i = 0; i < s; ++i) cin >> l[i] >> r[i], --l[i];
  VV<> r2l(n + 1);
  for (int i = 0; i < s; ++i) r2l[r[i]].push_back(l[i]);
  int m_ = 0;
  for (auto&& v : r2l) {
    sort(begin(v), end(v));
    if (v.size()) v.resize(1);
    m_ += v.size();
  }
  m = min(m, m_);
  auto chk = [&](int x) {
    VV<> dp; assign(dp, n + 1, m + 1);
    V<> b(n);
    for (int i = 0; i < n; ++i) b[i] = a[i] <= x;
    V<> c(n + 1);
    for (int i = 0; i < n; ++i) c[i + 1] = c[i] + b[i];
    V< SegmentTree<MaxMonoid> > st(m, SegmentTree<MaxMonoid>(n));
    for (int i = 0; i < n; ++i) {
      dp[i + 1] = dp[i];
      for (int j = 0; j < m; ++j) st[j].set(i, dp[i][j] - c[i]);
      for (int j = 0; j < m; ++j) for (int e : r2l[i + 1]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], c[i + 1] + st[j].get(e, i + 1));
      }
    }
    return *max_element(begin(dp[n]), end(dp[n])) > k;
  };
  V<> id(n);
  int ng = -1, ok = 1e9 + 10;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    if (chk(mid)) ok = mid;
    else ng = mid;
  }
  cout << (ok != 1e9 + 10 ? ok : -1) << '\n';
}