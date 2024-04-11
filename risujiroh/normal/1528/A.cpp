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

// clang-format off
using namespace std;
class Rep{struct I{int i;void operator++(){++i;}int operator*(){return i;}bool operator!=(I o){return i<*o;}}b,e;
public:Rep(int l,int r):b{l},e{r}{}Rep(int n):Rep(0,n){}I begin(){return b;}I end(){return e;}};
class Per{struct I{int i;void operator++(){--i;}int operator*(){return i;}bool operator!=(I o){return i>*o;}}b,e;
public:Per(int l,int r):b{r-1},e{l-1}{}Per(int n):Per(0,n){}I begin(){return b;}I end(){return e;}};
template<class F>struct Fix:F{Fix(F f):F(f){}
template<class...T>decltype(auto)operator()(T&&...a){return F::operator()(*this,forward<T>(a)...);}};
template<class T=int>T scan(){T r;cin>>r;return r;}
template<class T,class U=T>bool chmin(T&a,U&&b){return b<a?a=forward<U>(b),1:0;}
template<class T,class U=T>bool chmax(T&a,U&&b){return a<b?a=forward<U>(b),1:0;}
#ifndef LOCAL
#define DUMP(...) void(0)
#endif
#define ALL(c) begin(c), end(c)
// clang-format on

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int tt = scan(); tt--;) {
    int n = scan();
    vector<array<int, 2>> a(n);
    for (auto&& e : a) e = {scan(), scan()};
    DfsTree g(n);
    for (int _ = n - 1; _--;) g.add_edge({scan() - 1, scan() - 1, 1});
    g.dfs(0);
    vector<array<int64_t, 2>> f(n);
    for_each(rbegin(g.order), rend(g.order), [&](int v) {
      for (auto&& [u, id] : g.adj[v]) {
        if (id != g.pe[u]) continue;
        auto nf = f[v];
        for (int i : Rep(2))
          for (int j : Rep(2)) chmax(nf[i], f[v][i] + f[u][j] + abs(a[v][i] - a[u][j]));
        f[v] = move(nf);
      }
    });
    cout << *max_element(ALL(f[0])) << '\n';
  }
}