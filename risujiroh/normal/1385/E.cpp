#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T = int> struct graph {
  struct edge {
    int from, to;
    T w;
    int operator-(int v) const { return from ^ to ^ v; }
  };
  int n, m;
  vector<edge> es;
  vector<vector<int>> g;
  graph(int _n = 0) : n(_n), m(0), g(n) {}
  int add(int from, int to, bool undirected = true, T w = 1) {
    g[from].push_back(m);
    if (undirected) g[to].push_back(m);
    return es.push_back({from, to, w}), m++;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> t(m);
    graph g(n);
    vector<int> indeg(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> t[i] >> u >> v;
      --u, --v;
      g.add(u, v);
      if (t[i]) {
        ++indeg[v];
      }
    }
    queue<int> que;
    for (int v = 0; v < n; ++v) {
      if (indeg[v]) continue;
      que.push(v);
    }
    vector<int> vs;
    while (not empty(que)) {
      int v = que.front();
      que.pop();
      vs.push_back(v);
      for (int id : g.g[v]) {
        if (t[id] == 0) continue;
        int to = g.es[id] - v;
        if (--indeg[to] == 0) {
          que.push(to);
        }
      }
    }
    if ((int)size(vs) < n) {
      cout << "NO\n";
      continue;
    }
    vector<int> ord(n, -1);
    for (int k = 0; k < n; ++k) {
      ord[vs[k]] = k;
    }
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
      int u = g.es[i].from, v = g.es[i].to;
      if (ord[u] > ord[v]) {
        swap(u, v);
      }
      cout << u + 1 << ' ' << v + 1 << '\n';
    }
  }
}