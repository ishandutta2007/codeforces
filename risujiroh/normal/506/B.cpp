// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

struct dsu {
  dsu() {}
  explicit dsu(int n) : _cc(n), dat(n, -1) {}

  int size() const { return std::size(dat); }
  int root(int v) {
    assert(0 <= v), assert(v < size());
    return dat[v] < 0 ? v : dat[v] = root(dat[v]);
  }
  std::pair<int, int> unite(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    u = root(u), v = root(v);
    if (u == v) return {u, -1};
    --_cc;
    if (-dat[u] < -dat[v]) std::swap(u, v);
    dat[u] += dat[v];
    dat[v] = u;
    return {u, v};
  }
  bool same(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    return root(u) == root(v);
  }
  int size(int v) {
    assert(0 <= v), assert(v < size());
    return -dat[root(v)];
  }
  int cc() const { return _cc; }

 private:
  int _cc;
  std::vector<int> dat;
};

struct graph {
  struct edge {
    int src, dst;

    int operator-(int v) const {
      assert(v == src or v == dst);
      return src ^ dst ^ v;
    }
  };

  int n, m = 0;
  std::vector<edge> edges;
  std::vector<std::vector<std::pair<int, int>>> adj;
  std::function<bool(int)> ignore = [](int) { return false; };

  graph() : n(0) {}
  explicit graph(int _n) : n(_n), adj(n) {}

  int add(const edge& e, bool directed) {
    assert(0 <= e.src), assert(e.src < n);
    assert(0 <= e.dst), assert(e.dst < n);
    edges.push_back(e);
    adj[e.src].emplace_back(m, e.dst);
    if (not directed) adj[e.dst].emplace_back(m, e.src);
    return m++;
  }
};

struct scc_result {
  std::vector<int> comp_id;
  std::vector<std::vector<int>> components;
  graph dag;

  scc_result(int n) : comp_id(n, -1) {}
};
scc_result find_scc(const graph& g) {
  scc_result res(g.n);
  std::vector<int> in(g.n, -1), min_in(g.n);
  std::stack<int, std::vector<int>> stk;
  int cnt = 0, t = 0;
  auto dfs = [&](auto&& self, int v) -> void {
    in[v] = min_in[v] = t++;
    stk.push(v);
    for (auto [id, u] : g.adj[v]) {
      if (g.ignore(id)) continue;
      if (in[u] == -1) {
        self(self, u);
        min_in[v] = std::min(min_in[v], min_in[u]);
      } else if (res.comp_id[u] == -1) {
        min_in[v] = std::min(min_in[v], in[u]);
      }
    }
    if (min_in[v] == in[v]) {
      while (true) {
        int u = stk.top();
        stk.pop();
        res.comp_id[u] = cnt;
        if (u == v) break;
      }
      ++cnt;
    }
  };
  for (int v = 0; v < g.n; ++v)
    if (in[v] == -1) dfs(dfs, v);
  res.components.resize(cnt);
  for (int v = 0; v < g.n; ++v) {
    res.comp_id[v] = cnt - res.comp_id[v] - 1;
    res.components[res.comp_id[v]].push_back(v);
  }
  std::vector<std::pair<int, int>> es;
  for (int id = 0; id < g.m; ++id) {
    if (g.ignore(id)) continue;
    int src = res.comp_id[g.edges[id].src];
    int dst = res.comp_id[g.edges[id].dst];
    if (src == dst) continue;
    es.emplace_back(src, dst);
  }
  sort(begin(es), end(es));
  es.erase(unique(begin(es), end(es)), end(es));
  res.dag = graph(cnt);
  for (auto [src, dst] : es) res.dag.add({src, dst}, true);
  return res;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  dsu d(n);
  graph g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    d.unite(a, b);
    g.add({a, b}, true);
  }
  auto scc = find_scc(g);
  vector<vector<int>> vs(n);
  for (int v : rep(n)) vs[d.root(v)].push_back(v);
  int ans{};
  for (auto&& e : vs) {
    if (empty(e)) continue;
    vector<int> ids;
    for (int v : e) ids.push_back(scc.comp_id[v]);
    sort(begin(ids), end(ids));
    ids.erase(unique(begin(ids), end(ids)), end(ids));
    ans += size(e) - (size(ids) == size(e));
  }
  cout << ans << '\n';
}