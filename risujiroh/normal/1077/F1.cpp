#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct MaxMonoid {
  using T = lint;
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

  T& operator[](int i) { return val[i + n]; }

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
  int n, k, x; cin >> n >> k >> x;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  if (x < n / k) return cout << -1 << '\n', 0;
  V< SegmentTree<MaxMonoid> > dp(2, SegmentTree<MaxMonoid>(n + 1));
  dp[0].set(0, 0);
  for (int j = 0; j < x; ++j) {
    for (int i = 0; i < n; ++i) dp[j + 1 & 1][i + 1] = a[i] + dp[j & 1].get(max(i - k + 1, 0), i + 1);
    dp[j + 1 & 1].build();
  }
  cout << dp[x & 1].get(n - k + 1, n + 1) << '\n';
}