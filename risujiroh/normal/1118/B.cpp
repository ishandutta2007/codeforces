#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<> c(n + 1);
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] + (i & 1 ? -a[i] : a[i]);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += c[i] == (c[n] - c[i + 1]);
  }
  cout << res << '\n';
}