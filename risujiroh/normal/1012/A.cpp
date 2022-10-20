#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(2 * n); for (int i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  lint res = (lint) (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  for (int i = 1; i < n; i++) {
    res = min(res, (lint) (a[i + n - 1] - a[i]) * (a[2 * n - 1] - a[0]));
  }
  cout << res << '\n';
}