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
    auto mex = [&] {
      bitset<1 << 10> bs;
      bs.set();
      for (auto e : a) {
        bs[e] = 0;
      }
      return (int)bs._Find_first();
    };
    vector<int> res;
    while (true) {
      int v = mex();
      if (v == n) {
        int idx = -1;
        for (int i = 0; i < n; ++i) {
          if (a[i] != i) {
            idx = i;
            break;
          }
        }
        if (idx == -1) break;
        res.push_back(idx);
        a[idx] = v;
        continue;
      }
      res.push_back(v);
      a[v] = v;
    }
    int k = size(res);
    cout << k << '\n';
    for (int i = 0; i < k; ++i) {
      cout << res[i] + 1 << " \n"[i == k - 1];
    }
  }
}