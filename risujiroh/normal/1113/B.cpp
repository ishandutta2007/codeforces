#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  sort(begin(a), end(a));
  int s = accumulate(begin(a), end(a), 0), res = s;
  for (int i = 1; i < n; ++i) {
    for (int d = 1; d <= 100; ++d) if (a[i] % d == 0) {
      res = min(res, s - a[0] - a[i] + a[0] * d + a[i] / d);
    }
  }
  cout << res << '\n';
}