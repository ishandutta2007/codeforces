#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      int a; cin >> a;
      x += a % 3 == 1;
      y += a % 3 == 2;
    }
    int res = n - x - y;
    if (x < y) swap(x, y);
    res += y;
    res += (x - y) / 3;
    cout << res << '\n';
  }
}