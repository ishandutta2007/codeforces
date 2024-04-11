using namespace std;

#ifndef OJ
#define OJ 1
#define NDEBUG
#endif

#include <bits/stdc++.h>
#include <x86intrin.h>

struct Graph {
  struct Edge {
    int src, dst;
    int64_t cost;

    int other(int v) const {
      __glibcxx_assert(v == src or v == dst);
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
    __glibcxx_assert(0 <= e.src and e.src < n());
    __glibcxx_assert(0 <= e.dst and e.dst < n());
    int id = m();
    edges.push_back(e);
    adj[e.src].emplace_back(e.dst, id);
    if (not directed) adj[e.dst].emplace_back(e.src, id);
    return id;
  }
};

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

struct DfsTree : Graph {
  using T = decltype(Edge::cost);

  std::vector<int> root;
  std::vector<int> pv;
  std::vector<int> pe;
  std::vector<int> order;
  std::vector<int> in;
  std::vector<int> out;
  std::vector<int> sub;
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
        sub(n, -1),
        depth(n, -1),
        min_depth(n, -1),
        dist(n, std::numeric_limits<T>::max()),
        last(n, -1),
        num_trials(0) {}

  int add_edge(const Edge& e) { return Graph::add_edge(e, false); }
  void dfs(int r, bool clear_order = true) {
    __glibcxx_assert(0 <= r and r < n());
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
    __glibcxx_assert(0 <= id and id < m());
    int a = edges[id].src;
    int b = edges[id].dst;
    return depth[a] < depth[b] ? b : a;
  }
  bool is_tree_edge(int id) const {
    __glibcxx_assert(0 <= id and id < m());
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    sub[v] = 1;
    min_depth[v] = depth[v];
    last[v] = num_trials;
    for (auto&& [u, id] : adj[v]) {
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
      sub[v] += sub[u];
      min_depth[v] = std::min(min_depth[v], min_depth[u]);
    }
    out[v] = std::size(order);
  }
};

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

struct HldTree : DfsTree {
  std::vector<int> head;

  HldTree() {}
  explicit HldTree(int n) : DfsTree(n), head(n, -1) {}

  void build(int r, bool clear_order = true) {
    __glibcxx_assert(0 <= r and r < n());
    dfs(r, clear_order);
    order.erase(std::end(order) - sub[r], std::end(order));
    head[r] = r;
    build_impl(r);
  }
  void build_all() {
    std::fill(std::begin(root), std::end(root), -1);
    for (int v = 0; v < n(); ++v)
      if (root[v] == -1) build(v, v == 0);
  }

  int lca(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    while (true) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
  T distance(int u, int v) const {
    __glibcxx_assert(0 <= u and u < n());
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(root[u] == root[v]);
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
  }
  int la(int v, int d) const {
    __glibcxx_assert(0 <= v and v < n());
    __glibcxx_assert(0 <= d and d <= depth[v]);
    while (depth[head[v]] > d) v = pv[head[v]];
    return order[in[head[v]] + (d - depth[head[v]])];
  }
  int next(int src, int dst) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    __glibcxx_assert(src != dst);
    if (not is_ancestor(src, dst)) return pv[src];
    return la(dst, depth[src] + 1);
  }
  int next(int src, int dst, int k) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    __glibcxx_assert(k >= 0);
    int v = lca(src, dst);
    if (k <= depth[src] - depth[v]) return la(src, depth[src] - k);
    k -= depth[src] - depth[v];
    __glibcxx_assert(k <= depth[dst] - depth[v]);
    return la(dst, depth[v] + k);
  }
  template <class Function> void apply(int src, int dst, bool vertex, Function f) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    int v = lca(src, dst);
    while (head[src] != head[v]) {
      f(in[src] + 1, in[head[src]]);
      src = pv[head[src]];
    }
    if (vertex)
      f(in[src] + 1, in[v]);
    else if (src != v)
      f(in[src] + 1, in[v] + 1);
    auto rec = [&](auto self, int to) -> void {
      if (head[v] == head[to]) {
        if (v != to) f(in[v] + 1, in[to] + 1);
        return;
      }
      self(self, pv[head[to]]);
      f(in[head[to]], in[to] + 1);
    };
    rec(rec, dst);
  }
  template <class Searcher> int search(int src, int dst, bool vertex, Searcher f) const {
    __glibcxx_assert(0 <= src and src < n());
    __glibcxx_assert(0 <= dst and dst < n());
    __glibcxx_assert(root[src] == root[dst]);
    int res = -1;
    apply(src, dst, vertex, [&](int l, int r) {
      if (res != -1) return;
      int i = f(l, r);
      if (l > r) std::swap(l, r);
      if (l <= i and i < r) res = vertex ? order[i] : pe[order[i]];
    });
    return res;
  }

 private:
  void build_impl(int v) {
    in[v] = std::size(order);
    order.push_back(v);
    auto pos = std::partition(std::begin(adj[v]), std::end(adj[v]), [&](auto&& e) { return e.second == pe[e.first]; });
    auto it =
        std::max_element(std::begin(adj[v]), pos, [&](auto&& a, auto&& b) { return sub[a.first] < sub[b.first]; });
    if (it != std::begin(adj[v])) std::iter_swap(std::begin(adj[v]), it);
    std::partition(pos, std::end(adj[v]), [&](auto&& e) { return e.second == pe[v]; });
    for (auto&& [u, id] : adj[v]) {
      if (id != pe[u]) break;
      head[u] = u == adj[v].front().first ? head[v] : u;
      build_impl(u);
    }
    out[v] = std::size(order);
  }
};

