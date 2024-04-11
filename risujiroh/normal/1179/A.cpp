#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> mx(n + 1);
  for (int i = 0; i < n; ++i) mx[i + 1] = max(mx[i], a[i]);
  // int imx = max_element(begin(a), end(a)) - begin(a);
  auto b = a;
  for (int i = 0; i < n - 1; ++i) {
    if (b[i] > b[i + 1]) swap(b[i], b[i + 1]);
  }
  b.pop_back();
  while (q--) {
    lint m; cin >> m, --m;
    if (m < n - 1) {
      cout << mx[m + 1] << ' ' << a[(m + 1) % n] << '\n';
    } else {
      cout << mx[n] << ' ' << b[m % (n - 1)] << '\n';
    }
  }
}