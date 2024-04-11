#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> k(n); for (auto&& e : k) cin >> e;
  VV<> a(n);
  while (m--) {
    int d, t; cin >> d >> t, --d, --t;
    a[t].push_back(d);
  }
  for (auto&& v : a) sort(begin(v), end(v));
  auto chk = [&](int x) -> bool {
    VV<> v(4e5);
    for (int i = 0; i < n; ++i) {
      int j = lower_bound(begin(a[i]), end(a[i]), x) - begin(a[i]) - 1;
      if (j < 0) continue;
      v[a[i][j]].push_back(i);
    }
    int c = 0;
    auto r = k;
    int y = 0;
    for (int j = 0; j < x; ++j) {
      ++c;
      for (int i : v[j]){
        int t = min(c, r[i]);
        r[i] -= t;
        c -= t;
        y += t;
      }
    }
    return x + y >= 2 * accumulate(begin(k), end(k), 0);
  };
  int ng = 0, ok = 2 * accumulate(begin(k), end(k), 0);
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}