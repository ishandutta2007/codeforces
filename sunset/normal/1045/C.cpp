#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<vector<int>> adj(n), graph(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  vector<int> dfn(n, -1), low(n, -1), stack;
  int dfn_t = 0;
  m = n;
  function<void(int, int)> tarjan = [&](int x, int parent) {
    dfn[x] = low[x] = dfn_t++;
    stack.push_back(x);
    for (auto y : graph[x]) {
      if (y != parent) {
        if (!~dfn[y]) {
          tarjan(y, x);
          low[x] = min(low[x], low[y]);
          if (dfn[x] <= low[y]) {
            adj.push_back(vector<int>());
            adj[x].push_back(m);
            int z;
            do {
              z = stack.back();
              stack.pop_back();
              adj[m].push_back(z);
            } while (z != y);
            ++m;
          }
        } else {
          low[x] = min(low[x], dfn[y]);
        }
      }
    }
  };

  tarjan(0, -1);
  int log_m = 0;
  while (1 << log_m < m) {
    ++log_m;
  }
  vector<vector<int>> ancestor(log_m, vector<int> (m, -1));
  vector<int> depth(m), dist(m);

  function<void(int)> dfs = [&](int x) {
    for (int i = 1; depth[x] >> i; ++i) {
      ancestor[i][x] = ancestor[i - 1][ancestor[i - 1][x]];
    }
    for (auto y : adj[x]) {
      ancestor[0][y] = x;
      depth[y] = depth[x] + 1;
      dist[y] = dist[x] + 1 - (y >= n);
      dfs(y);
    }
  };

  auto lca = [&](int x, int y) {
    if (depth[x] < depth[y]) {
      swap(x, y);
    }
    for (int i = 0; depth[x] > depth[y]; ++i) {
      if (depth[x] - depth[y] >> i & 1) {
        x = ancestor[i][x];
      }
    }
    if (x == y) {
      return x;
    }
    for (int i = log_m - 1; ~i; --i) {
      if (ancestor[i][x] != ancestor[i][y]) {
        x = ancestor[i][x];
        y = ancestor[i][y];
      }
    }
    return ancestor[0][x];
  };

  dfs(0);
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    int z = lca(x, y);
    printf("%d\n", dist[x] + dist[y] - (dist[z] << 1) - (z >= n));
  }
  return 0;
}