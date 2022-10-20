#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  using i64 = long long;

  int n, m;
  i64 k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int& e : a) cin >> e;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }

  auto check = [&](int th) -> bool {
    vector<int> indeg(n);
    int num_vertices = 0;
    for (int v : views::iota(0, n)) {
      if (th < a[v]) continue;
      ++num_vertices;
      for (int u : g[v]) {
        if (th < a[u]) continue;
        ++indeg[u];
      }
    }

    vector<int> q;
    q.reserve(num_vertices);
    for (int v : views::iota(0, n)) {
      if (th < a[v]) continue;
      if (indeg[v] == 0) {
        q.push_back(v);
      }
    }

    vector<int> vs;
    vs.reserve(num_vertices);
    for (int z = 0; z < int(size(q)); ++z) {
      int v = q[z];
      vs.push_back(v);
      for (int u : g[v]) {
        if (th < a[u]) continue;
        --indeg[u];
        if (indeg[u] == 0) {
          q.push_back(u);
        }
      }
    }

    if (int(size(vs)) < num_vertices) {
      return true;
    }

    vector<int> f(n);
    for (int v : vs) {
      if (th < a[v]) continue;
      f[v] = max(f[v], 1);
      if (k <= f[v]) {
        return true;
      }
      for (int u : g[v]) {
        if (th < a[u]) continue;
        f[u] = max(f[u], f[v] + 1);
      }
    }

    return false;
  };

  int max_a = *max_element(begin(a), end(a));

  int ng = 0, ok = max_a + 1;
  while (ng + 1 < ok) {
    int mid = (ng + ok) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << (max_a < ok ? -1 : ok) << '\n';
}