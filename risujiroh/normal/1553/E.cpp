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

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      int r = i - a[i];
      if (r < 0) r += n;
      ++cnt[r];
    }
    vector<int> ans;
    for (int k = 0; k < n; ++k) {
      if (cnt[k] < n - 2 * m) continue;
      vector<int> p(n);
      iota(begin(p), end(p), 0);
      rotate(begin(p), end(p) - k, end(p));
      vector<int> q(n);
      for (int i = 0; i < n; ++i) q[p[i]] = i;
      Dsu d(n);
      for (int i = 0; i < n; ++i) d.unite(i, q[a[i]]);
      if (n - d.num_components() > m) continue;
      ans.push_back(k);
    }
    cout << size(ans);
    for (auto&& e : ans) cout << ' ' << e;
    cout << '\n';
  }
}