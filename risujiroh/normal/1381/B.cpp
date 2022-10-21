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
    vector<int> p(2 * n);
    for (auto&& e : p) cin >> e;
    int r = 2 * n;
    bitset<2001> bs;
    bs[0] = 1;
    while (r) {
      int mi = max_element(begin(p), begin(p) + r) - begin(p);
      bs |= bs << (r - mi);
      r = mi;
    }
    cout << (bs[n] ? "YES\n" : "NO\n");
  }
}