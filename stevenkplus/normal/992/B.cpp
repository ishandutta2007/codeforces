// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

// _gcd: a, b non-negative integers
ll _gcd(ll a, ll b) {
  if (a == 0) return b;
  return _gcd(b % a, a);
}

// =========== Solution ============= //

int main(){
  int l, r, x, y;
  cin >> l >> r >> x >> y;
  if (y % x != 0) { cout << "0\n"; return 0; }
  y /= x;
  l = (l + x - 1) / x;
  r /= x;
  int ans = 0;
  for (int i = l; i <= (y / i); ++i) {
    if (y % i == 0) {
      int j = y / i;
      if (j <= r && _gcd(i, j) == 1) {
        ++ans;
        if (i != j) ++ans;
      }
    }
  }
  cout << ans << "\n";
}