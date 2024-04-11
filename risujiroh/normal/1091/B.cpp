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
  V<lint> x(n), y(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  V<lint> a(n), b(n); for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  lint tx = accumulate(begin(x), end(x), 0LL) + accumulate(begin(a), end(a), 0LL);
  lint ty = accumulate(begin(y), end(y), 0LL) + accumulate(begin(b), end(b), 0LL);
  tx /= n;
  ty /= n;
  cout << tx << ' ' << ty << '\n';
}