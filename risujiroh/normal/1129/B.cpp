#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint k; cin >> k;
  if (k + 2 < 1e6) {
    cout << 2 << '\n';
    cout << "-1 " << k + 2 << '\n';
    return 0;
  }
  int n = 2000;
  lint x = -k, y = k;
  while (x + n < 1e6) {
  // while (x + y < 1 - n) {
    x += n;
    y -= n - 1;
  }
  V<lint> a(n);
  a[n - 1] = x;
  a[n - 2] = y;
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
    assert(abs(a[i]) <= 1e6);
  }
  V<lint> c(n + 1);
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] + a[i];
  }
  lint res = -1e18;
  int ll, rr;
  for (int l = 0; l < n; ++l) for (int r = l + 1; r <= n; ++r) {
    // res = max(res, (c[r] - c[l]) * (r - l));
    if (res < (c[r] - c[l]) * (r - l)) {
      res = (c[r] - c[l]) * (r - l);
      ll = l;
      rr = r;
    }
  }
  cerr << x << ' ' << y << '\n';
  cerr << ll << ' ' << rr << '\n';
  cerr << abs(res - a[n - 1]) << '\n';
  cerr << abs(c[n] * n - a[n - 1]) << '\n';
  // assert(abs(res - x) == k);
}