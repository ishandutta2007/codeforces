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

int n, a[5000];

int main() {
  scanf("%d", &n);
  rep(i, n) scanf("%d", &a[i]);
  ll ans = LLONG_MAX;
  rep(i, n) {
    ll cnt = 0;
    ll t = 0;
    repr(j, i) {
      ll d = (-t) / a[j] + 1;
      cnt += d;
      t = -a[j] * d;
    }
    t = 0;
    rep2(j, i+1, n) {
      ll d = t / a[j] + 1;
      cnt += d;
      t = a[j] * d;
    }
    ans = min(ans, cnt);
  }
  printf("%lld\n", ans);
}