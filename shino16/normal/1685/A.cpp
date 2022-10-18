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

int n, a[100000], b[100000];

void solve() {
  scanf("%d", &n);
  rep(i, n) scanf("%d", a+i);
  if (n % 2) return printf("NO\n"), void();
  sort(a, a+n);
  rep(i, n/2) b[i*2] = a[i];
  rep(i, n/2) b[i*2+1] = a[i+n/2];
  bool fail = false;
  rep(i, n-1) fail |= b[i] == b[i+1];
  if (fail) return printf("NO\n"), void();
  printf("YES\n");
  rep(i, n) printf("%d%c", b[i], " \n"[i==n-1]);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}