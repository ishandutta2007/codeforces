#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  if (k == 1) {
    if (a == b) {
      cout << "NO\n";
    } else if ((a % b) && (b % a)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
    return;
  }
  int c = a, o = 0;
  while (c % 2 == 0) {
    c /= 2;
    o++;
  }  for (int p = 3; p * p <= c; p+=2) {
    while (c % p == 0) {
      c /= p;
      o++;
    }
  }
  if (c > 1) o++;
  int d = b, oo = 0;
  while (d % 2 == 0) {
    d /= 2;
    oo++;
  }
  for (int p = 3; p * p <= d; p+=2) {
    while (d % p == 0) {
      d /= p;
      oo++;
    }
  }
  if (d > 1) oo++;
  if (oo + o >= k) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}