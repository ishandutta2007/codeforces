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
    int s = accumulate(begin(a), end(a), 0, bit_xor<>());
    if (s == 0) {
      cout << "DRAW\n";
    } else {
      int k = __lg(s);
      vector<int> cnt(2);
      for (auto e : a) {
        ++cnt[e >> k & 1];
      }
      assert(cnt[1] & 1);
      if (cnt[0] & 1 or cnt[1] % 4 == 1) {
        cout << "WIN\n";
      } else {
        cout << "LOSE\n";
      }
    }
  }
}