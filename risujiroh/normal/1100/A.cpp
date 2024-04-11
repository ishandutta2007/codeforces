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
  int n, k; cin >> n >> k;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  int res = 0;
  for (int b = 0; b < k; ++b) {
    int e = 0, s = 0;
    for (int i = 0; i < n; ++i) if (i % k != b) {
      e += a[i] == 1;
      s += a[i] == -1;
    }
    res = max(res, abs(e - s));
  }
  cout << res << '\n';
}