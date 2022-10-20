#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  reverse(begin(a), end(a));
  lint res = 0, t = 9e18;
  for (int i = 0; i < n; ++i) {
    t = min(a[i], t - 1);
    res += max<lint>(t, 0);
  }
  cout << res << '\n';
}