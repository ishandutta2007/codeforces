#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    V<> c(n);
    for (int _ = 0; _ < n; ++_) {
      int a; cin >> a, --a;
      ++c[a];
    }
    V<> d(n + 1);
    for (int e : c) ++d[e];
    int res = 0, t = 0;
    for (int i = n; i; --i) {
      t += d[i];
      if (t) {
        res += i;
        --t;
      }
    }
    cout << res << '\n';
  }
}