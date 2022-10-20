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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (i and i + 1 < n and ((a[i - 1] < a[i] and a[i] < a[i + 1]) or (a[i - 1] > a[i] and a[i] > a[i + 1]))) continue;
      res.push_back(a[i]);
    }
    int m = size(res);
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << res[i] << " \n"[i == m - 1];
    }
  }
}