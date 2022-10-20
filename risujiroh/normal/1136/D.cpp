#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> p(n); for (auto&& e : p) cin >> e, --e;
  VV<> a(n);
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    a[u].push_back(v);
  }
  for (int i = 0; i < n; ++i) {
    sort(begin(a[i]), end(a[i]));
  }
  set<int> se{p[n - 1]};
  auto chk = [&](int u) -> bool {
    if (a[u].size() < se.size()) return false;
    for (int e : se) {
      if (!binary_search(begin(a[u]), end(a[u]), e)) return false;
    }
    return true;
  };
  int res = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (chk(p[i])) ++res;
    else se.insert(p[i]);
  }
  cout << res << '\n';
}