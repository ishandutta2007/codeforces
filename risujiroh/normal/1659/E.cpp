#include <bits/stdc++.h>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  for (auto& [u, v, w] : edges) {
    cin >> u >> v >> w;
    --u, --v;
  }

  vector d(30, atcoder::dsu(n));
  for (int i = 0; i < 30; ++i)
    for (auto [u, v, w] : edges)
      if (w >> i & 1) d[i].merge(u, v);

  vector d2(30, atcoder::dsu(n));
  for (int i = 1; i < 30; ++i)
    for (auto [u, v, w] : edges)
      if (w & 1 && w >> i & 1) d2[i].merge(u, v);

  vector good(n, false);
  for (auto [u, v, w] : edges) {
    if (w & 1) continue;
    good[u] = true;
    good[v] = true;
  }

  vector good2(30, vector(n, false));
  for (int i = 1; i < 30; ++i)
    for (int v = 0; v < n; ++v)
      if (good[v]) good2[i][d2[i].leader(v)] = true;

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    int ans = [&]() -> int {
      for (int i = 0; i < 30; ++i)
        if (d[i].same(u, v)) return 0;

      for (int i = 1; i < 30; ++i)
        if (good2[i][d2[i].leader(u)]) return 1;

      return 2;
    }();

    cout << ans << '\n';
  }
}