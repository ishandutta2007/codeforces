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
  vector a(n, vector(m, 0));
  for (auto&& v : a) {
    for (auto&& e : v) {
      cin >> e;
    }
  }
  bool swapped = false;
  if (n > m) {
    vector na(m, vector(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        na[j][i] = a[i][j];
      }
    }
    swap(a, na);
    swap(n, m);
    swapped = true;
  }
  vector<pair<string, int>> res;
  for (int i = 0; i < n; ++i) {
    while (*min_element(begin(a[i]), end(a[i]))) {
      res.emplace_back("row", i);
      for (int j = 0; j < m; ++j) {
        --a[i][j];
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    while (true) {
      int mn = 1e9;
      for (int i = 0; i < n; ++i) {
        mn = min(mn, a[i][j]);
      }
      if (mn == 0) break;
      res.emplace_back("col", j);
      for (int i = 0; i < n; ++i) {
        --a[i][j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j]) {
        cout << "-1\n";
        exit(0);
      }
    }
  }
  cout << size(res) << '\n';
  for (auto [s, x] : res) {
    if (swapped) {
      s = s == "row" ? "col" : "row";
    }
    cout << s << ' ' << x + 1 << '\n';
  }
}