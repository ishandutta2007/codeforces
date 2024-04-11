#include <bits/stdc++.h>

struct Graph {
  struct Edge {
    int src, dst;
    int64_t cost;

    int other(int v) const {
      assert(v == src or v == dst);
      return src ^ dst ^ v;
    }
  };

  std::vector<Edge> edges;
  std::vector<std::vector<std::pair<int, int>>> adj;

  Graph() {}
  explicit Graph(int n) : adj(n) {}

  int n() const { return std::size(adj); }
  int m() const { return std::size(edges); }

  int add_edge(const Edge& e, bool directed) {
    assert(0 <= e.src), assert(e.src < n());
    assert(0 <= e.dst), assert(e.dst < n());
    int id = m();
    edges.push_back(e);
    adj[e.src].emplace_back(e.dst, id);
    if (not directed) adj[e.dst].emplace_back(e.src, id);
    return id;
  }
};

struct DfsTree : Graph {
  using T = decltype(Edge::cost);

  std::vector<int> root;
  std::vector<int> pv;
  std::vector<int> pe;
  std::vector<int> order;
  std::vector<int> in;
  std::vector<int> out;
  std::vector<int> sz;
  std::vector<int> depth;
  std::vector<int> min_depth;
  std::vector<T> dist;
  std::vector<int> last;
  int num_trials;

  DfsTree() {}
  explicit DfsTree(int n)
      : Graph(n),
        root(n, -1),
        pv(n, -1),
        pe(n, -1),
        in(n, -1),
        out(n, -1),
        sz(n, -1),
        depth(n, -1),
        min_depth(n, -1),
        dist(n, std::numeric_limits<T>::max()),
        last(n, -1),
        num_trials(0) {}

  int add_edge(const Edge& e) { return Graph::add_edge(e, false); }

  void dfs(int r, bool clear_order = true) {
    assert(0 <= r), assert(r < n());
    root[r] = r;
    pv[r] = -1;
    pe[r] = -1;
    if (clear_order) order.clear();
    depth[r] = 0;
    dist[r] = T{};
    dfs_impl(r);
    ++num_trials;
  }
  void dfs_all() {
    std::fill(std::begin(root), std::end(root), -1);
    for (int v = 0; v < n(); ++v)
      if (root[v] == -1) dfs(v, v == 0);
  }

  int deeper(int id) const {
    assert(0 <= id), assert(id < m());
    int a = edges[id].src;
    int b = edges[id].dst;
    return depth[a] < depth[b] ? b : a;
  }
  bool is_tree_edge(int id) const {
    assert(0 <= id), assert(id < m());
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    assert(0 <= u), assert(u < n());
    assert(0 <= v), assert(v < n());
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    sz[v] = 1;
    min_depth[v] = depth[v];
    last[v] = num_trials;
    for (auto [u, id] : adj[v]) {
      if (id == pe[v]) continue;
      if (last[u] == num_trials) {
        min_depth[v] = std::min(min_depth[v], depth[u]);
        continue;
      }
      root[u] = root[v];
      pv[u] = v;
      pe[u] = id;
      depth[u] = depth[v] + 1;
      dist[u] = dist[v] + edges[id].cost;
      dfs_impl(u);
      sz[v] += sz[u];
      min_depth[v] = std::min(min_depth[v], min_depth[u]);
    }
    out[v] = std::size(order);
  }
};

struct SccResult {
  std::vector<int> vertex_to_comp;
  std::vector<std::vector<int>> components;
  Graph dag;
};
SccResult find_strongly_connected_components(const Graph& g) {
  SccResult res;
  res.vertex_to_comp.resize(g.n(), -1);
  std::vector<int> in(g.n(), -1);
  std::vector<int> min_in(g.n());
  std::stack<int, std::vector<int>> stk;
  int cnt = 0, t = 0;
  auto dfs = [&](auto self, int v) -> void {
    in[v] = t++;
    min_in[v] = in[v];
    stk.push(v);
    for (auto [u, id] : g.adj[v]) {
      if (in[u] == -1) {
        self(self, u);
        min_in[v] = std::min(min_in[v], min_in[u]);
      } else if (res.vertex_to_comp[u] == -1) {
        min_in[v] = std::min(min_in[v], in[u]);
      }
    }
    if (min_in[v] == in[v]) {
      while (true) {
        int u = stk.top();
        stk.pop();
        res.vertex_to_comp[u] = cnt;
        if (u == v) break;
      }
      ++cnt;
    }
  };
  for (int v = 0; v < g.n(); ++v)
    if (in[v] == -1) dfs(dfs, v);
  res.components.resize(cnt);
  for (int v = 0; v < g.n(); ++v) {
    res.vertex_to_comp[v] = cnt - res.vertex_to_comp[v] - 1;
    res.components[res.vertex_to_comp[v]].push_back(v);
  }
  std::vector<std::pair<int, int>> edges;
  for (int id = 0; id < g.m(); ++id) {
    int src = res.vertex_to_comp[g.edges[id].src];
    int dst = res.vertex_to_comp[g.edges[id].dst];
    if (src == dst) continue;
    edges.emplace_back(src, dst);
  }
  std::sort(std::begin(edges), std::end(edges));
  edges.erase(std::unique(std::begin(edges), std::end(edges)), std::end(edges));
  res.dag = Graph(cnt);
  for (auto [src, dst] : edges) res.dag.add_edge({src, dst, 1}, true);
  return res;
}

class Dsu {
 public:
  Dsu() {}
  explicit Dsu(int n) : dat(n, -1), num_components_(n) {}

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
    --num_components_;
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
  int num_components() const { return num_components_; }

 private:
  std::vector<int> dat;
  int num_components_;
};

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int k = scan();
  DfsTree g(n);
  int r = -1;
  for (int v : Rep(n)) {
    int p = scan() - 1;
    if (p == -1)
      r = v;
    else
      g.add_edge({v, p, 1});
  }
  g.dfs(r);
  vector<int> x(k), y(k);
  Dsu d(n);
  for (int i : Rep(k)) {
    x[i] = scan() - 1;
    y[i] = scan() - 1;
    if (d.same(x[i], y[i]) or g.is_ancestor(y[i], x[i])) {
      cout << "0\n";
      exit(0);
    }
    d.unite(x[i], y[i]);
  }
  Graph h(n);
  for (int id : Rep(n - 1)) {
    int src = d.root(g.edges[id].other(g.deeper(id)));
    int dst = d.root(g.deeper(id));
    h.add_edge({src, dst, 1}, true);
  }
  vector<int> ans;
  auto scc = find_strongly_connected_components(h);
  vector<vector<int>> vs(n);
  for (int v : Rep(n)) vs[d.root(v)].push_back(v);
  vector<int> nxt(n, -1);
  for (int i : Rep(k)) nxt[x[i]] = y[i];
  vector f(n, true);
  for (int i : Rep(k)) f[y[i]] = false;
  for (auto&& e : scc.components) {
    if (size(e) > 1) {
      cout << "0\n";
      exit(0);
    }
    int v = e[0];
    if (d.root(v) != v) continue;
    int s = -1;
    for (int u : vs[v])
      if (f[u]) {
        assert(s == -1);
        s = u;
      }
    while (true) {
      ans.push_back(s);
      s = nxt[s];
      if (s == -1) break;
    }
  }
  for (int i : Rep(n)) cout << ans[i] + 1 << " \n"[i == ~-n];
}