#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a(m);
  for (int i = 0; i < n; ++i) {
    int s, r; cin >> s >> r, --s;
    a[s].push_back(r);
  }
  sort(rbegin(a), rend(a), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
  VV<> c(m);
  for (int i = 0; i < m; ++i) {
    sort(rbegin(a[i]), rend(a[i]));
    c[i].resize(a[i].size() + 1);
    for (int j = 0; j < a[i].size(); ++j) c[i][j + 1] = c[i][j] + a[i][j];
  }
  int res = 0;
  for (int k = 1; k <= n; ++k) {
    int curr = 0;
    for (int i = 0; i < m; ++i) {
      if (a[i].size() < k) break;
      if (c[i][k] >= 0) curr += c[i][k];
    }
    res = max(res, curr);
  }
  cout << res << '\n';
}