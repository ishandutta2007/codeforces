#include <bits/stdc++.h>

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
  int64_t n = scan();
  int64_t m = scan();
  Graph g(n);
  int x = 0;
  for (int _ = m; _--;) {
    int u = scan() - 1;
    int v = scan() - 1;
    int w = scan();
    g.add_edge({u, v, w}, false);
    x ^= w;
  }
  for (int v : Rep(n)) sort(ALL(g.adj[v]));
  bool forest = n * (n - 1) / 2 - m < n;
  if (forest) {
    Dsu d(n);
    for (int v : Rep(n)) {
      auto it = begin(g.adj[v]);
      for (int u : Rep(v)) {
        if (it != end(g.adj[v]) and it->first == u) {
          ++it;
          continue;
        }
        if (d.same(v, u)) forest = false;
        d.unite(v, u);
      }
    }
    if (forest) {
      int64_t ans = x;
      vector<int> order(m);
      iota(ALL(order), 0);
      sort(ALL(order),
           [&](int i, int j) { return g.edges[i].cost < g.edges[j].cost; });
      Dsu f(n);
      for (int id : order) {
        auto e = g.edges[id];
        if (d.same(e.src, e.dst)) continue;
        d.unite(e.src, e.dst);
        ans += e.cost;
        f.unite(e.src, e.dst);
      }
      int mn = 1 << 30;
      for (auto&& e : g.edges)
        if (not f.same(e.src, e.dst)) chmin(mn, e.cost);
      cout << min(ans, ans + mn - x) << '\n';
      exit(0);
    }
  }

  Dsu d(n);
  vector vis(n, false);
  vector<int> lst(n - 1);
  iota(ALL(lst), 1);
  for (int s : Rep(n)) {
    if (vis[s]) continue;
    vector que{s};
    for (int z = 0; z < int(size(que)); ++z) {
      int v = que[z];
      vector<int> nlst;
      auto it = begin(g.adj[v]);
      for (int u : lst) {
        while (it != end(g.adj[v]) and it->first < u) ++it;
        if (it != end(g.adj[v]) and it->first == u) {
          nlst.push_back(u);
        } else {
          que.push_back(u);
          DUMP(v, u);
          d.unite(v, u);
        }
      }
      lst = move(nlst);
    }
  }
  int64_t ans = 0;
  vector<int> order(m);
  iota(ALL(order), 0);
  sort(ALL(order),
       [&](int i, int j) { return g.edges[i].cost < g.edges[j].cost; });
  for (int id : order) {
    auto e = g.edges[id];
    if (d.same(e.src, e.dst)) continue;
    d.unite(e.src, e.dst);
    ans += e.cost;
  }
  cout << ans << '\n';
}