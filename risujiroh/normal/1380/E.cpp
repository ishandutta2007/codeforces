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
  vector<set<int>> se(m);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    --t;
    se[t].insert(i);
  }
  int res = n - 1;
  for (int t = 0; t < m; ++t) {
    for (auto it = begin(se[t]); it != end(se[t]); ++it) {
      res -= next(it) != end(se[t]) and *it + 1 == *next(it);
    }
  }
  cout << res << '\n';
  while (m-- > 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (size(se[a]) < size(se[b])) {
      swap(se[a], se[b]);
    }
    for (int e : se[b]) {
      auto it = se[a].lower_bound(e);
      res -= it != end(se[a]) and e + 1 == *it;
      res -= it != begin(se[a]) and *prev(it) + 1 == e;
    }
    se[a].merge(se[b]);
    set<int>().swap(se[b]);
    cout << res << '\n';
  }
}