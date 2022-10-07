#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

ll mn, mx;
void go(ll m) {
  for (int i = 0; i < n; ++i) {
    ll val = n * k / gcd(n * k + i * k + m, n * k);
    if (val < mn) mn = val;
    if (val > mx) mx = val;
  }
}

int main() {
  int a, b;
  cin >> n >> k;
  cin >> a >> b;
  mn = n * k;
  mx = 0;

  go(a + b);
  go(a - b);
  go(-a + b);
  go(-a - b);
  cout << mn << " " << mx << "\n";
}