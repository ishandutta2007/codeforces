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
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  vector<int> res(n + 1);
  for (int v = 1; v < n; ++v) {
    for (int k = 1; k < min(500, n); ++k) {
      if (a[v] < a[(v - 1) / k]) {
        ++res[k];
        --res[k + 1];
      }
    }
    for (int p = 0; p < min(500, v); ++p) {
      if (a[p] <= a[v]) continue;
      int l = max((v + p) / (p + 1), 500);
      int r = p ? (v + p - 1) / p : n;
      if (l >= r) continue;
      ++res[l];
      --res[r];
    }
  }
  for (int k = 1; k < n; ++k) {
    cout << res[k] << " \n"[k == n - 1];
    res[k + 1] += res[k];
  }
}