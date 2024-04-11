#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  int p = 0, m = 0;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    p += a > 0;
    m += a < 0;
  }
  int res = 0;
  if (p >= n + 1 >> 1) res = 1;
  if (m >= n + 1 >> 1) res = -1;
  cout << res << '\n';
}