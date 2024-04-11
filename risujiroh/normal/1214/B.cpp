#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int b, g, n; cin >> b >> g >> n;
  int res = n + 1;
  for (int i = 0; i <= n; ++i) {
    res -= i > b or n - i > g;
  }
  cout << res << '\n';
}