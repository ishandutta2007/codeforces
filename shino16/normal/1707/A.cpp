#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 2 "lib/math/int/bisect.hpp"

template <class I, class F>
I bisect(I l, I r, F p) {
  while (l != r) {
    I m = ((l ^ r) >> 1) + (l & r);
    if (p(m)) l = m + 1;
    else r = m;
  }
  return l;
}
#line 3 "main.cpp"

int n, q, a[100000];
char ans[100001];

void solve() {
  scanf("%d%d", &n, &q);
  rep(i, n) scanf("%d", a + i);

  int T = bisect(0, n-1, [](int t) {
    int qx = q;
    rep2(i, t, n-1) qx -= a[i] > qx;
    return qx <= 0;
  });
  rep(i, T) ans[i] = '0' + (a[i] <= q);
  rep2(i, T, n) {
    assert(q > 0);
    ans[i] = '1';
    q -= a[i] > q;
  }
  ans[n] = 0;
  printf("%s\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}