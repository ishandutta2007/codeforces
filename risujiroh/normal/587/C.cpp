#include <bits/extc++.h>

struct graph {
  struct edge {
    static inline bool cost;  // dummy
    int src, dst;

    int operator-(int v) const {
      assert(v == src or v == dst);
      return src ^ dst ^ v;
    }
  };

  int n, m;
  std::vector<edge> edges;
  std::vector<std::vector<std::pair<int, int>>> adj;
  std::function<bool(int)> ignore;

  graph(int _n = 0) : n(_n), m(0), adj(n), ignore([](int) { return false; }) {}

  int add(const edge& e, bool directed) {
    assert(0 <= e.src), assert(e.src < n);
    assert(0 <= e.dst), assert(e.dst < n);
    edges.push_back(e);
    adj[e.src].emplace_back(m, e.dst);
    if (not directed) adj[e.dst].emplace_back(m, e.src);
    return m++;
  }
};

struct dfs_forest : graph {
  using cost_t = decltype(edge::cost);

  std::vector<int> root, pv, pe, sz, depth, min_depth, last, order, in, out;
  std::vector<cost_t> dist;
  int trials;

  dfs_forest(int _n = 0) : graph(_n), dist(n), trials(0) {
    for (auto p : {&root, &pv, &pe, &sz, &depth, &min_depth, &last, &in, &out})
      p->assign(n, -1);
  }

  int add(const edge& e) { return graph::add(e, false); }
  void build(int r, bool clear_order = true) {
    assert(0 <= r), assert(r < n);
    root[r] = r, pv[r] = pe[r] = -1, depth[r] = 0, dist[r] = cost_t{};
    if (clear_order) order.clear();
    dfs(r);
    ++trials;
  }
  void build() {
    fill(begin(root), end(root), -1);
    for (int v = 0; v < n; ++v)
      if (root[v] == -1) build(v, v == 0);
  }
  int deeper(int id) const {
    assert(0 <= id), assert(id < m), assert(not ignore(id));
    int u = edges[id].src, v = edges[id].dst;
    return depth[u] < depth[v] ? v : u;
  }
  bool is_tree_edge(int id) const {
    assert(0 <= id), assert(id < m), assert(not ignore(id));
    return id == pe[deeper(id)];
  }
  bool is_ancestor(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    return in[u] <= in[v] and out[v] <= out[u];
  }

 private:
  void dfs(int v) {
    sz[v] = 1, min_depth[v] = depth[v], last[v] = trials;
    in[v] = size(order), order.push_back(v);
    for (auto [id, u] : adj[v]) {
      if (ignore(id) or id == pe[v]) continue;
      if (last[u] == trials) {
        min_depth[v] = std::min(min_depth[v], depth[u]);
        continue;
      }
      root[u] = root[v], pv[u] = v, pe[u] = id, depth[u] = depth[v] + 1;
      dist[u] = dist[v] + edges[id].cost;
      dfs(u);
      sz[v] += sz[u], min_depth[v] = std::min(min_depth[v], min_depth[u]);
    }
    out[v] = size(order);
  }
};

struct hld_forest : dfs_forest {
  std::vector<int> head;

  hld_forest(int _n = 0) : dfs_forest(_n), head(n) {}

