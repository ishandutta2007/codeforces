#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<bool> b(n - 1);
  V<> t(m), l(m), r(m);
  for (int j = 0; j < m; ++j) {
    cin >> t[j] >> l[j] >> r[j], --l[j], --r[j];
    if (t[j]) {
      for (int i = l[j]; i < r[j]; ++i) {
        b[i] = true;
      }
    }
  }
  for (int j = 0; j < m; ++j) if (!t[j]) {
    bool ok = false;
    for (int i = l[j]; i < r[j]; ++i) if (!b[i]) {
      ok = true;
      break;
    }
    if (!ok) return cout << "NO" << '\n', 0;
  }
  cout << "YES" << '\n';
  V<> a(n);
  a[0] = 2 * n;
  for (int i = 0; i < n - 1; ++i) {
    a[i + 1] = a[i] - !b[i];
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[!(n + ~i)];
  }
}