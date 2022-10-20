#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  auto chk = [&](int x) -> int {
    V< pair<int, int> > u, d;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= x) u.emplace_back(i, a[i]);
      else d.emplace_back(i, a[i]);
    }
    int m = u.size();
    int ul = 0;
    while (ul < m and (!ul or u[ul - 1].second > u[ul].second)) ++ul;
    int ur = m;
    while (ur > 0 and (ur == m or u[ur - 1].second < u[ur].second)) --ur;
    m = d.size();
    int dl = 0;
    while (dl < m and (!dl or d[dl - 1].second < d[dl].second)) ++dl;
    int dr = m;
    while (dr > 0 and (dr == m or d[dr - 1].second > d[dr].second)) --dr;
    if (ul < ur and dl < dr) return -10;
    if (ul < ur) return -1;
    if (dl < dr) return -2;
    int l = min(ul < u.size() ? u[ul].first : n, dl < d.size() ? d[dl].first : n);
    int r = max(ur > 0 ? u[ur - 1].first + 1 : 0, dr > 0 ? d[dr - 1].first + 1 : 0);
    if (l < r) return -10;
    return l;
  };
  int l = 0, r = 2e5 + 1;
  for (int x : {l, r}) {
    int m = chk(x);
    if (m >= 0) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; ++i) {
        cout << (a[i] < x ^ i < m) << " \n"[i == n - 1];
      }
      return 0;
    }
  }
  while (r - l > 1) {
    int x = l + r >> 1;
    int m = chk(x);
    if (m >= 0) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; ++i) {
        cout << (a[i] < x ^ i < m) << " \n"[i == n - 1];
      }
      return 0;
    }
    if (m == -10) break;
    (m == -1 ? l : r) = x;
  }
  cout << "NO" << '\n';
}