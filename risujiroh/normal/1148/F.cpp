#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n), mask(n); for (int i = 0; i < n; ++i) cin >> a[i] >> mask[i];
  if (accumulate(begin(a), end(a), 0LL) < 0) {
    for (auto&& e : a) e = -e;
  }
  V<bool> o(n, true);
  lint res = 0;
  for (int k = 61; k >= 0; --k) {
    lint s = 0, t = 0;
    for (int i = 0; i < n; ++i) if (mask[i] == 1LL << k) {
      if (o[i]) s += a[i];
      else t += a[i];
    }
    if (s > t) {
      res |= 1LL << k;
      for (int i = 0; i < n; ++i) if (mask[i] >> k & 1) {
        o[i] = !o[i];
      }
    }
    for (int i = 0; i < n; ++i) {
      mask[i] &= ~(1LL << k);
    }
  }
  cout << res << '\n';
}