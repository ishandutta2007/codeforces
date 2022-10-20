#include <bits/stdc++.h>

struct Node {
  int mn = std::numeric_limits<int>::max();
  int x = -1, y = -1;
  friend Node operator*(const Node& a, const Node& b) { return b.mn < a.mn ? b : a; }
};

struct Fenwick {
  std::vector<Node> tree;

  Fenwick() {}
  explicit Fenwick(int n) : tree(n) {}

  int size() const { return std::size(tree); }
  void update(int i, const Node& a) {
    for (; i < size(); i |= i + 1) tree[i] = tree[i] * a;
  }
  Node query(int i) const {
    Node res{};
    for (; i; i &= i - 1) res = res * tree[i - 1];
    return res;
  }
};

struct Fenwick2 {
  int n;
  std::vector<std::pair<int, int>> ps;
  std::vector<std::vector<int>> ys;
  std::vector<Fenwick> f;
  void add_point(int x, int y) { ps.emplace_back(x, y); }
  void build() {
    std::sort(std::begin(ps), std::end(ps));
    ps.erase(std::unique(std::begin(ps), std::end(ps)), std::end(ps));
    n = std::size(ps);
    ys.resize(n), f.resize(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; j |= j + 1) ys[j].push_back(ps[i].second);
      std::sort(std::begin(ys[i]), std::end(ys[i]));
      ys[i].erase(std::unique(std::begin(ys[i]), std::end(ys[i])), std::end(ys[i]));
      f[i] = Fenwick(std::size(ys[i]));
    }
  }
  int zip(int x) const {
    return std::lower_bound(std::begin(ps), std::end(ps), std::pair{x, std::numeric_limits<int>::min()}) -
           std::begin(ps);
  }
  int zip(int i, int y) const { return std::lower_bound(std::begin(ys[i]), std::end(ys[i]), y) - std::begin(ys[i]); }
  void update(int x, int y, const Node& a) {
    int i = std::lower_bound(std::begin(ps), std::end(ps), std::pair{x, y}) - std::begin(ps);
    for (; i < n; i |= i + 1) f[i].update(zip(i, y), a);
  }
  Node query(int x, int y) const {
    Node res{};
    for (int i = zip(x); i; i &= i - 1) res = res * f[i - 1].query(zip(i - 1, y));
    return res;
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<tuple<int, int, int>>> v(n + 1);
  Fenwick2 f;
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    v[r - l].emplace_back(r, n - l, i);
    f.add_point(r, n - l);
  }
  f.build();

  vector<int> ans(n + 1);
  for (int k = n; k; --k) {
    for (auto&& [x, y, t] : v[k]) f.update(x, y, {t, x, y});

    auto solve = [&](auto self, int l, int r) -> int {
      if (l >= r) return 0;
      Node e = f.query(r + 1, n - l + 1);
      if (e.mn == numeric_limits<int>::max()) return 0;
      return self(self, l, n - e.y) + (e.x + e.y - n) + self(self, e.x, r);
    };

    ans[k] = solve(solve, 0, n);
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}