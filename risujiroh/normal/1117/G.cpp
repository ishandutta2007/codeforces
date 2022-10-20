#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


struct MinSegmentTree {
  using T = int;
  static T op(const T& x, const T& y) { return min(x, y); }
  static constexpr T e() { return 1e9; }

  const int n;
  V<T> t;
  MinSegmentTree(int n, const T& a) : n(n), t(2 * n, a) { build(); }
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T acc(int l, int r) const {
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  void set(int i, const T& x) {
    t[i += n] = x;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};
struct MaxSegmentTree {
  using T = int;
  static T op(const T& x, const T& y) { return max(x, y); }
  static constexpr T e() { return -1e9; }

  const int n;
  V<T> t;
  MaxSegmentTree(int n, const T& a) : n(n), t(2 * n, a) { build(); }
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T acc(int l, int r) const {
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  void set(int i, const T& x) {
    t[i += n] = x;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int n) : n(n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};
template<class T> struct AddSumTree {
  const int n;
  FenwickTree<T> d, e;
  AddSumTree(int n) : n(n), d(n), e(n) {}
  void add(int l, int r, T x) {
    d.add(l, x), e.add(l, l * x);
    if (r < n) d.add(r, -x), e.add(r, -r * x);
  }
  T sum(int i) const { return i * d.sum(i) - e.sum(i); }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  int n, q; scanf("%d%d", &n, &q);
  V<> p(n); for (auto&& e : p) scanf("%d", &e), --e;
  V<> ls(q); for (auto&& e : ls) scanf("%d", &e), --e;
  V<> rs(q); for (auto&& e : rs) scanf("%d", &e), --e;
  struct Q { int id, l, r; };
  VV<Q> ql(n), qr(n);
  V<lint> res(q);
  for (int id = 0; id < q; ++id) {
    ql[rs[id]].emplace_back(Q{id, ls[id], rs[id]});
    qr[ls[id]].emplace_back(Q{id, ls[id], rs[id]});
    res[id] = -(rs[id] - ls[id] + 1);
  }

  V<> il(n);
  MaxSegmentTree mxst(n, -1);
  for (int i = 0; i < n; ++i) {
    il[i] = mxst.acc(p[i], n);
    mxst.set(p[i], i);
  }
  AddSumTree<lint> astl(n);
  for (int i = 0; i < n; ++i) {
    astl.add(il[i] + 1, i + 1, 1);
    for (const auto& e : ql[i]) {
      res[e.id] += astl.sum(e.l, e.r + 1);
    }
  }

  V<> ir(n);
  MinSegmentTree mnst(n, n);
  for (int i = n - 1; i >= 0; --i) {
    ir[i] = mnst.acc(p[i], n);
    mnst.set(p[i], i);
  }
  AddSumTree<lint> astr(n);
  for (int i = n - 1; i >= 0; --i) {
    astr.add(i, ir[i], 1);
    for (const auto& e : qr[i]) {
      res[e.id] += astr.sum(e.l, e.r + 1);
    }
  }

  for (int id = 0; id < q; ++id) {
    if (id) printf(" ");
    printf("%lld", res[id]);
  }
  printf("\n");
}