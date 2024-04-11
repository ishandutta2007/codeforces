#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int tmod(int a) { return (a %= 2520) < 0 ? a + 2520 : a; }

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
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e, e = tmod(e);
  VV<> g(n * 2520);
  auto _ = [](int v, int x) -> int { return v * 2520 + x; };
  V<> m(n);
  VV<> h(n);
  for (int v = 0; v < n; ++v) {
    cin >> m[v];
    for (int i = 0; i < m[v]; ++i) {
      int to; cin >> to, --to;
      h[v].push_back(to);
    }
  }
  for (int v = 0; v < n; ++v) for (int x = 0; x < 2520; ++x) {
    g[_(v, x)].push_back(_(h[v][(x + a[v]) % m[v]], tmod(x + a[v])));
  }

  V<> comp;
  scc(g, comp);
  V< set<int> > se(n * 2520);
  for (int i = 0; i < n * 2520; ++i) {
    se[comp[i]].insert(i / 2520);
  }

  V<> dp(n * 2520);
  for (int i = 0; i < n * 2520; ++i) {
    dp[i] = g[i][0];
  }
  for (int _ = 0; _ < 30; ++_) {
    V<> ndp(n * 2520);
    for (int i = 0; i < n * 2520; ++i) {
      ndp[i] = dp[dp[i]];
    }
    swap(dp, ndp);
  }

  int q; cin >> q;
  while (q--) {
    int v, x; cin >> v >> x, --v, x = tmod(x);
    int res = se[comp[dp[_(v, x)]]].size();
    cout << res << '\n';
  }
}