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

constexpr int Inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  Graph g(n);
  for (int m = scan(); m--;) g.add_edge({scan() - 1, scan() - 1, scan()}, true);

  Dsu d(2 * n);
  for (auto&& [i, j, b] : g.edges) {
    d.unite(2 * i, 2 * j + 1);
    d.unite(2 * i + 1, 2 * j);
  }
  for (int i : Rep(n))
    if (d.same(2 * i, 2 * i + 1)) {
      cout << "NO\n";
      exit(0);
    }

  int mx = -1;
  vector<int> ans(n);

  Graph h(n);
  for (auto&& [i, j, b] : g.edges)
    if (b) {
      if (d.same(2 * i, 0)) {
        h.add_edge({i, j, 0}, false);
      } else {
        h.add_edge({i, j, 1}, true);
        h.add_edge({j, i, -1}, true);
      }
    } else {
      if (d.same(2 * i, 0)) {
        h.add_edge({i, j, 0}, true);
        h.add_edge({j, i, 1}, true);
      } else {
        h.add_edge({i, j, 1}, true);
        h.add_edge({j, i, 0}, true);
      }
    }

  for (int s : Rep(n)) {
    vector p(n, +Inf);
    vector<int> que{s};
    p[s] = 0;
    for (int i = 0; i < int(size(que)); ++i) {
      int v = que[i];
      if (p[v] < 0) break;
      for (auto [u, id] : h.adj[v])
        if (chmin(p[u], p[v] + h.edges[id].cost)) que.push_back(u);
    }
    for (int i : Rep(n)) p[i] = 2 * p[i] + d.same(2 * i + 1, 0);
    bool feasible = true;
    for (auto&& [i, j, b] : g.edges)
      if (b) {
        if (p[j] - p[i] != 1) {
          feasible = false;
          break;
        }
      } else {
        if (abs(p[j] - p[i]) != 1) {
          feasible = false;
          break;
        }
      }
    if (not feasible) continue;
    if (chmax(mx, *max_element(ALL(p)) - *min_element(ALL(p)))) ans = p;
  }

  if (mx == -1) {
    cout << "NO\n";
    exit(0);
  }

  cout << "YES\n";
  cout << mx << '\n';
  int mn = *min_element(ALL(ans));
  for (auto&& e : ans) e -= mn;
  for (int i : Rep(n)) cout << ans[i] << " \n"[i == ~-n];
}