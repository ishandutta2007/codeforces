#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> b(n);
    for (int& e : b) cin >> e;
    vector<array<int, 2>> segments(m);
    vector<vector<int>> g(n + 1);
    for (int e = 0; e < m; ++e) {
      auto&& [l, r] = segments[e];
      cin >> l >> r;
      --l;
      g[l].push_back(e);
      g[r].push_back(e);
    }

    using i64 = long long;

    vector<i64> h(n + 1);
    for (int i = 0; i < n; ++i) {
      h[i + 1] = h[i] + (a[i] - b[i]);
    }

    if (h[n]) {
      cout << "NO\n";
      continue;
    }

    set<int> rest;
    for (int i = 1; i < n; ++i) {
      if (h[i]) {
        rest.insert(end(rest), i);
      }
    }

    queue<int> q;
    vector<bool> done(m);
    for (int e = 0; e < m; ++e) {
      auto [l, r] = segments[e];
      if (h[l] == 0 && h[r] == 0) {
        done[e] = true;
        q.push(e);
      }
    }

    while (!empty(q)) {
      int e = q.front();
      q.pop();
      auto [l, r] = segments[e];
      for (auto it = rest.lower_bound(l); it != end(rest) && *it <= r; ++it) {
        h[*it] = 0;
      }
      for (auto it = rest.lower_bound(l); it != end(rest) && *it <= r;
           it = rest.erase(it)) {
        for (int i : g[*it]) {
          if (done[i]) {
            continue;
          }
          if (h[segments[i][0]] == 0 && h[segments[i][1]] == 0) {
            done[i] = true;
            q.push(i);
          }
        }
      }
    }

    cout << (empty(rest) ? "YES\n" : "NO\n");
  }
}