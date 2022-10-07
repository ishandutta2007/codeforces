#include <iostream>
using namespace std;

typedef long long ll;
ll n, k, m, d;

int main() {
  cin >> n >> k >> m >> d;

  ll ans = 0;
  while (--d >= 0) {
    if (k * double(d) > 1E18) {
      continue;
    }
    ll x = n / (k * d + 1);
    if (x > m) x = m;
    ll val = x * (d + 1);
    if (val > ans) ans = val;
  }

  cout << ans;
}