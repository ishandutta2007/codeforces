#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int k = __lg(2 * n - 1);
    int res = 0;
    for (int i = 0; i < k; ++i) {
      V<> v0, v1;
      for (int v = 0; v < n; ++v) if (v >> i & 1) {
        v1.push_back(v);
      } else {
        v0.push_back(v);
      }
      int k0 = v0.size(), k1 = v1.size();
      assert(k0 and k1);
      cout << k0 << ' ' << k1;
      for (int e : v0) cout << ' ' << e + 1;
      for (int e : v1) cout << ' ' << e + 1;
      cout << endl;
      int x; cin >> x;
      res = max(res, x);
    }
    cout << "-1 " << res << endl;
  }
}