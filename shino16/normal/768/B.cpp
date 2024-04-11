#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll n, l, r;

int main() {
  scanf("%lld%lld%lld", &n, &l, &r);
  l--;
  ll ans = 0;
  int j = 64 - __builtin_clzll(n);
  rep(i, j) {
    int b = n >> (j - i - 1) & 1;
    ll x = 1LL << i;
    ll m = x * 2;
    auto f = [&](ll r) { return r / m + (r % m >= x); };
    ans += b * (f(r) - f(l));
  }
  printf("%lld\n", ans);
}