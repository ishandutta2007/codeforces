#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n);
  for (auto&& e : a) cin >> e;
  int mx = *max_element(begin(a), end(a));
  int res = 0, t = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == mx) {
      res = max(res, ++t);
    } else {
      t = 0;
    }
  }
  cout << res << '\n';
}