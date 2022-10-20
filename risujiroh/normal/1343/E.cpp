#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct graph {
  struct edge {
    int from, to;
    T w;
  };
  const int n;
  vector<edge> edges;
  vector<int> head;
  graph(int _n = 0) : n(_n), head(n + 1) {}
  void add(int from, int to, T w = 1) {
    edges.push_back({from, to, w}), ++head[from];
  }
  void build() {
    partial_sum(begin(head), end(head), begin(head));
    for (auto&& e : vector<edge>(edges)) edges[--head[e.from]] = e;
  }
  template <class F> void for_each_edge(int from, F f) const {
    for (int i = head[from]; i < head[from + 1]; ++i) f(edges[i]);
  }
};

template <class Key, class T> struct radix_heap {
  static_assert(is_integral<Key>::value, "");
  array<vector<pair<Key, T>>, sizeof(Key) * 8 + 1> v;
  Key last = 0;
  size_t sz = 0, ptr = 0;
  static int lg(Key a) { return a ? __lg(a) : -1; }
  void emplace(Key key, T val) {
    assert(key >= last);
    v[lg(key ^ last) + 1].emplace_back(key, val);
    ++sz;
  }
  void pull() {
    if (ptr < v[0].size()) return;
    v[0].clear(), ptr = 0;
    int i = 1;
    while (v[i].empty()) ++i;
    last = min_element(begin(v[i]), end(v[i]), [](auto a, auto b) {
      return a.first < b.first;
    })->first;
    for (auto e : v[i]) v[lg(e.first ^ last) + 1].push_back(e);
    v[i].clear();
  }
  pair<Key, T> top() { return pull(), v[0][ptr]; }
  void pop() { pull(), --sz, ++ptr; }
  bool empty() const { return sz == 0; }
};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

template <class T> vector<T> dijkstra(const graph<T>& g, int s) {
  vector<T> d(g.n, inf<T>);
  radix_heap<T, int> rh;
  rh.emplace(d[s] = 0, s);
  while (not rh.empty()) {
    T dv;
    int v;
    tie(dv, v) = rh.top(), rh.pop();
    if (dv != d[v]) continue;
    g.for_each_edge(v, [&](auto&& e) {
      if (chmin(d[e.to], dv + e.w)) rh.emplace(d[e.to], e.to);
    });
  }
  return d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    vector<int> p(m);
    for (auto&& e : p) {
      cin >> e;
    }
    sort(begin(p), end(p));
    graph<int> g(n);
    for (int _ = m; _--; ) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g.add(u, v);
      g.add(v, u);
    }
    g.build();
    auto da = dijkstra(g, a);
    auto db = dijkstra(g, b);
    auto dc = dijkstra(g, c);
    vector<long long> cum(m + 1);
    for (int i = m; i--; ) {
      cum[i] = p[i] + cum[i + 1];
    }
    auto res = inf<long long>;
    for (int x = 0; x < n; ++x) {
      if (da[x] + db[x] + dc[x] > m) {
        continue;
      }
      auto cur = 2 * (cum[0] - cum[db[x]]);
      cur += cum[db[x]] - cum[db[x] + da[x] + dc[x]];
      chmin(res, cur);
    }
    cout << res << '\n';
  }
}