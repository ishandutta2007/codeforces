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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  vector<vector<int>> v(n);
  int invs = 0;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      if (a[i] > a[j]) {
        v[i].push_back(j);
        ++invs;
      }
    }
  }
  cout << invs << '\n';
  for (int i = 0; i < n; ++i) {
    sort(begin(v[i]), end(v[i]), [&](int j, int k) {
      return a[j] > a[k];
    });
    for (int j : v[i]) {
      swap(a[i], a[j]);
      cout << i + 1 << ' ' << j + 1 << '\n';
    }
  }
}