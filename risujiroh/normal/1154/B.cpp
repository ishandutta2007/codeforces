#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  a.erase(unique(begin(a), end(a)), end(a));
  n = a.size();
  if (n > 3) return cout << -1 << '\n', 0;
  if (n == 3) {
    if (a[1] * 2 == a[0] + a[2]) cout << a[1] - a[0] << '\n';
    else cout << -1 << '\n';
  } else if (n == 2) {
    if (a[1] - a[0] & 1) cout << a[1] - a[0] << '\n';
    else cout << (a[1] - a[0] >> 1) << '\n';
  } else {
    cout << 0 << '\n';
  }
}