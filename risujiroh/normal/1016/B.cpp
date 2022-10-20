#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  if (n < m) {
    for (int i = 0; i < q; i++) cout << 0 << '\n';
    return 0;
  }
  string s, t; cin >> s >> t;
  V<bool> a(n - m + 1); for (int i = 0; i < n - m + 1; i++) a[i] = s.substr(i, m) == t;
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r, l--;
    int res = 0;
    for (int j = l; j < r; j++) res += j <= r - m and a[j]; 
    cout << res << '\n';
  }
}