#include <bits/extc++.h>
using namespace std;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  using ll = long long;
  vector<ll> t(n);
  for (auto&& e : t) cin >> e;
  vector<int> h(n);
  for (auto&& e : h) cin >> e;
  vector<vector<int>> g(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<ll> up(n, 1e12), down(n, 1e12);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    ll base = 0;
    vector<ll> delta;
    for (int u : g[v]) {
      if (u == p) continue;
      self(self, u, v);
      base += up[u];
      delta.push_back(down[u] - up[u]);
    }
    sort(begin(delta), end(delta));
    int sz = size(delta);
    if (v and h[v] <= h[p]) {
      ll cur = base;
      int in = sz, out = 1;
      for (ll d : delta) {
        chmin(up[v], cur + t[v] * max(in, out));
        cur += d;
        --in;
        ++out;
      }
      chmin(up[v], cur + t[v] * max(in, out));
    }
    if (v and h[v] >= h[p]) {
      ll cur = base;
      int in = sz + 1, out = 0;
      for (ll d : delta) {
        chmin(down[v], cur + t[v] * max(in, out));
        cur += d;
        --in;
        ++out;
      }
      chmin(down[v], cur + t[v] * max(in, out));
    }
    if (v == 0) {
      ll cur = base;
      int in = sz, out = 0;
      ll res = 1e18;
      for (ll d : delta) {
        chmin(res, cur + t[v] * max(in, out));
        cur += d;
        --in;
        ++out;
      }
      chmin(res, cur + t[v] * max(in, out));
      cout << res << '\n';
    }
  };
  dfs(dfs, 0, - 1);
}