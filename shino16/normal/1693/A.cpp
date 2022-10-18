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

int n, a[200000];

void solve() {
  scanf("%d", &n);
  rep(i, n) scanf("%d", a+i);
  while (n > 0 && a[n-1] == 0) n--;
  if (n == 0) {
    printf("Yes\n");
    return;
  }
  a[0]--, a[n-1]++;
  ll tot = 0;
  bool fail = false;
  rep(i, n) {
    tot += a[i];
    fail |= tot < 0;
  }
  printf("%s\n", !fail && tot == 0 ? "Yes" : "No");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}