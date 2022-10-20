#include <bits/stdc++.h>

class Dsu {
 public:
  struct Node {
    int parent = -1;
    int size = 1;

    void merge(Node& o) { size += o.size; }
  };

  Dsu() {}
  explicit Dsu(int n) : tree(n), num_ccs_(n) {}

  int size() const { return std::size(tree); }
  int root(int v) const {
    assert(0 <= v), assert(v < size());
    while (tree[v].parent != -1) v = tree[v].parent;
    return v;
  }
  void unite(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    u = root(u);
    v = root(v);
    assert(u != v);
    --num_ccs_;
    if (tree[u].size < tree[v].size) std::swap(u, v);
    history.emplace_back(u, tree[u]);
    history.emplace_back(v, tree[v]);
    tree[v].parent = u;
    tree[u].merge(tree[v]);
  }
  void rollback() {
    ++num_ccs_;
    for (int _ = 2; _--;) {
      auto&& [v, t] = history.back();
      tree[v] = std::move(t);
      history.pop_back();
    }
  }
  bool same(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    return root(u) == root(v);
  }
  Node& get(int v) {
    assert(0 <= v), assert(v < size());
    return tree[root(v)];
  }
  int num_ccs() const { return num_ccs_; }

 private:
  std::vector<Node> tree;
  std::vector<std::pair<int, Node>> history;
  int num_ccs_;
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
  int m = scan();
  int k = scan();
  vector<int> col(n);
  for (auto&& e : col) {
    cin >> e;
    --e;
  }
  vector<array<int, 2>> edges(m);
  for (auto&& [u, v] : edges) {
    cin >> u >> v;
    --u, --v;
  }

  Dsu d(2 * n);
  for (auto [u, v] : edges)
    if (col[u] == col[v]) {
      if (not d.same(2 * u, 2 * v + 1)) d.unite(2 * u, 2 * v + 1);
      if (not d.same(2 * u + 1, 2 * v)) d.unite(2 * u + 1, 2 * v);
    }

  vector good(k, true);
  for (int v : Rep(n))
    if (d.same(2 * v, 2 * v + 1)) good[col[v]] = false;

  map<pair<int, int>, vector<int>> mp;
  for (int id : Rep(m)) {
    auto [u, v] = edges[id];
    if (col[u] == col[v]) continue;
    if (not good[col[u]]) continue;
    if (not good[col[v]]) continue;
    mp[minmax(col[u], col[v])].push_back(id);
  }

  int64_t ans = count(begin(good), end(good), true);
  ans = ans * (ans - 1) / 2;
  for (auto&& [p, ids] : mp) {
    int cnt = 0;
    for (int id : ids) {
      auto [u, v] = edges[id];
      if (d.same(2 * u, 2 * v + 1)) {
        assert(d.same(2 * u + 1, 2 * v));
        continue;
      }
      d.unite(2 * u, 2 * v + 1), ++cnt;
      if (d.same(2 * u + 1, 2 * v)) continue;
      d.unite(2 * u + 1, 2 * v), ++cnt;
    }
    [&] {
      for (int id : ids)
        for (int v : edges[id])
          if (d.same(2 * v, 2 * v + 1)) {
            --ans;
            return;
          }
    }();
    while (cnt--) d.rollback();
  }
  cout << ans << '\n';
}