  void build_hld(int r, bool clear_order = true) {
    assert(0 <= r), assert(r < n);
    build(r, clear_order);
    order.erase(end(order) - sz[r], end(order));
    head[r] = r;
    dfs_hld(r);
  }
  void build_hld() {
    fill(begin(root), end(root), -1);
    for (int v = 0; v < n; ++v)
      if (root[v] == -1) build_hld(v, v == 0);
  }
  int lca(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    assert(root[u] == root[v]);
    while (true) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    assert(root[u] == root[v]);
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
  cost_t distance(int u, int v) const {
    assert(0 <= u), assert(u < n);
    assert(0 <= v), assert(v < n);
    assert(root[u] == root[v]);
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
  }
  int la(int v, int d) const {
    assert(0 <= v), assert(v < n);
    assert(0 <= d), assert(d <= depth[v]);
    while (depth[head[v]] > d) v = pv[head[v]];
    return order[in[head[v]] + (d - depth[head[v]])];
  }
  int next(int src, int dst) const {
    assert(0 <= src), assert(src < n);
    assert(0 <= dst), assert(dst < n);
    assert(root[src] == root[dst]);
    assert(src != dst);
    if (not is_ancestor(src, dst)) return pv[src];
    return la(dst, depth[src] + 1);
  }
  int next(int src, int dst, int k) const {
    assert(0 <= src), assert(src < n);
    assert(0 <= dst), assert(dst < n);
    assert(root[src] == root[dst]);
    assert(k >= 0);
    int v = lca(src, dst);
    if (k <= depth[src] - depth[v]) return la(src, depth[src] - k);
    k -= depth[src] - depth[v];
    assert(k <= depth[dst] - depth[v]);
    return la(dst, depth[v] + k);
  }
  template <class Function>
  void apply(int src, int dst, bool vertex, Function func) const {
    assert(0 <= src), assert(src < n);
    assert(0 <= dst), assert(dst < n);
    assert(root[src] == root[dst]);
    int v = lca(src, dst);
    for (auto [a, b] : ascend(src, v)) func(a + 1, b);
    if (vertex) func(in[v], in[v] + 1);
    for (auto [a, b] : descend(v, dst)) func(a, b + 1);
  }

 private:
  void dfs_hld(int v) {
    in[v] = size(order), order.push_back(v);
    sort(begin(adj[v]), end(adj[v]), [&](auto a, auto b) {
      int au = a.second, bu = b.second;
      return (a.first == pe[au]) * sz[au] > (b.first == pe[bu]) * sz[bu];
    });
    for (auto [id, u] : adj[v]) {
      if (ignore(id) or id == pe[v] or not is_tree_edge(id)) continue;
      head[u] = u == adj[v][0].second ? head[v] : u;
      dfs_hld(u);
    }
    out[v] = size(order);
  }
  auto ascend(int src, int dst) const {
    std::vector<std::pair<int, int>> res;
    while (head[src] != head[dst]) {
      res.emplace_back(in[src], in[head[src]]);
      src = pv[head[src]];
    }
    if (src != dst) res.emplace_back(in[src], in[dst] + 1);
    return res;
  }
  std::vector<std::pair<int, int>> descend(int src, int dst) const {
    if (src == dst) return {};
    if (head[src] == head[dst]) return {{in[src] + 1, in[dst]}};
    auto res = descend(src, pv[head[dst]]);
    res.emplace_back(in[head[dst]], in[dst]);
    return res;
  }
};

struct segment_tree_base {
  virtual int size() const = 0;

 protected:
  template <class F>
  void forward(int l, int r, F f) const {
    int h = h1(l += size() - 1, r += size());
    for (int s = 0; s < h; ++s)
      if (int i = l >> s; ~i & 1) f(i + 1);
    for (int s = h; s--;)
      if (int i = r >> s; i & 1) f(i - 1);
  }
  template <class F>
  void forward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->forward(l, r, f);
  }
  template <class F>
  void backward(int l, int r, F f) const {
    int h = h1(l += size() - 1, r += size());
    for (int s = 0; s < h; ++s)
      if (int i = r >> s; i & 1) f(i - 1);
    for (int s = h; s--;)
      if (int i = l >> s; ~i & 1) f(i + 1);
  }
  template <class F>
  void backward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->backward(l, r, f);
  }
  template <class F>
  void downward(int l, int r, F f) const {
    if (l == r or (l == 0 and r == size())) return;
    int h = h2(l += size(), r += size());
    for (int s = std::__lg(l); s > h; --s) f(l >> s);
    for (int s = h; s > __builtin_ctz(l); --s) f(l >> s);
    for (int s = h; s > __builtin_ctz(r); --s) f(r >> s);
  }
  template <class F>
  void downward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->downward(l, r, f);
  }
  template <class F>
  void upward(int l, int r, F f) const {
    if (l == r or (l == 0 and r == size())) return;
    int h = h2(l += size(), r += size());
    for (int s = __builtin_ctz(r); s++ < h;) f(r >> s);
    for (int s = __builtin_ctz(l); s++ < h;) f(l >> s);
    for (int s = h; s++ < std::__lg(l);) f(l >> s);
  }
  template <class F>
  void upward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->upward(l, r, f);
  }

 private:
  static int h1(int l, int r) {
    for (int h = 0;; ++h)
      if ((r >> h) - (l >> h) == 1) return h;
  }
  static int h2(int l, int r) {
    l <<= std::__lg(l) < std::__lg(r);
    return std::__lg(l ^ r);
  }
};

