#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  V<> b(n); for (int i = 0; i < n; ++i) cin >> b[i], --b[i];
  V<> ia(n); for (int i = 0; i < n; ++i) ia[a[i]] = i;
  V<> c(n, 1);
  for (int i = 0; i < n; ++i) {
    int res = 0;
    int j = ia[b[i]];
    while (c[j] and j >= 0) {
      c[j] = 0;
      --j;
      ++res;
    }
    cout << res << (i != n - 1 ? ' ' : '\n');
  }
}