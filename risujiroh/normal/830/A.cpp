#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct bipartite_matching {
  vector<vector<int>> g;
  vector<int> r, c, vis;
  int t = 0;
  bipartite_matching(int h = 0, int w = 0) : g(h), r(h, -1), c(w, -1), vis(h) {}
  void add(int i, int j) { g[i].push_back(j); }
  bool dfs(int i) {
    if (exchange(vis[i], t) == t) return false;
    for (int j : g[i]) if (c[j] == -1) return r[i] = j, c[j] = i, true;
    for (int j : g[i]) if (dfs(c[j])) return r[i] = j, c[j] = i, true;
    return false;
  }
  int run() {
    for (bool updated = true; ++t, exchange(updated, false); )
      for (int i = r.size(); i--; ) if (r[i] == -1) updated |= dfs(i);
    return r.size() - count(begin(r), end(r), -1);
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> a(n), b(k);
  for (auto&& e : a) cin >> e;
  for (auto&& e : b) cin >> e;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  auto chk = [&](long long m) {
    bipartite_matching bm(n, k);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        if (abs(a[i] - b[j]) + abs(b[j] - p) <= m) {
          bm.add(i, j);
        }
      }
    }
    return bm.run() == n;
  };
  long long ng = -1, ok = 1e10;
  while (ok - ng > 1) {
    auto mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}