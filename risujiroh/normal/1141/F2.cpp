#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> c(n + 1);
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] + a[i];
  }
  map< int, V< pair<int, int> > > mp;
  for (int l = 0; l < n; ++l) for (int r = l + 1; r <= n; ++r) {
    mp[c[r] - c[l]].emplace_back(l, r);
  }
  int mx = 0;
  V< pair<int, int> > res;
  for (const auto& e : mp) {
    auto v = e.second;
    sort(begin(v), end(v), [](const auto& l, const auto& r) {
      return l.second < r.second;
    });
    int t = 0;
    V< pair<int, int> > curr;
    for (const auto& p : v) {
      if (p.first >= t) {
        curr.push_back(p);
        t = p.second;
      }
    }
    if (curr.size() > mx) {
      mx = curr.size();
      res = curr;
    }
  }
  cout << res.size() << '\n';
  for (const auto& e : res) {
    cout << e.first + 1 << ' ' << e.second << '\n';
  }
}