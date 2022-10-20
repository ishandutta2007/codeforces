#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  int n; cin >> n;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> sz(n);
  VV<> ch(n);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    sz[v] = 1;
    for (int w : g[v]) if (w != p) {
      ch[v].push_back(w);
      dfs(dfs, w, v);
      sz[v] += sz[w];
    }
  };
  dfs(dfs, 0, -1);
  auto fn = [&](const auto& fn, int r) -> void {
    cout << "d " << r + 1 << endl;
    int dep; cin >> dep;
    if (!dep) {
      cout << "! " << r + 1 << endl;
      exit(0);
    }
    int mx = 0;
    for (int v : ch[r]) mx = max(mx, sz[v]);
    if (2 * mx <= sz[r]) {
      cout << "s " << r + 1 << endl;
      int nxt; cin >> nxt, --nxt;
      fn(fn, nxt);
      return;
    }
    int v = r;
    V<> vs;
    while (true) {
      vs.push_back(v);
      int nv = -1;
      for (int w : ch[v]) {
        if (nv == -1 or sz[w] > sz[nv]) nv = w;
      }
      if (nv != -1 and 2 * sz[nv] > sz[v]) v = nv;
      else break;
    }
    int len = vs.size() - 1;
    cout << "d " << vs.back() + 1 << endl;
    int dist; cin >> dist;
    if (dep + dist == len) {
      cout << "! " << vs[dep] + 1 << endl;
      exit(0);
    } else if (len + dist == dep) {
      fn(fn, vs.back());
    } else {
      int a = dep + len - dist;
      assert(~a & 1);
      // fn(fn, vs[a / 2]);
      cout << "s " << vs[a / 2] + 1 << endl;
      int nxt; cin >> nxt, --nxt;
      fn(fn, nxt);
    }
  };
  fn(fn, 0);
}