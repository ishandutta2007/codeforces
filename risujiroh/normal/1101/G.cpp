#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<> c(n);
  partial_sum(begin(a), end(a), begin(c), [](int x, int y) { return x ^ y; });
  if (c.back() == 0) return cout << -1 << '\n', 0;
  int r = 0;
  for (int j = 0; j < 30; ++j) {
    for (int i0 = r; i0 < n; ++i0) {
      if (c[i0] & 1 << j) {
        for (int i = 0; i < n; ++i) if (i != i0 and c[i] & 1 << j) {
          c[i] ^= c[i0];
        }
        swap(c[r], c[i0]);
        ++r;
        break;
      }
    }
  }
  cout << r << '\n';
}