#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int m, n; cin >> m >> n;
  V< bitset<10000> > bs(m);
  for (int i = 0; i < m; ++i) {
    int k; cin >> k;
    while (k--) {
      int j; cin >> j, --j;
      bs[i][j] = true;
    }
  }
  for (int i = 0; i < m; ++i) for (int j = 0; j < i; ++j) {
    if (!(bs[i] & bs[j]).count()) return cout << "impossible" << '\n', 0;
  }
  cout << "possible" << '\n';
}