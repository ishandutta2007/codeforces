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
  int n, k, m; cin >> n >> k >> m;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  sort(rbegin(a), rend(a));
  V<lint> c(n + 1);
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] + a[i];
  }
  double res = 0;
  for (int x = 0; x <= min(n - 1, m); ++x) {
    double curr = c[n - x];
    curr += min<double>(m - x, 1.0 * k * (n - x));
    curr /= n - x;
    res = max(res, curr);
  }
  cout << fixed << setprecision(15) << res << '\n';
}