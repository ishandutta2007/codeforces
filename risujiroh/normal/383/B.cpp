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
  vector<int> x(m), y(m), vx{1, n}, vy{1, n};
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i];
    for (int j = -1; j <= 1; ++j) {
      vx.push_back(clamp(x[i] + j, 1, n));
      vy.push_back(clamp(y[i] + j, 1, n));
    }
  }
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), end(vx));
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), end(vy));
  for (int i = 0; i < m; ++i) {
    x[i] = lower_bound(begin(vx), end(vx), x[i]) - begin(vx);
    y[i] = lower_bound(begin(vy), end(vy), y[i]) - begin(vy);
  }
  int h = size(vx), w = size(vy);
  vector<set<int>> js(h, {-1, w});
  for (int i = 0; i < m; ++i) {
    js[x[i]].insert(y[i]);
  }
  set<int> a, b;
  for (int j = 0; j < w; ++j) {
    (j ? b : a).insert(j);
  }
  for (int i = 0; i < h; ++i) {
    for (auto it = begin(js[i]); *it < w; ++it) {
      if (*it != -1) {
        a.erase(*it);
        b.insert(*it);
      }
      auto ita = a.upper_bound(*it);
      if (ita == end(a) or *ita >= *next(it)) continue;
      for (auto itb = b.upper_bound(*ita); itb != end(b) and *itb < *next(it); ) {
        a.insert(*itb);
        itb = b.erase(itb);
      }
    }
    DEBUG(a);
    DEBUG(b);
  }
  if (a.count(w - 1)) {
    cout << 2 * n - 2 << '\n';
  } else {
    cout << "-1\n";
  }
}