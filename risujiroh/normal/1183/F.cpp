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
    sort(rbegin(a), rend(a));
    a.erase(unique(begin(a), end(a)), end(a));
    n = a.size();
    int res = a[0];
    for (int i = 0; i < n; ++i) if (a[0] % a[i]) {
      res = max(res, a[0] + a[i]);
      break;
    }
    for (int i = 0; i < min(2, n); ++i) {
      for (int j = i; j < n; ++j) if (a[i] % a[j]) {
        for (int k = j; k < n; ++k) if (a[i] % a[k] and a[j] % a[k]) {
          res = max(res, a[i] + a[j] + a[k]);
        }
        break;
      }
    }
    cout << res << '\n';
  }
}