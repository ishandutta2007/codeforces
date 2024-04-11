#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V< pair<int, int> > v;
  while (m--) {
    int a, b; cin >> a >> b, --a, --b;
    if (a > b) swap(a, b);
    v.emplace_back(a, b);
  }
  sort(begin(v), end(v));
  for (int d = 1; d < n; ++d) if (!(n % d)) {
    V< pair<int, int> > nv;
    for (const auto& p : v) {
      int a = (p.first + d) % n;
      int b = (p.second + d) % n;
      if (a > b) swap(a, b);
      nv.emplace_back(a, b);
    }
    sort(begin(nv), end(nv));
    if (v == nv) return cout << "Yes" << '\n', 0;
  }
  cout << "No" << '\n';
}