#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    lint x, y; cin >> x >> y;
    if (x - y == 1) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}