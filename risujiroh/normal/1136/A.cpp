#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> l(n), r(n); for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
  int k; cin >> k;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += k <= r[i];
  }
  cout << res << '\n';
}