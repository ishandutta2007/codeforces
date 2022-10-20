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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    set<int> se(begin(a), end(a));
    if (size(se) > k) {
      cout << "-1\n";
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      if ((int)size(se) == k) break;
      se.insert(i);
    }
    vector<int> res;
    for (int _ = n; _--; ) {
      res.insert(end(res), begin(se), end(se));
    }
    int m = size(res);
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << res[i] << " \n"[i == m - 1];
    }
  }
}