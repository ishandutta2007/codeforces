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
template <class T>
auto ndvec(size_t n, T&& x) { return vector(n, forward<T>(x)); }
template <class... Ts>
auto ndvec(size_t n, Ts&&... xs) { return vector(n, forward<Ts>(xs)...); }
#line 2 "main.cpp"

int n, a[100], b[100];
void solve() {
  scanf("%d", &n);
  rep(i, n) scanf("%d", &a[i]);
  rep(i, n) scanf("%d", &b[i]);
  sort(a, a+n);
  sort(b, b+n);
  bool fail = false;
  rep(i, n) fail |= b[i]-a[i] < 0 || b[i]-a[i] > 1;
  printf("%s\n", !fail ? "Yes" : "No");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}