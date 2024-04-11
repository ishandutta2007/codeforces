#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll _gcd(ll a, ll b) {
  if (a == 0) return b;
  return _gcd(b % a, a);
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll _n = n;
  ll _m = m;
  if (k % 2 == 1) {
    if (_gcd(n, k) != 1) {
      n *= 2;
    } else {
      m *= 2;
    }
  } else k /= 2;
  ll g = _gcd(n, k);
  n /= g;
  k /= g;
  if (n > _n || m % k) {
    cout << "NO\n";
    return 0;
  }
  m /= k;
  if (m > _m) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  cout << n << " 0\n";
  cout << "0 " << m << "\n";
  cout << "0 0\n";
}