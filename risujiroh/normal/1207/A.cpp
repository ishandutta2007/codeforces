#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int b, p, f; cin >> b >> p >> f;
    int h, c; cin >> h >> c;
    int res = 0;
    for (int i = 0; i <= p; ++i) for (int j = 0; j <= f; ++j) {
      if (2 * i + 2 * j > b) continue;
      res = max(res, i * h + j * c);
    }
    cout << res << '\n';
  }
}