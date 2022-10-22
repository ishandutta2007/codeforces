#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n, m; cin >> n >> m;
  m <<= 3;
  m /= n;
  if (m >= 30) return cout << 0 << '\n', 0;
  m = 1LL << m;
  V<> a(n); for (auto&& e : a) cin >> e;
  {
    auto v = a;
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    for (auto&& e : a) {
      e = lower_bound(begin(v), end(v), e) - begin(v);
    }
  }
  sort(begin(a), end(a));
  int res = 1e9;
  for (int i = 0; i < n; ++i) {
    int c = lower_bound(begin(a), end(a), a[i] + m) - (begin(a) + i);
    res = min<int>(res, n - c);
  }
  cout << res << '\n';
}