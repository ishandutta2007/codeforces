#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int a, b, c; cin >> a >> b >> c;
    int res = 0;
    for (int x = 0; x <= 100; ++x) for (int y = 0; y <= 100; ++y) {
      if (x > a) continue;
      if (2 * x + y > b) continue;
      if (2 * y > c) continue;
      res = max(res, 3 * (x + y));
    }
    cout << res << '\n';
  }
}