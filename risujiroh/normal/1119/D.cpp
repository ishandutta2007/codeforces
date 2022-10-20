#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  a.erase(unique(begin(a), end(a)), end(a));
  n = a.size();
  V<lint> d(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    d[i] = a[i + 1] - a[i];
  }
  sort(begin(d), end(d));
  V<lint> c(n);
  for (int i = 0; i < n - 1; ++i) {
    c[i + 1] = c[i] + d[i];
  }
  int q; cin >> q;
  while (q--) {
    lint l, r; cin >> l >> r;
    lint w = r - l + 1;
    lint res = a.back() + w - a[0];
    int i = upper_bound(begin(d), end(d), w) - begin(d);
    res -= c[n - 1] - c[i] - (n - 1 - i) * w;
    cout << res << " \n"[!q];
  }
}