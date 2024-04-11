#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e, e = abs(e);
  sort(begin(a), end(a));
  lint res = 0;
  for (int i = 0; i < n; ++i) {
    int c = upper_bound(begin(a), end(a), 2 * a[i]) - (begin(a) + i + 1);
    res += max(c, 0);
  }

  cout << res << '\n';
}