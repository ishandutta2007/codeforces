#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    VV<> idx(n);
    for (int i = 0; i < n; ++i) {
      int a; cin >> a, --a;
      idx[a].push_back(i);
    }
    int res = inf;
    for (const auto& v : idx) if (v.size() >= 2) {
      for (int t = 0; t < (int)v.size() - 1; ++t) {
        res = min(res, v[t + 1] - v[t] + 1);
      }
    }
    if (res == inf) {
      cout << -1 << '\n';
    } else {
      cout << res << '\n';
    }
  }
}