#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int scc(const VV<>& g, V<>& comp) {
  int n = g.size();
  VV<> rg(n);
  for (int v = 0; v < n; v++) for (int w : g[v]) {
    rg[w].push_back(v);
  }
  V<> vs;
  V<bool> vis(n);
  comp.resize(n);
  auto dfs = [&](const auto& dfs, int v) -> void {
    vis[v] = true;
    for (int w : g[v]) if (!vis[w]) {
      dfs(dfs, w);
    }
    vs.push_back(v);
  };
  auto rdfs = [&](const auto& rdfs, int v, int k) -> void {
    vis[v] = true;
    comp[v] = k;
    for (int w : rg[v]) if (!vis[w]) {
      rdfs(rdfs, w, k);
    }
  };
  for (int v = 0; v < n; v++) if (!vis[v]) {
    dfs(dfs, v);
  }
  vis.assign(n, false);
  int k = 0;
  reverse(begin(vs), end(vs));
  for (int v : vs) if (!vis[v]) {
    rdfs(rdfs, v, k++);
  }
  return k;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    V<> nxt(n); for (auto&& e : nxt) cin >> e, --e;
    /*{
      V<> p(n);
      iota(begin(p), end(p), 0);
      do {
        bool f = true;
        for (int i = 0; i < n; ++i) {
          int j = i + 1;
          while (j < n and p[j] < p[i]) ++j;
          if (nxt[i] != -2 and nxt[i] != j) {
            f = false;
            break;
          }
        }
        if (!f) continue;
        // for (int i = 0; i < n; ++i) cerr << p[i] << " \n"[!(n + ~i)];
        cerr << "p(" << p.size() << ") = {"; for (const auto& e : p) cerr << e + 1 << ", "; cerr << "} (l." << __LINE__ << ")\n";
      } while (next_permutation(begin(p), end(p)));
    }*/
    VV<> g(n + 1);
    for (int i = 0; i < n; ++i) {
      g[i].push_back(n);
      if (0 <= nxt[i] and nxt[i] < n) g[i].push_back(nxt[i]);
    }
    V<> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) { return nxt[i] > nxt[j]; });
    auto itr = begin(idx);
    set<int> se;
    for (int i = n - 1; i >= 0; --i) {
      // if (nxt[*next(itr)] > i) se.insert(*itr);
      // while (next(itr) != end(idx) and nxt[*next(itr)] > i) {
      //   se.insert(*++itr);
      // }
      while (itr != end(idx) and nxt[*itr] > i) {
        se.insert(*itr++);
      }
      if (se.empty()) continue;
      auto nitr = se.lower_bound(i);
      if (nitr == begin(se)) continue;
      g[i].push_back(*prev(nitr));
    }
    // for (int i = 0; i <= n; ++i) {
    //   for (int j : g[i]) cerr << i << ' ' << j << '\n';
    // }
    V<> comp;
    int k = scc(g, comp);
    // if (k < n + 1) cout << -1 << '\n';
    // else {
    //   for (int i = 0; i < n; ++i) {
    //     cout << comp[i] + 1 << " \n"[!(n + ~i)];
    //   }
    // }
    V<> v(begin(comp), end(comp) - 1);
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    if ((int)v.size() < n) cout << -1 << '\n';
    else {
      for (int i = 0; i < n; ++i) {
        cout << lower_bound(begin(v), end(v), comp[i]) - begin(v) + 1 << " \n"[!(n + ~i)];
      }
    }
  }
}