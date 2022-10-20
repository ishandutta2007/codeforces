#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int c, m, x; cin >> c >> m >> x;
    int res = min({c, m, (c + m + x) / 3});
    cout << res << '\n';
  }
}