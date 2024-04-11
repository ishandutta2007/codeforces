#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> x(1, 0), y(1, 0);
  while (n--) {
    int _x, _y; cin >> _x >> _y;
    if (_x == x.back() and _y == y.back()) continue;
    x.push_back(_x);
    y.push_back(_y);
  }
  n = x.size();
  int res = 1;
  for (int i = 0; i < n - 1; ++i) {
    res += max(min(x[i + 1], y[i + 1]) - max(x[i], y[i]) + 1, 0);
    res -= x[i] == y[i];
  }
  cout << res << '\n';
}