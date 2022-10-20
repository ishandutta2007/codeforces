#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct SegmentTree {
  using T = lint;
  static T op(const T& x, const T& y) { return min(x, y); }
  static constexpr T e() { return 1e18; }
  using U = lint;
  static void ap(const U& f, T& x) { x += f; }
  static void cp(const U& g, U& f) { f += g; }
  static constexpr U id() { return 0; }

  const int n;
  V<T> t;
  V<U> u;
  SegmentTree(int n) : n(n), t(2 * n, e()), u(n, id()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  void push() { for (int i = 1; i < n; ++i) push(i); }
  void apply(const U& f, int i) {
    ap(f, t[i]);
    if (i < n) cp(f, u[i]);
  }
  void push(int i) {
    if (u[i] == id()) return;
    apply(u[i], 2 * i);
    apply(u[i], 2 * i + 1);
    u[i] = id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = l + n >> hl, ar = r - 1 + n >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
  T acc(int l, int r) {
    push(l, r);
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  T get(int i) { return acc(i, i + 1); }
  void act(int l, int r, const U& f) {
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(f, i++);
      if (j & 1) apply(f, --j);
    }
    l = l + n >> __builtin_ctz(l + n);
    while (l >>= 1) t[l] = op(t[2 * l], t[2 * l + 1]);
    r = r + n >> __builtin_ctz(r + n);
    while (r >>= 1) t[r] = op(t[2 * r], t[2 * r + 1]);
  }
  void set(int i, const T& x) {
    push(i, i + 1);
    t[i += n] = x;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  struct Edge { int to, d; };
  VV<Edge> g(n);
  for (int v = 1; v < n; ++v) {
    int p, d; cin >> p >> d, --p;
    g[p].emplace_back(Edge{v, d});
  }
  struct Query { int id, l, r; };
  VV<Query> qs(n);
  for (int i = 0; i < q; ++i) {
    int v, l, r; cin >> v >> l >> r, --v, --l;
    qs[v].emplace_back(Query{i, l, r});
  }

  V<lint> dist(n);
  V<> sz(n, 1);
  auto dfs0 = [&](const auto& dfs0, int v) -> void {
    for (const auto& e : g[v]) {
      dist[e.to] = dist[v] + e.d;
      dfs0(dfs0, e.to);
      sz[v] += sz[e.to];
    }
  };
  dfs0(dfs0, 0);
  
  SegmentTree st(n);
  for (int v = 0; v < n; ++v) if (sz[v] == 1) {
    st[v] = dist[v];
  }
  st.build();

  V<lint> res(q);
  lint o = 0;
  auto dfs = [&](const auto& dfs, int v) -> void {
    for (const auto& qry : qs[v]) {
      res[qry.id] = o + st.acc(qry.l, qry.r);
    }
    for (const auto& e : g[v]) {
      o += e.d;
      st.act(e.to, e.to + sz[e.to], -2 * e.d);
      dfs(dfs, e.to);
      o -= e.d;
      st.act(e.to, e.to + sz[e.to], 2 * e.d);
    }
  };
  dfs(dfs, 0);
  for (lint e : res) {
    cout << e << '\n';
  }
}