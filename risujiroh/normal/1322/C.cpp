#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    vector<vector<int>> g(n);
    while (m--) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[v].push_back(u);
    }
    map<vector<int>, long long> mp;
    for (int v = 0; v < n; ++v) {
      if (g[v].empty()) {
        continue;
      }
      sort(begin(g[v]), end(g[v]));
      mp[g[v]] += a[v];
    }
    long long res = 0;
    for (const auto& e : mp) {
      res = __gcd(res, e.second);
    }
    cout << res << '\n';
  }
}