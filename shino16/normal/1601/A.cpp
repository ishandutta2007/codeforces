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

int t, n, a[200000];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    int g = 0;
    rep(b, 30) {
      int cnt = 0;
      rep(i, n) cnt += a[i] >> b & 1;
      g = gcd(g, cnt);
    }
    if (g) {
      rep2(k, 1, g+1) if (g % k == 0)
        printf("%d%c", k, " \n"[k==g]);
    } else rep2(k, 1, n+1)
      printf("%d%c", k, " \n"[k==n]);
  }
}