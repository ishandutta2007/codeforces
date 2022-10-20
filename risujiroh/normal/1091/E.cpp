#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


// 
struct MinMonoid {
  using T = lint;
  static T op(const T& lhs, const T& rhs) { return min(lhs, rhs); }
  static constexpr T e() { return numeric_limits<T>::max(); }
};

// 
template<class Monoid> struct AddMonoidAct {
  using T = lint;
  static void ap(const T& act, typename Monoid::T& val, int len) { val += act; }
  static void cp(const T& lhs, T& rhs) { rhs += lhs; }
  static constexpr T id() { return 0; }
};

template<class Monoid, class MonoidAct> struct SegmentTree {
  using M = Monoid;
  using MA = MonoidAct;
  using Tv = typename M::T;
  using Ta = typename MA::T;

  const int n;

  SegmentTree(int n, const Tv& a = M::e()) :
    n(n), val(2 * n, a), act(n, MA::id()), len(2 * n, 1) {
    build();
    for (int i = n - 1; i > 0; --i) {
      len[i] = len[2 * i] + len[2 * i + 1];
    }
  }
  template<class Itr> SegmentTree(Itr first, Itr last) :
    n(distance(first, last)), val(2 * n, M::e()), act(n, MA::id()), len(2 * n, 1) {
    copy(first, last, next(begin(val), n));
    build();
    for (int i = n - 1; i > 0; --i){
      len[i] = len[2 * i] + len[2 * i + 1];
    }
  }

  void build() {
    for (int i = n - 1; i > 0; --i) {
      val[i] = M::op(val[2 * i], val[2 * i + 1]);
    }
  }

  void push() {
    for (int i = 1; i < n; ++i) push(i);
  }

  Tv get(int l, int r) {
    l = max(l, 0), r = min(r, n);
    if (l >= r) return M::e();
    push(l, r);
    Tv resl = M::e(), resr = M::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = M::op(resl, val[l++]);
      if (r & 1) resr = M::op(val[--r], resr);
    }
    return M::op(resl, resr);
  }
  Tv get(int i) { return get(i, i + 1); }

  void set(int l, int r, const Ta& f) {
    l = max(l, 0), r = min(r, n);
    if (l >= r) return;
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) ap(f, i++);
      if (j & 1) ap(f, --j);
    }
    for (l += n; !(l & 1); l >>= 1);
    while ((l >>= 1) > 0) val[l] = M::op(val[2 * l], val[2 * l + 1]);
    for (r += n; !(r & 1); r >>= 1);
    while ((r >>= 1) > 0) val[r] = M::op(val[2 * r], val[2 * r + 1]);
  }
  void set(int i, const Tv& a) {
    assert(0 <= i and i < n);
    push(i, i + 1);
    for (val[i += n] = a, i >>= 1; i > 0; i >>= 1) {
      val[i] = M::op(val[2 * i], val[2 * i + 1]);
    }
  }

private:
  V<Tv> val;
  V<Ta> act;
  V<> len;

  void ap(const Ta& f, int i) {
    MA::ap(f, val[i], len[i]);
    if (i < n) MA::cp(f, act[i]);
  }

  void push(int i) {
    ap(act[i], 2 * i);
    ap(act[i], 2 * i + 1);
    act[i] = MA::id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = l + n >> hl, ar = r - 1 + n >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
};

using ST = SegmentTree< MinMonoid, AddMonoidAct<MinMonoid> >;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> d(n); for (int i = 0; i < n; ++i) cin >> d[i];
  sort(rbegin(d), rend(d));
  V<lint> a(n + 1);
  for (int i = 0; i < n; ++i) a[i + 1] = a[i] + d[i];
  V<lint> x(n + 1);
  for (lint k = 0; k <= n; ++k) {
    auto itr = lower_bound(begin(d), end(d), k, greater<lint>());
    lint j = max<lint>(distance(begin(d), itr), k);
    x[k] = k * (k - 1) + k * (j - k) + (a[n] - a[j]) - a[k];
  }
  ST st(begin(x), end(x));
  V< pair<int, int> > p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = {d[i], i};
  }
  sort(rbegin(p), rend(p));
  V<> cand;
  for (int i = 0; i <= n; ++i) {
    if (st.get(0, st.n) >= 0) cand.push_back(i);
    if (i == n) break;
    int j = p[i].second;
    st.set(j + 1, st.n, 1);
    st.set(d[j], j + 1, -1);
  }
  lint s = accumulate(begin(d), end(d), 0LL);
  V<> res;
  for (int e : cand) {
    if ((s & 1) == (e & 1)) {
      res.push_back(e);
    }
  }
  int m = res.size();
  if (m) {
    for (int i = 0; i < m; ++i) {
      cout << res[i] << (i != m - 1 ? ' ' : '\n');
    }
  } else {
    cout << -1 << '\n';
  }
}