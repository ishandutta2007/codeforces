#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  for (int i = 0; i < n; ++i) {
    a.push_back(a[i]);
  }
  n = a.size();
  int res = 0;
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      ++t;
      res = max(res, t);
    } else t = 0;
  }
  cout << res << '\n';
}