template <class T>
struct segment_tree : segment_tree_base {
  segment_tree() {}
  template <class Generator>
  segment_tree(int n, Generator gen) : tree(2 * n) {
    for (int i = 0; i < n; ++i) tree[n + i] = gen(i);
    for (int i = n; i-- > 1;) pull(i);
  }

  int size() const override { return std::size(tree) / 2; }
  const T& operator[](int i) const {
    assert(0 <= i), assert(i < size());
    return tree[size() + i];
  }
  T fold(int l, int r) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T res{};
    forward(l, r, [&](int i) { res = res * tree[i]; });
    return res;
  }
  T fold_all_rotated() const { return size() ? tree[1] : T{}; }
  template <class Function>
  void update(int i, Function func) {
    assert(0 <= i), assert(i < size());
    tree[size() + i] = func(tree[size() + i]);
    upward(i, i + 1, [&](int j) { pull(j); });
  }
  template <class Predicate>
  int forward_search(int l, int r, Predicate pred) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T a{};
    assert(pred(a));
    int res = r;
    forward(l, r, [&](int i) {
      if (res < r) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = a * tree[i *= 2]; pred(na)) a = na, ++i;
      res = i - size();
    });
    return res;
  }
  template <class Predicate>
  int backward_search(int l, int r, Predicate pred) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T a{};
    assert(pred(a));
    int res = l - 1;
    backward(l, r, [&](int i) {
      if (res >= l) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = a * tree[i = 2 * i + 1]; pred(na)) a = na, --i;
      res = i - size();
    });
    return res;
  }

 private:
  std::vector<T> tree;

  void pull(int i) { tree[i] = tree[2 * i] * tree[2 * i + 1]; }
};

constexpr int inf = 0x3f3f3f3f;
struct node {
  int mn = inf, v = -1;
  friend node operator*(const node& a, const node& b) {
    return b.mn < a.mn ? b : a;
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  hld_forest g(n);
  for (int _ = n - 1; _--;) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add({u, v});
  }
  g.build_hld();
  vector ids(n, vector(10, inf));
  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    --c;
    ids[c].push_back(i + 1);
  }
  for (auto&& e : ids) sort(rbegin(e), rend(e));
  segment_tree<node> seg(n, [](int) -> node { return {}; });

  vector<tuple<int, int, node>> hist;
  auto add = [&](int v) -> void {
    assert(not empty(ids[v]));
    auto id = ids[v].back();
    ids[v].pop_back();
    hist.emplace_back(g.in[v], id, seg[g.in[v]]);
    seg.update(g.in[v], [&](const node&) -> node { return {id, v}; });
  };

  for (int v = 0; v < n; ++v) add(v);
  hist.clear();
  while (q--) {
    int u, v, a;
    cin >> u >> v >> a;
    --u, --v;
    vector<node> ans;
    while (a--) {
      node t{};
      g.apply(u, v, true, [&](int l, int r) {
        if (l > r) swap(l, r);
        t = t * seg.fold(l, r);
      });
      if (t.mn == inf) break;
      ans.push_back(t);
      add(t.v);
    }
    while (not empty(hist)) {
      auto [i, id, e] = hist.back();
      seg.update(i, [&](const node&) { return e; });
      ids[e.v].push_back(id);
      hist.pop_back();
    }
    cout << size(ans);
    for (auto&& e : ans) cout << ' ' << e.mn;
    cout << '\n';
  }
}