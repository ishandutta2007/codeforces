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
  for (int tt = scan(); tt--;) {
    int n = scan();
    int k = scan();
    DfsTree g(n);
    for (int v : Rep(1, n)) g.add_edge({v, scan() - 1, 1});
    g.dfs_all();

    int deepest = max_element(ALL(g.depth)) - begin(g.depth);
    vector<int> path;
    path.reserve(g.depth[deepest] + 1);
    for (int v = deepest; v != -1; v = g.pv[v]) {
      path.push_back(v);
    }
    reverse(ALL(path));

    if (k <= int(size(path))) {
      cout << k - 1 << '\n';
      for (int i : Rep(k)) cout << path[i] + 1 << " \n"[i + 1 == k];
      continue;
    }

    for (int i : Rep(1, size(path))) {
      int p = path[i - 1];
      int v = path[i];
      for (auto&& e : g.adj[p])
        if (e.first == v) {
          swap(g.adj[p].front(), e);
          break;
        }
    }
    g.dfs_all();

    int l = 2 * k - size(path) - 1;
    cout << l << '\n';
    vector<int> ans{0};
    ans.reserve(l + 1);
    vector<int> stk{0};
    for (int i : Rep(1, k)) {
      int v = g.order[i];
      while (g.depth[stk.back()] >= g.depth[v]) {
        stk.pop_back();
        ans.push_back(stk.back());
      }
      ans.push_back(v);
      stk.push_back(v);
    }
    stk.pop_back();
    while (not empty(stk)) {
      ans.push_back(stk.back());
      stk.pop_back();
    }
    reverse(ALL(ans));
    ans.erase(end(ans) - (size(path) - 1), end(ans));
    assert(int(size(ans)) == l + 1);
    for (int i : Rep(l + 1)) cout << ans[i] + 1 << " \n"[i == l];
  }
}