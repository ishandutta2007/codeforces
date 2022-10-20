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
    V<> a(n); for (auto&& e : a) cin >> e;
    auto v = a;
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    for (auto&& e : a) {
      e = lower_bound(begin(v), end(v), e) - begin(v);
    }
    int m = v.size();
    if (m == 1) {
      cout << 0 << '\n';
      continue;
    }
    V<> l(m, n), r(m, -1);
    for (int i = 0; i < n; ++i) {
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    }
    V<> c(m - 1);
    for (int x = 0; x < m - 1; ++x) {
      c[x] = r[x] < l[x + 1];
    }
    int mx = 0, t = 0;
    for (int x = 0; x < m - 1; ++x) {
      if (c[x]) {
        ++t;
        mx = max(mx, t);
      } else {
        t = 0;
      }
    }
    cout << m - 1 - mx << '\n';
  }
}