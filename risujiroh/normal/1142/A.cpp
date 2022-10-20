#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> Z gcd(Z a, Z b) {
  while (b) swap(a %= b, b);
  return a;
}
lint tmod(lint a, lint p) { return (a %= p) < 0 ? a + p : a; }

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n, k; cin >> n >> k;
  lint a, b; cin >> a >> b;
  lint mn = 9e18, mx = -9e18, l;
  for (lint i = 0; i < n; ++i) {
    l = i * k + b - a;
    l = tmod(l, n * k);
    mn = min(mn, n * k / gcd(n * k, l));
    mx = max(mx, n * k / gcd(n * k, l));
    l = i * k + b + a;
    l = tmod(l, n * k);
    mn = min(mn, n * k / gcd(n * k, l));
    mx = max(mx, n * k / gcd(n * k, l));
    l = i * k - b - a;
    l = tmod(l, n * k);
    mn = min(mn, n * k / gcd(n * k, l));
    mx = max(mx, n * k / gcd(n * k, l));
    l = i * k - b + a;
    l = tmod(l, n * k);
    mn = min(mn, n * k / gcd(n * k, l));
    mx = max(mx, n * k / gcd(n * k, l));
  }
  cout << mn << ' ' << mx << '\n';
}