#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


struct QuickFind {
  const int n;
  V<> par;
  V< set<int> > chi;
  QuickFind(int n) : n(n), par(n), chi(n) {
    for (int i = 0; i < n; i++) {
      par[i] = i;
      chi[i].insert(i);
    }
  }
  void unite(int i, int j) {
    if (same(i, j)) return;
    if (size(i) < size(j)) swap(i, j);
    i = par[i], j = par[j];
    for (int e : chi[j]) par[e] = i;
    chi[i].insert(begin(chi[j]), end(chi[j]));
    set<int>().swap(chi[j]);
  }
  bool same(int i, int j) const { return par[i] == par[j]; }
  int size(int i) const { return chi[par[i]].size(); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<char> c(n, V<char>(m));
  QuickFind qf(n + m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    cin >> c[i][j];
    if (c[i][j] == '=') {
      qf.unite(i, n + j);
    }
  }
  VV<> g(n + m);
  V<> d(n + m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    int pi = qf.par[i];
    int pj = qf.par[n + j];
    if (c[i][j] == '<') {
      g[pi].push_back(pj);
      ++d[pj];
    } else if (c[i][j] == '>') {
      g[pj].push_back(pi);
      ++d[pi];
    }
  }
  queue<int> que;
  V<> res(n + m);
  for (int v = 0; v < n + m; ++v) if (d[v] == 0) {
    res[v] = 1;
    que.push(v);
  }
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int w : g[v]) {
      res[w] = max(res[w], res[v] + 1);
      if (--d[w] == 0) {
        que.push(w);
      }
    }
  }
  for (int v = 0; v < n + m; ++v) {
    res[v] = res[qf.par[v]];
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    if (c[i][j] == '=' and res[i] != res[n + j]) return cout << "No" << '\n', 0;
    if (c[i][j] == '<' and res[i] >= res[n + j]) return cout << "No" << '\n', 0;
    if (c[i][j] == '>' and res[i] <= res[n + j]) return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " \n"[i == n - 1];
  }
  for (int j = 0; j < m; ++j) {
    cout << res[n + j] << " \n"[j == m - 1];
  }
}