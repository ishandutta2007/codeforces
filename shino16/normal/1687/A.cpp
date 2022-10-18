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

int n, k, a[200001];
ll sum[200001];

ll solve_a() {
  ll ans = accumulate(a, a+n, 0LL);
  ll d = 0;
  rep2(i, 1, n) d += i * 2;
  ans += d * (k / (n-1) - 1);
  k = k % (n-1);
  rep(i, k) ans += i;
  rep2(i, 1, k) ans += i * 2;
  rep2(i, k, n) ans += i + k - 1;
  return ans;
}

ll solve_b() {
  exclusive_scan((int*)a, a+n+1, (ll*)sum, 0LL);
  ll maxi = 0;
  rep(i, n-k+1) maxi = max(maxi, sum[i+k]-sum[i]);
  rep(i, k) maxi += i;
  return maxi;
}

void solve() {
  scanf("%d%d", &n, &k);
  rep(i, n) scanf("%d", a+i);
  if (n == 1) printf("%d\n", a[0] + k - 1);
  else if (k >= n) {
    printf("%lld\n", solve_a());
  } else {
    printf("%lld\n", solve_b());
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}