#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    V<> a(n); for (auto&& e : a) cin >> e;
    int res = 0;
    int mn = a.back();
    for (int i = n - 2; i >= 0; --i) {
      res += a[i] > mn;
      mn = min(mn, a[i]);
    }
    cout << res << '\n';
  }
}