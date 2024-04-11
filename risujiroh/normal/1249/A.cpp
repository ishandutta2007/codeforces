#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    V<> a(n); for (auto&& e : a) cin >> e;
    sort(begin(a), end(a));
    int mn = 1e9;
    for (int i = 0; i < n - 1; ++i) {
      mn = min(mn, a[i + 1] - a[i]);
    }
    if (mn == 1) {
      cout << 2 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
}