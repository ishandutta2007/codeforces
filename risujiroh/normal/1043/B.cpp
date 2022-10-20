#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<> x(n);
  x[0] = a[0];
  for (int i = 1; i < n; ++i) x[i] = a[i] - a[i - 1];
  V<> res;
  for (int k = 1; k < n + 1; ++k) {
    bool chk = true;
    for (int i = 0; i < n; ++i) if (x[i] != x[i % k]) chk = false;
    if (chk) res.push_back(k);
  }
  cout << res.size() << '\n';
  for (int i = 0; i < res.size(); ++i) cout << res[i] << (i != res.size() - 1 ? ' ' : '\n');
}