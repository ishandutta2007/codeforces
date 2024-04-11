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
  int n, m, k; cin >> n >> m >> k;
  V<> b(n); for (int i = 0; i < n; ++i) cin >> b[i];
  V<> d(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    d[i] = b[i + 1] - b[i] - 1;
  }
  sort(rbegin(d), rend(d));
  int res = b.back() - b[0] + 1;
  for (int i = 0; i < k - 1; ++i) {
    res -= d[i];
  }
  cout << res << '\n';
}