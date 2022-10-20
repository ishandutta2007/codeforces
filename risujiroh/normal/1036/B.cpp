#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int q; cin >> q;
  for (int iq = 0; iq < q; iq++) {
    lint x, y, k; cin >> x >> y >> k;
    if (max(x, y) > k) cout << -1 << '\n';
    else {
      if (x + y & 1LL) {
        cout << k - 1 << '\n';
      } else {
        if (k - max(x, y) & 1) cout << k - 2 << '\n';
        else cout << k << '\n';
      }
    }
  }
}