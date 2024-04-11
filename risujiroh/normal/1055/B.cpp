#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint n, m, l; cin >> n >> m >> l;
  V<lint> a(n + 1); for (int i = 0; i < n; ++i) cin >> a[i];
  int res = 0;
  for (int i = 0; i < n; ++i) res += a[i] > l and a[i + 1] <= l;
  for (int _ = 0; _ < m; ++_) {
    int t; cin >> t;
    if (!t) cout << res << '\n';
    else {
      lint p, d; cin >> p >> d, --p;
      if (a[p] <= l and a[p] + d > l) {
        if (!(p > 0 and a[p - 1] > l or p < n - 1 and a[p + 1] > l)) ++res;
        if (p > 0 and a[p - 1] > l and p < n - 1 and a[p + 1] > l) --res;
      }
      a[p] += d;
    }
  }
}