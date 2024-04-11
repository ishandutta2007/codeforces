#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n), b(n); for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return (a[i] - b[i]) > (a[j] - b[j]); });
  lint res = 0;
  for (int j = 0; j < n; ++j) {
    int i = idx[j];
    res += a[i] * j + b[i] * (n - 1 - j);
  }
  cout << res << '\n';
}