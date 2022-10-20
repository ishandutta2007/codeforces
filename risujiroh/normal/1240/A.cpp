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
    V<lint> p(n); for (auto&& e : p) cin >> e;
    sort(rbegin(p), rend(p));
    V<> r(n + 1);
    int x, a; cin >> x >> a;
    for (int i = a; i <= n; i += a) {
      r[i] += x;
    }
    int y, b; cin >> y >> b;
    for (int i = b; i <= n; i += b) {
      r[i] += y;
    }
    r.erase(begin(r));
    lint k; cin >> k;
    auto chk = [&](int mid) -> bool {
      V<> idx(mid);
      iota(begin(idx), end(idx), 0);
      sort(begin(idx), end(idx), [&](int i, int j) { return r[i] > r[j]; });
      V<lint> np(mid);
      for (int t = 0; t < mid; ++t) {
        int i = idx[t];
        np[i] = p[t];
      }
      lint crr = 0;
      for (int i = 0; i < mid; ++i) {
        crr += np[i] / 100 * r[i];
      }
      return crr >= k;
    };
    int ng = 0, ok = n + 1;
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      (chk(mid) ? ok : ng) = mid;
    }
    cout << (ok <= n ? ok : -1) << '\n';
  }
}