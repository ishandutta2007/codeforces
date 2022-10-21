#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> c(2e5 + 1);
  for (int e : a) ++c[e];
  if (*max_element(begin(c), end(c)) < 2) {
    for (int i = 0; i < 2e5; ++i) if (c[i] and c[i + 1]) {
      cout << 2 << '\n';
      cout << i << ' ' << i + 1 << '\n';
      return 0;
    }
    cout << 1 << '\n';
    cout << a[0] << '\n';
    return 0;
  }
  int t = 0;
  V<> res;
  for (int i = 0; i <= 2e5; ++i) {
    if (c[i] >= 2) {
      ++t;
      if (i == 2e5 or c[i + 1] < 2) {
        int l = i - t + 1, r = i + 1;
        if (l and c[l - 1]) --l;
        if (r <= 2e5 and c[r]) ++r;
        V<> curr;
        for (int _ = 0; _ < c[l]; ++_) curr.push_back(l);
        for (int x = l + 1; x < r; ++x) {
          for (int _ = 0; _ < c[x] - 1; ++_) curr.push_back(x);
        }
        for (int x = r - 1; x > l; --x) curr.push_back(x);
        if (curr.size() > res.size()) {
          res = curr;
        }
      }
    } else {
      t = 0;
    }
  }
  int m = res.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " \n"[!(m + ~i)];
  }
}