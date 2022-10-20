#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    lint n, m; cin >> n >> m;
    lint res = 0;
    for (int r = 1; r < 10; ++r) if (n >= r * m) {
      res += (r * m % 10) * ((n - r * m) / (10 * m) + 1);
    }
    cout << res << '\n';
  }
}