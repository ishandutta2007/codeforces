#include <bits/stdc++.h>
using namespace std;

auto chmax = [](auto&& l, auto r) { return l < r ? l = r, 1 : 0; };

constexpr long long inf = 0x3f3f3f3fLL << 32;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  struct Edge {
    int from, to;
  };
  vector<Edge> es;
  vector<vector<int>> g(n);
  auto add_edge = [&](int from, int to) {
    g[from].push_back(es.size());
    es.emplace_back(Edge{from, to});
  };
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    add_edge(u, v);
    add_edge(v, u);
  }
  auto to = [&](int v, int id) {
    return v ^ es[id].from ^ es[id].to;
  };
  vector<int> sz(2 * (n - 1));
  {
    auto dfs = [&](auto&& self, int v, int pid) -> void {
      sz[pid] = 1;
      for (int id : g[v]) {
        if ((id ^ 1) != pid) {
          self(self, to(v, id), id);
          sz[pid] += sz[id];
        }
      }
      sz[pid ^ 1] = n - sz[pid];
    };
    for (int id : g[0]) {
      dfs(dfs, to(0, id), id);
    }
  }
  vector<vector<int>> d(n, vector<int>(n));
  vector<vector<pair<int, int>>> lrid(n);
  {
    for (int r = 0; r < n; ++r) {
      auto dfs = [&](auto&& self, int v, int pid) -> void {
        for (int id : g[v]) {
          if ((id ^ 1) != pid) {
            d[r][to(v, id)] = d[r][v] + 1;
            self(self, to(v, id), id);
          }
        }
      };
      dfs(dfs, r, -1);
    }
    for (int id = 1; id < 2 * (n - 1); id += 2) {
      lrid[1].emplace_back(id, id - 1);
    } 
    for (int lid = 0; lid < 2 * (n - 1); ++lid) {
      for (int rid = 0; rid < lid; ++rid) {
        if (d[es[lid].from][es[rid].from] + 2 == d[es[lid].to][es[rid].to]) {
          lrid[d[es[lid].to][es[rid].to]].emplace_back(lid, rid);
        }
      }
    }
  }
  vector<vector<long long>> dp(2 * (n - 1));
  for (int id = 0; id < 2 * (n - 1); ++id) {
    dp[id].assign(id, -inf);
    if (id > (id ^ 1)) {
      dp[id][id ^ 1] = sz[id] * sz[id ^ 1];
    }
  }
  for (auto v : lrid) {
    for (auto e : v) {
      int lid, rid;
      tie(lid, rid) = e;
      for (int id : g[es[lid].to]) {
        if ((id ^ 1) != lid) {
          chmax(dp[max(id, rid)][min(id, rid)], dp[lid][rid] + sz[id] * sz[rid]);
        }
      }
      for (int id : g[es[rid].to]) {
        if ((id ^ 1) != rid) {
          chmax(dp[max(lid, id)][min(lid, id)], dp[lid][rid] + sz[lid] * sz[id]);
        }
      }
    }
  }
  long long res = -inf;
  for (auto e : dp) {
    if (e.empty()) {
      continue;
    }
    chmax(res, *max_element(begin(e), end(e)));
  }
  cout << res << '\n';
}