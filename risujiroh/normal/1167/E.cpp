#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (auto&& e : a) cin >> e, --e;
  V<> li(m, n), ri(m, -1);
  for (int i = 0; i < n; ++i) {
    li[a[i]] = min(li[a[i]], i);
    ri[a[i]] = max(ri[a[i]], i);
  }
  V<> p(m + 1, n), q(m + 1, -1);
  p[0] = -1;
  for (int j = 0; j < m; ++j) {
    if (p[j] < li[j]) p[j + 1] = max(p[j], ri[j]);
    else break;
  }
  q[m] = n;
  for (int j = m - 1; j >= 0; --j) {
    if (ri[j] < q[j + 1]) q[j] = min(q[j + 1], li[j]);
    else break;
  }
  lint res = 0;
  int r = 1;
  for (int l = 0; l < m; ++l) {
    r = max(r, l + 1);
    while (r <= m and p[l] >= q[r]) ++r;
    res += m - r + 1;
  }
  cout << res << '\n';
}