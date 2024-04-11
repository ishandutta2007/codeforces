#include <bits/stdc++.h>
using namespace std;

struct scc {
  const int n;
  vector<pair<int, int>> edge_pool;
  vector<int> head, g, ord, low, st, cmp;
  int t = 0, id = 0;
  scc(int _n) : n(_n), head(n + 1), ord(n, -1), low(n), cmp(n, -1) {}
  void add(int from, int to) {
    edge_pool.emplace_back(from, to);
    ++head[from];
  }
  void build() {
    for (int v = 0; v < n; ++v) head[v + 1] += head[v];
    g.resize(head[n]);
    for (auto e : edge_pool) g[--head[e.first]] = e.second;
  }
  void dfs(int v) {
    ord[v] = low[v] = t++, st.push_back(v);
    for (int i = head[v]; i < head[v + 1]; ++i) {
      int to = g[i];
      if (ord[to] == -1) {
        dfs(to);
        low[v] = min(low[v], low[to]);
      } else if (cmp[to] == -1) {
        low[v] = min(low[v], ord[to]);
      }
    }
    if (ord[v] == low[v]) {
      while (true) {
        int u = st.back();
        st.pop_back();
        cmp[u] = id;
        if (u == v) break;
      }
      ++id;
    }
  }
  void run() {
    build();
    for (int v = 0; v < n; ++v) if (ord[v] == -1) dfs(v);
    for (auto&& e : cmp) e = id - e - 1;
  }
};

struct stopwatch {
  clock_t t = clock();
  void restart() { t = clock(); }
  int elapsed() const { return (clock() - t) * 1000 / CLOCKS_PER_SEC; }
  friend string to_string(stopwatch sw) {
    return "Time: " + to_string(sw.elapsed()) + " ms";
  }
} sw;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector a(n, vector(n, -1));
  scc g(n);
  while (m--) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    --u, --v;
    a[u][v] = c - 'a';
    g.add(u, v);
  }
  g.run();
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return g.cmp[i] > g.cmp[j];
  });
  vector dp(n, vector(n, bitset<26>()));
  while (sw.elapsed() < 900) {
    for (int i : ord) {
      for (int j : ord) {
        for (int k = 26; k--; ) {
          dp[i][j][k] = 0;
          for (int to = 0; to < n; ++to) {
            if (a[i][to] < k) {
              continue;
            }
            if (dp[j][to][a[i][to]] == 0) {
              dp[i][j][k] = 1;
              break;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (char)('B' - dp[i][j][0]);
    }
    cout << '\n';
  }
}