#define INC_DEC(op) \
  template <class T> vector<T>& operator op(vector<T>& v) { \
    for (T & e : v) op e; \
    return v; \
  } \
  template <class T> vector<T>&& operator op(vector<T>&& v) { return move(op v); } \
  template <class T> enable_if_t<__is_tuple_like<T>{}, T&&> operator op(T&& t) { \
    apply([](auto&... es) { (..., op es); }, t); \
    return forward<T>(t); \
  }
INC_DEC(++)
INC_DEC(--)
#undef INC_DEC
template <class T> istream& operator>>(istream& i, vector<T>& v) {
  for (T& e : v) i >> e;
  return i;
}
template <class T> enable_if_t<__is_tuple_like<T>{}, istream&> operator>>(istream& i, T& t) {
  apply([&](auto&... es) { (i >> ... >> es); }, t);
  return i;
}
template <class T> ostream& operator<<(ostream& o, const vector<T>& v) {
  string_view s;
  for (const T& e : v) o << exchange(s, " ") << e;
  return o;
}
template <class T> enable_if_t<__is_tuple_like<T>{}, ostream&> operator<<(ostream& o, const T& t) {
  string_view s;
  apply([&](const auto&... es) { (..., (o << exchange(s, " ") << es)); }, t);
  return o;
}
template <class T = int, class... Args> T input(Args&&... args) {
  T r(forward<Args>(args)...);
  cin >> r;
  return r;
}
template <class... Ts> enable_if_t<sizeof...(Ts) >= 2, tuple<Ts...>> input() {
  tuple<Ts...> r;
  apply([](auto&... es) { (cin >> ... >> es); }, r);
  return r;
}

using i64 = long long;

template <class F> struct Fix : F {
  explicit Fix(F f) : F(move(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) const {
    return F::operator()(ref(*this), forward<Args>(args)...);
  }
};

template <class R> int sz(const R& r) { return int(size(r)); }
template <class I> int sz(I b, I e) { return int(distance(b, e)); }
template <class T> T div_floor(T x, T y) { return assert(y), x / y - ((x ^ y) < 0 && x % y); }
template <class T> T div_ceil(T x, T y) { return assert(y), x / y + ((x ^ y) >= 0 && x % y); }
template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x ? x = forward<U>(y), true : false; }
template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y ? x = forward<U>(y), true : false; }

mt19937_64 rng(_rdtsc() * OJ);
template <class T> T rnd(T x, T y) { return uniform_int_distribution(x, y)(rng); }

#define fn(...) [&]([[maybe_unused]] auto&& _) -> decltype(auto) { return (__VA_ARGS__); }
#define dump(...) OJ ? cerr : cerr << __LINE__ << ": [" #__VA_ARGS__ "]: " << __VA_ARGS__ << '\n'

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int n, m; cin >> n >> m;) {
    HldTree g(n);
    for (int e : views::iota(0, m)) {
      g.add_edge({input() - 1, input() - 1, 1});
    }
    g.build_all();
    int q = input();
    vector<int> a(q), b(q);
    for (int i : views::iota(0, q)) {
      cin >> a[i] >> b[i];
    }
    --a, --b;
    vector<int> f(n);
    for (int i : views::iota(0, q)) {
      ++f[a[i]];
      ++f[b[i]];
    }
    if (int c = ranges::count_if(f, fn(_ & 1))) {
      assert(~c & 1);
      cout << "NO\n";
      cout << c / 2 << '\n';
    } else {
      cout << "YES\n";
      for (int i : views::iota(0, q)) {
        vector<int> ans;
        for (int v = a[i];; v = g.next(v, b[i])) {
          ans.push_back(v);
          if (v == b[i]) break;
        }
        cout << sz(ans) << '\n';
        cout << ++ans << '\n';
      }
    }
  }
}