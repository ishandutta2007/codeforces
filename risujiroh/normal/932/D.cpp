#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  vector<int> w(q);
  vector nxt(19, vector(q, -1));
  vector sum(19, vector(q, inf<long long>));
  sum[0][0] = 0;
  int v = 1, last = 0;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int r;
      cin >> r >> w[v];
      r ^= last, w[v] ^= last;
      --r;
      if (w[r] >= w[v]) {
        nxt[0][v] = r;
      } else {
        for (int k = 19; k--; ) {
          if (nxt[k][r] == -1 or w[nxt[k][r]] >= w[v]) continue;
          r = nxt[k][r];
        }
        nxt[0][v] = nxt[0][r];
      }
      sum[0][v] = w[v];
      for (int k = 1; k < 19; ++k) {
        if (nxt[k - 1][v] == -1) continue;
        nxt[k][v] = nxt[k - 1][nxt[k - 1][v]];
        sum[k][v] = sum[k - 1][v] + sum[k - 1][nxt[k - 1][v]];
      }
      ++v;
    } else {
      int r;
      long long x;
      cin >> r >> x;
      r ^= last, x ^= last;
      --r;
      int res = 0;
      for (int k = 19; k--; ) {
        if (r == -1) break;
        if (sum[k][r] > x) continue;
        x -= sum[k][r];
        r = nxt[k][r];
        res += 1 << k;
      }
      cout << res << '\n';
      last = res;
    }
  }
}