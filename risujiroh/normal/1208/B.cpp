#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  auto v = a;
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
  for (auto&& e : a) {
    e = lower_bound(begin(v), end(v), e) - begin(v);
  }

  int res = n;
  for (int l = 0; l <= n; ++l) {
    V<> c(n);
    bool ok = true;
    for (int i = 0; i < l; ++i) {
      if (c[a[i]]) {
        ok = false;
        break;
      }
      ++c[a[i]];
    }
    if (!ok) continue;
    int r = n;
    while (r > l and !c[a[r - 1]]) {
      --r;
      ++c[a[r]];
    }
    res = min(res, r - l);
  }
  cout << res << '\n';
}