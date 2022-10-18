#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, m;
ll a[200000], x, y, sum;

int main() {
  scanf("%d", &n);
  rep(i, n) scanf("%lld", a+i);
  sort(a, a+n);
  sum = accumulate(a, a+n, 0LL);
  scanf("%d", &m);
  while (m--) {
    scanf("%lld%lld", &x, &y);
    auto itr = lower_bound(a, a+n, x);
    ll ans = LONG_LONG_MAX;
    if (itr != a+n) ans = max(0LL, y - (sum - *itr));
    if (itr != a) ans = min(ans, x - itr[-1] + max(0LL, y - (sum - itr[-1])));
    printf("%lld\n", ans);
  }
}