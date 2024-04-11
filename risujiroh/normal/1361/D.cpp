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
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  vector<int> x(n), y(n);
  vector<double> d(n);
  vector<pair<int, int>> i2p(n);
  map<pair<int, int>, vector<int>> mp;
  int zi = -1;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    d[i] = hypot(x[i], y[i]);
    if (x[i] == 0 and y[i] == 0) {
      zi = i;
      continue;
    }
    auto g = gcd(x[i], y[i]);
    i2p[i] = {x[i] / g, y[i] / g};
    mp[i2p[i]].push_back(i);
  }
  map<pair<int, int>, int> sz;
  for (auto&& [p, v] : mp) {
    sort(begin(v), end(v), [&](int i, int j) {
      return d[i] < d[j];
    });
    sz[p] = size(v);
  }
  priority_queue<pair<double, int>> pq;
  for (auto&& [p, v] : mp) {
    pq.emplace(d[v.back()] * (k - 1), v.back());
  }
  double res = 0;
  for (int r = k; r; --r) {
    if (not empty(pq) and pq.top().first > -1e-10) {
      auto [t, i] = pq.top();
      pq.pop();
      auto&& v = mp[i2p[i]];
      v.pop_back();
      res += t;
      if (not empty(v)) {
        int c = sz[i2p[i]] - size(v);
        pq.emplace(d[v.back()] * (k - 1 - 2 * c), v.back());
      } else {
        mp.erase(i2p[i]);
      }
    } else {
      assert(size(mp) <= 1);
      vector<int> v;
      int c = 0;
      if (not empty(mp)) {
        v = move(begin(mp)->second);
        c = sz[begin(mp)->first] - size(v);
      }
      v.insert(begin(v), zi);
      for (int j = r; j--; ) {
        res += d[v[j]] * (k - 1 - 2 * c);
        ++c;
      }
      break;
    }
  }
  cout << res << '\n';
}