#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  scc sc(n);
  vector g(2, vector<vector<int>>(n));
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    sc.add(a, b);
    g[0][a].push_back(b);
    g[1][b].push_back(a);
  }
  sc.run();
  if (sc.id != n) {
    cout << "-1\n";
    exit(0);
  }
  vector ex(2, vector(n, true));
  string res(n, 'E');
  for (int v = 0; v < n; ++v) {
    if (ex[0][v] and ex[1][v]) {
      res[v] = 'A';
    }
    for (int i : {0, 1}) {
      queue<int> que;
      ex[i][v] = false;
      que.push(v);
      while (not empty(que)) {
        int u = que.front();
        que.pop();
        for (int to : g[i][u]) {
          if (ex[i][to]) {
            ex[i][to] = false;
            que.push(to);
          }
        }
      }
    }
  }
  cout << count(begin(res), end(res), 'A') << '\n';
  cout << res << '\n';
}