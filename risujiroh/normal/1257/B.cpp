#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    if (x >= 4) {
      cout << "YES" << '\n';
    } else if (x == 1) {
      cout << (y == 1 ? "YES" : "NO") << '\n';
    } else {
      cout << (y <= 3 ? "YES" : "NO") << '\n';
    }
  }
}