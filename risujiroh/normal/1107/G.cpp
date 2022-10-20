#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct UnionFind {
  const int n;

  UnionFind(int n) : n(n), dat(n, -1) {}

  bool same(int u, int v) {
    assert(0 <= u and u < n);
    assert(0 <= v and v < n);
    return find(u) == find(v);
  }

  int size(int v) {
    assert(0 <= v and v < n);
    return -dat[find(v)];
  }

  void unite(int u, int v) {
    assert(0 <= u and u < n);
    assert(0 <= v and v < n);
    if ((u = find(u)) == (v = find(v))) return;
    if (-dat[u] < -dat[v]) {
      dat[v] += dat[u];
      dat[u] = v;
    } else {
      dat[u] += dat[v];
      dat[v] = u;
    }
  }

private:
  V<> dat; // dat[v] := v ? -size : parent

  int find(int v) {
    return dat[v] < 0 ? v : dat[v] = find(dat[v]);
  }
};

struct MinMaxMonoid {
  using T = pair<lint, lint>;
  static T op(const T& lhs, const T& rhs) { return {min(lhs.first, rhs.first), max(lhs.second, rhs.second)}; }
  static constexpr T e() { return {numeric_limits<lint>::max(), numeric_limits<lint>::min()}; }
};

template<class Monoid> struct SegmentTree {
  using M = Monoid;
  using T = typename M::T;

  const int n;

  SegmentTree(int n, const T& a = M::e()) : n(n), val(2 * n, a) {
    build();
  }

  template<class Itr> SegmentTree(Itr first, Itr last) :
    n(distance(first, last)), val(2 * n, M::e()) {
    copy(first, last, next(begin(val), n));
    build();
  }

  T& operator[](int i) {
    assert(0 <= i and i < n);
    return val[i + n];
  }

  void build() {
    for (int i = n - 1; i > 0; --i) {
      val[i] = M::op(val[2 * i], val[2 * i + 1]);
    }
  }

  T get(int l, int r) const {
    l = max(l, 0), r = min(r, n);
    T resl = M::e(), resr = M::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = M::op(resl, val[l++]);
      if (r & 1) resr = M::op(val[--r], resr);
    }
    return M::op(resl, resr);
  }

  void set(int i, const T& a) {
    assert(0 <= i and i < n);
    for (val[i += n] = a, i >>= 1; i > 0; i >>= 1) {
      val[i] = M::op(val[2 * i], val[2 * i + 1]);
    }
  }

private:
  V<T> val;
};

using ST = SegmentTree<MinMaxMonoid>;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, a; cin >> n >> a;
  V<> d(n), c(n); for (int i = 0; i < n; ++i) cin >> d[i] >> c[i], c[i] = a - c[i];
  ST st(n + 1);
  st[0] = {0, 0};
  for (int i = 0; i < n; ++i) {
    st[i + 1] = {st[i].first + c[i], st[i].second + c[i]};
  }
  st.build();
  V<> id(n - 1);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) { return d[i + 1] - d[i] < d[j + 1] - d[j]; });
  UnionFind uf(n);
  lint res = 0;
  res = max<lint>(res, *max_element(begin(c), end(c)));
  for (int i : id) {
    int l = i - uf.size(i) + 1;
    int r = i + uf.size(i + 1);
    lint curr = st.get(i + 2, r + 2).second - st.get(l, i + 1).first;
    curr -= (lint) (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
    uf.unite(i, i + 1);
    res = max(res, curr);
  }
  cout << res << '\n';
}