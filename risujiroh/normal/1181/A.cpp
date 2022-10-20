#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint x, y, z; cin >> x >> y >> z;
  lint res = 0;
  if (x / z + y / z < (x + y) / z) {
    res = min(z - x % z, z - y % z);
  }
  cout << (x + y) / z << ' ' << res << '\n';
}