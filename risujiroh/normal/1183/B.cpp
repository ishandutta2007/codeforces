#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n, k; cin >> n >> k;
    V<> a(n); for (auto&& e : a) cin >> e;
    sort(begin(a), end(a));
    if (a.back() - a[0] > 2 * k) cout << -1 << '\n';
    else {
      cout << a[0] + k << '\n';
    }
  }
}