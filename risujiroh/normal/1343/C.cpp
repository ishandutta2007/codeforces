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
    for (auto && e : a) {
      cin >> e;
    }
    vector<int> p{0};
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] < 0 ^ a[i] < 0) {
        p.push_back(i);
      }
    }
    p.push_back(n);
    auto res = 0LL;
    for (int t = 0; t < (int)size(p) - 1; ++t) {
      res += *max_element(begin(a) + p[t], begin(a) + p[t + 1]);
    }
    cout << res << '\n';
  }
}