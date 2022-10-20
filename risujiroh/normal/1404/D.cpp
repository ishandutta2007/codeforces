#include <bits/extc++.h>

using namespace std;

struct bipartite_matching {
  vector<vector<int>> g;
  vector<int> r, c, vis;
  int t = 0;
  bipartite_matching(int h = 0, int w = 0) : g(h), r(h, -1), c(w, -1), vis(h) {}
  void add(int i, int j) { g[i].push_back(j); }
  bool dfs(int i) {
    if (exchange(vis[i], t) == t) return false;
    for (int j : g[i])
      if (c[j] == -1) return r[i] = j, c[j] = i, true;
    for (int j : g[i])
      if (dfs(c[j])) return r[i] = j, c[j] = i, true;
    return false;
  }
  int run() {
    for (bool updated = true; ++t, exchange(updated, false);)
      for (int i = r.size(); i--;)
        if (r[i] == -1) updated |= dfs(i);
    return r.size() - count(begin(r), end(r), -1);
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "First" << endl;
    for (int i = 0; i < 2 * n; ++i) {
      if (i) cout << ' ';
      cout << i % n + 1;
    }
    cout << endl;
    exit(0);
  }
  cout << "Second" << endl;
  vector<int> p(2 * n);
  for (auto&& e : p) cin >> e, --e;
  vector<vector<int>> v(n);
  for (int i = 0; i < 2 * n; ++i) {
    v[p[i]].push_back(i);
  }
  bipartite_matching bm(n, n);
  for (int i = 0; i < 2 * n; ++i) {
    bm.add(i % n, p[i]);
  }
  int mx = bm.run();
  assert(mx == n);
  vector<bool> b(2 * n);
  int64_t sum{};
  for (int i = 0; i < 2 * n; ++i) {
    if (i >= n and p[i - n] == p[i]) continue;
    b[i] = bm.r[i % n] == p[i];
    if (b[i]) sum += i + 1;
  }
  if (sum % (2 * n) == 0) {
    for (int i = 0; i < 2 * n; ++i)
      if (b[i]) cout << i + 1 << ' ';
  } else {
    for (int i = 0; i < 2 * n; ++i)
      if (not b[i]) cout << i + 1 << ' ';
  }
  cout << endl;
}