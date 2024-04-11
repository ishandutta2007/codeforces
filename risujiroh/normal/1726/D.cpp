#include <bits/stdc++.h>

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n, m;
  is >> n >> m;

  std::vector<std::array<int, 2>> edges(m);
  std::vector<std::vector<std::pair<int, int>>> g(n);
  for (int e = 0; e < m; ++e) {
    auto& [u, v] = edges[e];
    is >> u >> v;
    --u;
    --v;
    g[u].emplace_back(v, e);
    g[v].emplace_back(u, e);
  }

  std::vector<int> pe(n, -1);
  std::vector<int> depth(n);

  std::vector<int> es;
  es.reserve(m - n + 1);

  auto dfs = [&](auto self, int v) -> void {
    for (auto [u, e] : g[v]) {
      if (e == pe[v]) {
        continue;
      }
      if (u && pe[u] == -1) {
        pe[u] = e;
        depth[u] = depth[v] + 1;
        self(self, u);
      } else {
        if (depth[u] < depth[v]) {
          es.push_back(e);
        }
      }
    }
  };

  dfs(dfs, 0);

  assert(int(es.size()) == m - n + 1);

  std::string ans(m, '0');
  for (int e : es) {
    ans[e] = '1';
  }

  if (m == n + 2) {
    std::set<int> s;
    for (int e : es) {
      s.insert(edges[e][0]);
      s.insert(edges[e][1]);
    }
    if (s.size() == 3) {
      int e = es[0];
      auto [u, v] = edges[e];
      if (depth[u] < depth[v]) {
        std::swap(u, v);
      }
      std::swap(ans[pe[u]], ans[e]);
    }
  }

  os << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    solve(std::cin, std::cout);
  }
}