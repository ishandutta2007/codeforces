#include <bits/stdc++.h>
using namespace std;

struct ConvexHullTrick {
  using lint = long long;
  using R = long double;
  static constexpr lint max_x = 2e6; // 
  static constexpr lint inf = numeric_limits<lint>::max();
  struct Line {
    lint a, b = 0;
    R x = 0; // 
    bool operator<(const Line& r) const {
      return a == inf or r.a == inf ? x < r.x : a < r.a;
    }
  };
  set<Line> se;
  bool need(const Line& l, const Line& m, const Line& r) const {
    return (R)m.b * (r.a - l.a) > (R)l.b * (r.a - m.a) + (R)r.b * (m.a - l.a);
  }
  void add(lint a, lint b) {
    auto itr = se.find({a});
    if (itr != end(se)) {
      if (b <= itr->b) return;
      itr = se.erase(itr);
    } else {
      itr = se.lower_bound({a});
      if (itr != begin(se) and itr != end(se) and !need(*prev(itr), {a, b}, *itr)) return;
    }
    if (itr != end(se)) {
      while (next(itr) != end(se) and !need({a, b}, *itr, *next(itr))) {
        itr = se.erase(itr);
      }
    }
    if (itr != begin(se)) {
      while (prev(itr) != begin(se) and !need(*prev(itr, 2), *prev(itr), {a, b})) {
        se.erase(prev(itr));
      }
    }
    R x = max_x;
    if (itr != end(se)) {
      x = -(R)(itr->b - b) / (itr->a - a);
    }
    itr = se.emplace_hint(itr, Line{a, b, x});
    if (itr != begin(se)) {
      auto e = *prev(itr);
      se.erase(prev(itr));
      e.x = -(R)(b - e.b) / (a - e.a);
      se.insert(e);
    }
  }
  lint max(lint x) const {
    // if (se.empty()) return numeric_limits<lint>::min(); // 
    assert(not se.empty());
    auto itr = se.lower_bound({inf, inf, (R)x});
    return itr->a * x + itr->b;
  }
};

// grecsolve
namespace CentroidDecomposition {
  int n;
  vector<vector<int>> g;
  vector<int> sz;
  vector<bool> be;
  void dfs_sz(int v, int p) {
    sz[v] = 1;
    for (int w : g[v]) if (w != p and be[w]) {
      dfs_sz(w, v);
      sz[v] += sz[w];
    }
  }
  int dfs_cent(int v, int p) {
    for (int w : g[v]) if (w != p and be[w] and sz[w] > n / 2) {
      return dfs_cent(w, v);
    }
    return v;
  }
  int find(int v) {
    dfs_sz(v, -1);
    n = sz[v];
    return dfs_cent(v, -1);
  }
  struct s {
    long long l, s, p;
  };
  vector<long long> a;
  vector<s> in, out;
  long long rec(int v) {
    int c = find(v);
    be[c] = false;
    long long res = -1;
    // vector<s> is, os;
    map<int, vector<s>> is, os;
    int nu = -1;
    auto dfs = [&](auto&& self, int v, int p) -> void {
      if (p == c) {
        nu = v;
      }
      is[nu].push_back(in[v]);
      os[nu].push_back(out[v]);
      for (int u : g[v]) {
        if (be[u] and u != p) {
          in[u] = {in[v].l + 1, a[u] + in[v].s, a[u] + in[v].p + in[v].s};
          out[u] = {out[v].l + 1, out[v].s + a[u], out[v].p + (out[v].l + 1) * a[u]};
          self(self, u, v);
        }
      }
    };
    in[c] = {0, 0, 0};
    out[c] = {1, a[c], a[c]};
    dfs(dfs, c, -1);
    {
      ConvexHullTrick cht;
      bool first = true;
      for (auto e : is) {
        if (not exchange(first, false)) {
          for (auto f : e.second) {
            res = max(res, f.p + cht.max(f.l));
          }
        }
        for (auto f : os[e.first]) {
          cht.add(f.s, f.p);
        }
      }
    }
    {
      ConvexHullTrick cht;
      bool first = true;
      // for (auto e : is) {
      for (auto it = rbegin(is); it != rend(is); ++it) {
        auto e = *it;
        if (not exchange(first, false)) {
          for (auto f : e.second) {
            res = max(res, f.p + cht.max(f.l));
          }
        }
        for (auto f : os[e.first]) {
          cht.add(f.s, f.p);
        }
      }
    }
    for (int w : g[c]) if (be[w]) {
      res = max(res, rec(w));
    }
    be[c] = true;
    return res;
  }
  auto solve() {
    n = g.size();
    sz.resize(n);
    be.assign(n, true);
    in.resize(n);
    out.resize(n);
    return rec(0);
  }
}
using namespace CentroidDecomposition;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  g.resize(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  a.resize(n);
  for (auto&& e : a) {
    cin >> e;
  }
  cout << solve() << '\n';
}