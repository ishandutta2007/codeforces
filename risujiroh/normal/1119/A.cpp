#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> c(n); for (auto&& e : c) cin >> e;
  int res = -1;
  int i = 0;
  while (c[i] == c.back()) ++i;
  res = max(res, n - 1 - i);
  int j = n - 1;
  while (c[j] == c[0]) --j;
  res = max(res, j);
  cout << res << '\n';
}