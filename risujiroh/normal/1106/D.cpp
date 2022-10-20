#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    if (u == v) continue;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int v = 0; v < n; ++v) {
    sort(begin(g[v]), end(g[v]));
    g[v].erase(unique(begin(g[v]), end(g[v])), end(g[v]));
  }
  V<> a;
  priority_queue< int, V<>, greater<int> > pque;
  V<bool> vis(n);
  vis[0] = true;
  pque.push(0);
  while (!pque.empty()) {
    int v = pque.top(); pque.pop();
    a.push_back(v);
    for (int w : g[v]) if (!vis[w]) {
      vis[w] = true;
      pque.push(w);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] + 1 << " \n"[i == n - 1];
  }
}