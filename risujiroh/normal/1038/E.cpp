#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  struct block { int c1, v, c2; };
  V<block> a(n);
  for (int i = 0; i < n; i++) {
    int c1, v, c2; cin >> c1 >> v >> c2, c1--, c2--;
    if (c1 > c2) swap(c1, c2);
    a[i] = block{c1, v, c2};
  }
  V<> v(4);
  VV<V<>> e; assign(e, 4, 4);
  for (int i = 0; i < n; i++) {
    if (a[i].c1 == a[i].c2) v[a[i].c1] += a[i].v;
    else e[a[i].c1][a[i].c2].push_back(a[i].v);
  }
  for (int i = 0; i < 3; i++) for (int j = i + 1; j < 4; j++) sort(e[i][j].begin(), e[i][j].end());
  VV<> g(4);
  for (int i = 0; i < n; i++) if (a[i].c1 != a[i].c2) {
    g[a[i].c1].push_back(a[i].c2);
    g[a[i].c2].push_back(a[i].c1);
  }
  int res = 0;
  V<> l = {0, 0, 0, 1, 1, 2}, r = {1, 2, 3, 2, 3, 3};
  for (int bit = 0; bit < 1 << 6; bit++) {
    V<bool> b(6);
    for (int i = 0; i < 6; i++) if (bit & 1 << i) {
      for (int j = 0; j < g[l[i]].size(); j++) if (g[l[i]][j] == r[i]) {
        g[l[i]].erase(g[l[i]].begin() + j);
        b[i] = true;
        break;
      }
      for (int j = 0; j < g[r[i]].size(); j++) if (g[r[i]][j] == l[i]) {
        g[r[i]].erase(g[r[i]].begin() + j);
        break;
      }
    }
    V<bool> vis(4);
    for (int i = 0; i < 4; i++) if (!vis[i]) {
      set<int> c;
      queue<int> q;
      vis[i] = true; q.push(i);
      while (!q.empty()) {
        int u = q.front(); q.pop();
        c.insert(u);
        for (int j : g[u]) if (!vis[j]) {
          vis[j] = true; q.push(j);
        }
      }
      int d = 0;
      for (auto u : c) d += g[u].size() & 1;
      if (d == 0 or d == 2) {
        int tmp = 0;
        for (auto u : c) tmp += v[u];
        for (int j = 0; j < 6; j++) {
          if (c.count(l[j]) or c.count(r[j])) tmp += accumulate(e[l[j]][r[j]].begin(), e[l[j]][r[j]].end(), 0);
          if (b[j]) tmp -= e[l[j]][r[j]][0];
        }
        res = max(res, tmp);
      }
    }
    for (int i = 0; i < 6; i++) if (b[i]) {
      g[l[i]].push_back(r[i]);
      g[r[i]].push_back(l[i]);
    }
  }
  cout << res << '\n';
}