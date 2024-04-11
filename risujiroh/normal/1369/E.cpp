#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> w(n);
  for (auto&& e : w) cin >> e;
  vector<int> x(m), y(m);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
    --w[x[i]];
    --w[y[i]];
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  priority_queue<pair<int, int>> pq;
  for (int v = 0; v < n; ++v) {
    pq.emplace(w[v], v);
  }
  vector<bool> used(m);
  vector<int> res;
  while (not empty(pq)) {
    auto [wv, v] = pq.top();
    pq.pop();
    if (wv != w[v]) continue;
    if (wv < 0) break;
    for (int i : g[v]) {
      if (used[i]) continue;
      used[i] = true;
      res.push_back(i);
      int to = x[i] ^ y[i] ^ v;
      ++w[to];
      pq.emplace(w[to], to);
    }
  }
  if ((int)size(res) < m) {
    cout << "DEAD\n";
  } else {
    cout << "ALIVE\n";
    for (int i = m; i--; ) {
      cout << res[i] + 1 << " \n"[i == 0];
    }
  }
}