#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

namespace LCA {
  using T = pair<lint, lint>;
  struct Edge { int to; T w; };
  T op(const T& x, const T& y) { return {x.first + y.first, x.second + y.second}; }
  constexpr T e = {0, 0};

  V<> dep;
  VV<> par;
  VV<T> val;
  void init(const VV<Edge>& g, int r) {
    int n = g.size();
    dep.resize(n);
    par.assign(__lg(2 * n - 1), V<>(n, -1));
    val.assign(__lg(2 * n - 1), V<T>(n, e));
    auto dfs = [&](const auto& dfs, int v, int p) -> void {
      for (const auto& e : g[v]) if (e.to != p) {
        dep[e.to] = dep[v] + 1;
        par[0][e.to] = v;
        val[0][e.to] = e.w;
        dfs(dfs, e.to, v);
      }
    };
    dep[r] = 0;
    dfs(dfs, r, -1);
    for (int k = 1; k < (int) par.size(); ++k) {
      for (int v = 0; v < n; ++v) {
        if (par[k - 1][v] == -1) continue;
        par[k][v] = par[k - 1][par[k - 1][v]];
        val[k][v] = op(val[k - 1][v], val[k - 1][par[k - 1][v]]);
      }
    }
  }
  int get_par(int v, int h) {
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (v == -1) break;
      if (h & 1) v = par[k][v];
    }
    return v;
  }
  int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = get_par(v, dep[v] - dep[u]);
    if (u == v) return u;
    for (int k = par.size() - 1; k >= 0; --k) {
      if (par[k][u] != par[k][v]) {
        u = par[k][u];
        v = par[k][v];
      }
    }
    return par[0][u];
  }
  T get_val(int v, int h) {
    T res = e;
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (v == -1) break;
      if (h & 1) {
        res = op(res, val[k][v]);
        v = par[k][v];
      }
    }
    return res;
  }
  T acc(int u, int v) {
    int a = lca(u, v);
    return op(get_val(v, dep[v] - dep[a]), get_val(u, dep[u] - dep[a]));
  }
}

template<class T> struct ConvexHullTrick {
  using R = long double;
  struct Line { T a, b; };
  deque<Line> deq;
  bool monotone_query;
  bool need(const Line& l, const Line& m, const Line& r) const {
    return (R)m.b * (r.a - l.a) > (R)l.b * (r.a - m.a) + (R)r.b * (m.a - l.a);
  }
  ConvexHullTrick(bool monotone_query = false) : monotone_query(monotone_query) {}
  void add(T a, T b) {
    if (deq.empty() or a > deq.back().a or a == deq.back().a and b > deq.back().b) {
      while (deq.size() >= 2 and !need(deq[deq.size() - 2], deq.back(), {a, b})) {
        deq.pop_back();
      }
      deq.emplace_back(Line{a, b});
    };
  }
  T max(T x) {
    if (deq.empty()) return numeric_limits<T>::min(); // 
    if (monotone_query) {
      while (deq.size() >= 2 and deq[0].a * x + deq[0].b <= deq[1].a * x + deq[1].b) {
        deq.pop_front();
      }
      return deq[0].a * x + deq[0].b;
    }
    int ok = 0, ng = deq.size();
    while (ng - ok > 1) {
      int m = ok + ng >> 1;
      (deq[m - 1].a * x + deq[m - 1].b <= deq[m].a * x + deq[m].b ? ok : ng) = m;
    }
    return deq[ok].a * x + deq[ok].b;
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  V<> p(n - 1); for (auto&& e : p) cin >> e, --e;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> b(n); for (auto&& e : b) cin >> e;
  VV<LCA::Edge> g(n);
  for (int v = 1; v < n; ++v) {
    g[p[v - 1]].emplace_back(LCA::Edge{v, {a[v], b[v]}});
  }

  V<> in(n), out(n);
  int t = 0;
  auto dfs = [&](auto dfs, int v) -> void {
    in[v] = t++;
    for (const auto& e : g[v]) {
      dfs(dfs, e.to);
    }
    out[v] = t;
  };
  dfs(dfs, 0);

  LCA::init(g, 0);
  V<lint> c(2 * n), d(n);
  for (int v = 0; v < n; ++v) {
    lint sa, sb;
    tie(sa, sb) = LCA::acc(v, 0);
    sa += a[0], sb += b[0];
    c[in[v]] = sb;
    d[in[v]] = sa * sb;
  }
  for (int i = 0; i < n; ++i) c[n + i] = -c[i];

  constexpr int B = 128;
  V< ConvexHullTrick<lint> > cht((n + B - 1) / B, true);
  V<lint> sx((n + B - 1) / B);
  VV<> idx((n + B - 1) / B);
  auto push = [&](int k) -> void {
    for (int i = k * B; i < min((k + 1) * B, n); ++i) {
      d[i] += c[i] * sx[k];
    }
    sx[k] = 0;
  };
  auto build = [&](int k) -> void {
    cht[k] = ConvexHullTrick<lint>(true);
    for (int i : idx[k]) {
      cht[k].add(c[i], i < n ? d[i] : -d[i - n]);
    }
  };
  for (int k = 0; k < (n + B - 1) / B; ++k) {
    for (int i = k * B; i < min((k + 1) * B, n); ++i) {
      idx[k].push_back(i);
      idx[k].push_back(n + i);
    }
    sort(begin(idx[k]), end(idx[k]), [&](int i, int j) { return c[i] < c[j]; });
    build(k);
  }
  auto add = [&](int l, int r, lint x) -> void {
    if (l % B) {
      push(l / B);
      while (l < r and l % B) {
        d[l] += c[l] * x;
        ++l;
      }
      build((l - 1) / B);
    }
    if (r % B) {
      push(r / B);
      while (l < r and r % B) {
        --r;
        d[r] += c[r] * x;
      }
      build(r / B);
    }
    while (l < r) {
      sx[l / B] += x;
      l += B;
    }
  };
  auto acc = [&](int l, int r) -> lint {
    lint res = -9e18;
    if (l % B) {
      push(l / B);
      while (l < r and l % B) {
        res = max(res, abs(d[l]));
        ++l;
      }
      build((l - 1) / B);
    }
    if (r % B) {
      push(r / B);
      while (l < r and r % B) {
        --r;
        res = max(res, abs(d[r]));
      }
      build(r / B);
    }
    while (l < r) {
      res = max(res, cht[l / B].max(sx[l / B]));
      l += B;
    }
    return res;
  };

  while (q--) {
    int tp; cin >> tp;
    if (tp == 1) {
      int v, x; cin >> v >> x, --v;
      add(in[v], out[v], x);
    } else {
      int v; cin >> v, --v;
      lint res = acc(in[v], out[v]);
      cout << res << '\n';
    }
  }
}