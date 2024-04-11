#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;
ll x[4], y[4];
int p[4];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 4; ++i) scanf("%lld%lld", x + i, y + i);
    iota(p, p + 4, 0);
    ll res = 1000000000000000000LL;
    do {
      ll D[8], len = 0;
      for (int i : {0, 1})
        for (int j : {2, 3})
          D[len++] = x[p[i]] - x[p[j]];
      for (int i : {0, 2})
        for (int j : {1, 3})
          D[len++] = y[p[i]] - y[p[j]];
      sort(D, D + len);
      ll d = D[3];
      ll tx[4] = {x[p[0]], x[p[1]], x[p[2]] + d, x[p[3]] + d};
      ll ty[4] = {y[p[0]], y[p[1]] + d, y[p[2]], y[p[3]] + d};
      sort(tx, tx + 4); sort(ty, ty + 4);
      res = min(res, tx[2] + tx[3] - tx[0] - tx[1] + ty[2] + ty[3] - ty[0] - ty[1]);
    } while (next_permutation(p, p + 4));
    printf("%lld\n", res);
  }
  return 0;
}