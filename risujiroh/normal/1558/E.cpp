#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int v = 1; v < n; ++v) {
      cin >> a[v];
    }
    vector<int> b(n);
    for (int v = 1; v < n; ++v) {
      cin >> b[v];
    }
    vector<vector<int>> g(n);
    while (m--) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    auto check = [&](int start) -> bool {
      vector<int64_t> pw(n);

      vector<bool> vis(n);
      vector<int> pv(n);
      bool done;

      vector<bool> f(n);
      f[0] = true;

      auto dfs = [&](auto self, int v) -> void {
        if (done) return;
        for (int u : g[v]) {
          if (done) continue;
          if (u == pv[v]) {
            continue;
          }
          if (pw[v] <= a[u]) {
            continue;
          }
          if (vis[u]) {
            done = true;
            for (int t = v; !f[t]; t = pv[t]) {
              f[t] = true;
            }
            for (int t = u; !f[t]; t = pv[t]) {
              f[t] = true;
            }
            continue;
          }

          vis[u] = true;
          pw[u] = pw[v] + b[u];
          pv[u] = v;
          self(self, u);
        }
      };

      while (find(begin(f), end(f), false) != end(f)) {
        bool upd = false;
        [&] {
          vis = f;
          pw[0] = start;
          for (int v = 0; v < n; ++v) {
            if (f[v]) {
              pw[0] += b[v];
            } else {
              pw[v] = 0;
            }
          }
          for (int v = 0; v < n; ++v) {
            if (f[v]) {
              pw[v] = pw[0];
            }
          }
          for (int v = 0; v < n; ++v) {
            if (f[v]) {
              for (int u : g[v]) {
                if (!f[u] && pw[v] > a[u]) {
                  done = false;
                  vis[u] = true;
                  pw[u] = pw[v] + b[u];
                  pv[u] = v;
                  dfs(dfs, u);
                  if (!done) continue;
                  upd = true;
                  return;
                }
              }
            }
          }
        }();
        if (!upd) return false;
      }
      return true;
    };

    int ng = 1, ok = 1e9 + 1;
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      (check(mid) ? ok : ng) = mid;
    }
    cout << ok << '\n';
  }
}