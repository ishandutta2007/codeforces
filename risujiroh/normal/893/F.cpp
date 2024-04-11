#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct Sparse2DSegmentTree {
  using T = int;
  static T op(const T& a, const T& b) { return min(a, b); }
  static constexpr T e() { return 1 << 30; }

  struct SegmentTree {
    const int n;
    V<T> t;
    SegmentTree(int n) : n(n), t(2 * n, e()) {}
    T& operator[](int i) { return t[i + n]; }
    void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
    T acc(int l, int r) const {
      T res = e();
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = op(res, t[l++]);
        if (r & 1) res = op(res, t[--r]);
      }
      return res;
    }
    void set(int i, const T& a) {
      t[i += n] = a;
      while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
    }
  };
  const int n;
  V<SegmentTree> st;
  VV<> ys;
  Sparse2DSegmentTree(int n) : n(n), ys(2 * n) {}
  void preset(int x, int y) {
    for (x += n; x; x >>= 1) ys[x].push_back(y);
  }
  void build() {
    for (auto&& v : ys) {
      sort(begin(v), end(v));
      v.erase(unique(begin(v), end(v)), end(v));
      st.emplace_back(v.size());
    }
  }
  int zip(int x, int y) const { return lower_bound(begin(ys[x]), end(ys[x]), y) - begin(ys[x]); }
  T acc(int x0, int x1, int y0, int y1) const {
    T res = e();
    for (x0 += n, x1 += n; x0 < x1; x0 >>= 1, x1 >>= 1) {
      if (x0 & 1) res = op(res, st[x0].acc(zip(x0, y0), zip(x0, y1))), ++x0;
      if (x1 & 1) --x1, res = op(res, st[x1].acc(zip(x1, y0), zip(x1, y1)));
    }
    return res;
  }
  void set(int x, int y, const T& a) {
    for (x += n; x; x >>= 1) st[x].set(zip(x, y), op(st[x][zip(x, y)], a));
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, r; cin >> n >> r, --r;
  V<> a(n); for (auto&& e : a) cin >> e;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  V<> d(n), in(n), out(n);
  int t = 0;
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    in[v] = t++;
    for (int w : g[v]) if (w != p) {
      d[w] = d[v] + 1;
      dfs(dfs, w, v);
    }
    out[v] = t;
  };
  dfs(dfs, r, -1);

  Sparse2DSegmentTree st(n);
  for (int v = 0; v < n; ++v) {
    st.preset(in[v], d[v]);
  }
  st.build();
  for (int v = 0; v < n; ++v) {
    st.set(in[v], d[v], a[v]);
  }

  int m; cin >> m;
  int res = 0;
  while (m--) {
    int p, q; cin >> p >> q;
    int v = (p + res) % n, k = (q + res) % n + 1;
    res = st.acc(in[v], out[v], d[v], d[v] + k);
    cout << res << '\n';
  }
}