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
#line 2 "main.cpp"

int t, n, e, a[200000];
bool prime[1000001];
int l[200000], r[200000];

int main() {
  fill(prime+2, end(prime), true);
  for (int p = 2; p * p < size(prime); p++)
    if (prime[p])
      for (int q = p * p; q < size(prime); q += p)
        prime[q] = false;

  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &e);
    rep(i, n) scanf("%d", a+i);
    ll ans = 0;
    fill(l, l+n, 0);
    fill(r, r+n, 0);
    rep(b, e) {
      int now = 0;
      int i;
      for (i = b; i < n; i += e)
        if (a[i] == 1) now++;
        else l[i] = now, now = 0;
      now = 0;
      for (i -= e; i >= 0; i -= e)
        if (a[i] == 1) now++;
        else r[i] = now, now = 0;
    }
    rep(i, n) if (prime[a[i]]) ans += 1LL * (l[i]+1) * (r[i]+1) - 1;
    printf("%lld\n", ans);
  }
}