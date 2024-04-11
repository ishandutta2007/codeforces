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
  vector<long long> head(31);
  for (int i = 0; i <= 30; ++i) {
    head[i] = (1LL << 2 * i) - 1;
  }
  DEBUG(head);
  while (tt--) {
    long long k;
    cin >> k;
    --k;
    int i = upper_bound(begin(head), end(head), k) - begin(head) - 1;
    k -= head[i];
    long long res = 0;
    res |= (k % 3 + 1LL) << 2 * i;
    while (i) {
      int q = k / (3LL << 2 * (i - 1));
      assert(0 <= q and q < 4);
      k -= q * (3LL << 2 * (i - 1));
      if (q == 1) {
        res |= (k % 3 + 1LL) << 2 * (i - 1);
      } else if (q == 2) {
        res |= ((k + 1) % 3 + 1LL) << 2 * (i - 1);
      } else if (q == 3) {
        res |= ((k + 2) % 3 + 1LL) << 2 * (i - 1);
      }
      --i;
    }
    cout << res << '\n';
  }
}