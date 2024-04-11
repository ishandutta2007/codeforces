#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
  std::vector<int> start;
  std::vector<E> elist;
  explicit csr(int n, const std::vector<std::pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {
    for (auto e : edges) {
      start[e.first + 1]++;
    }
    for (int i = 1; i <= n; i++) {
      start[i] += start[i - 1];
    }
    auto counter = start;
    for (auto e : edges) {
      elist[counter[e.first]++] = e.second;
    }
  }
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {
namespace internal {

struct scc_graph {
 public:
  explicit scc_graph(int n) : _n(n) {}

  int num_vertices() { return _n; }

  void add_edge(int from, int to) { edges.push_back({from, {to}}); }

  std::pair<int, std::vector<int>> scc_ids() {
    auto g = csr<edge>(_n, edges);
    int now_ord = 0, group_num = 0;
    std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
    visited.reserve(_n);
    auto dfs = [&](auto self, int v) -> void {
      low[v] = ord[v] = now_ord++;
      visited.push_back(v);
      for (int i = g.start[v]; i < g.start[v + 1]; i++) {
        auto to = g.elist[i].to;
        if (ord[to] == -1) {
          self(self, to);
          low[v] = std::min(low[v], low[to]);
        } else {
          low[v] = std::min(low[v], ord[to]);
        }
      }
      if (low[v] == ord[v]) {
        while (true) {
          int u = visited.back();
          visited.pop_back();
          ord[u] = _n;
          ids[u] = group_num;
          if (u == v) break;
        }
        group_num++;
      }
    };
    for (int i = 0; i < _n; i++) {
      if (ord[i] == -1) dfs(dfs, i);
    }
    for (auto& x : ids) {
      x = group_num - 1 - x;
    }
    return {group_num, ids};
  }

  std::vector<std::vector<int>> scc() {
    auto ids = scc_ids();
    int group_num = ids.first;
    std::vector<int> counts(group_num);
    for (auto x : ids.second) counts[x]++;
    std::vector<std::vector<int>> groups(ids.first);
    for (int i = 0; i < group_num; i++) {
      groups[i].reserve(counts[i]);
    }
    for (int i = 0; i < _n; i++) {
      groups[ids.second[i]].push_back(i);
    }
    return groups;
  }

  //  private:
  int _n;
  struct edge {
    int to;
  };
  std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

struct scc_graph {
 public:
  scc_graph() : internal(0) {}
  explicit scc_graph(int n) : internal(n) {}

  void add_edge(int from, int to) {
    int n = internal.num_vertices();
    assert(0 <= from && from < n);
    assert(0 <= to && to < n);
    internal.add_edge(from, to);
  }

  std::vector<std::vector<int>> scc() { return internal.scc(); }

  //  private:
  internal::scc_graph internal;
};

}  // namespace atcoder

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto&& e : s) cin >> e;
  vector<int> a(w);
  for (auto&& e : a) cin >> e;
  vector nxt(h + 1, vector<int>(w, h));
  for (int i = h; i--;)
    for (int j = w; j--;) nxt[i][j] = s[i][j] == '#' ? i : nxt[i + 1][j];
  int n = 0;
  vector id(h, vector<int>(w, -1));
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (s[i][j] == '#') id[i][j] = n++;
  atcoder::scc_graph g(n);
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (s[i][j] == '#') {
        if (j and nxt[i][j - 1] < h) g.add_edge(id[i][j], id[nxt[i][j - 1]][j - 1]);
        if (nxt[i + 1][j] < h) g.add_edge(id[i][j], id[nxt[i + 1][j]][j]);
        if (j + 1 < w and nxt[i][j + 1] < h) g.add_edge(id[i][j], id[nxt[i][j + 1]][j + 1]);
        if (i and s[i - 1][j] == '#') g.add_edge(id[i][j], id[i - 1][j]);
      }
  auto scc = g.scc();
  vector<int> comp(n, -1);
  for (int i = 0; i < int(size(scc)); ++i)
    for (int v : scc[i]) comp[v] = i;
  vector<bool> b(size(scc), true);
  for (auto&& [v, e] : g.internal.edges)
    if (comp[v] != comp[e.to]) b[comp[e.to]] = false;
  cout << count(begin(b), end(b), true) << '\n';
}