#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i != (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)

int t; ll x, y;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &x, &y);
    ll n = y >= x ? y / x * x + (y % x) / 2 : ll(1e9) * x + y;
    printf("%lld\n", n);
    assert(n % x == y % n);
  }
}