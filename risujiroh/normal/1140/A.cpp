#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e, --e;
  int res = 0, mx = -1;
  for (int i = 0; i < n; ++i) {
    mx = max(mx, a[i]);
    if (mx <= i) ++res;
  }
  cout << res << '\n';
}