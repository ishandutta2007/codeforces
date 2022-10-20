#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    a[i] = 1 << x | 1 << y;
  }
  V<> b(m);
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    b[i] = 1 << x | 1 << y;
  }
  V<> c(10);
  V<> ca(10), cb(10);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (__builtin_popcount(a[i] & b[j]) == 1) {
    ++c[__lg(a[i] & b[j])];
    ca[__lg(a[i] & b[j])] |= 1 << i;
    cb[__lg(a[i] & b[j])] |= 1 << j;
  }
  if (count_if(cbegin(c), cend(c), [](int x) { return x > 0; }) == 1) return cout << distance(cbegin(c), max_element(cbegin(c), cend(c))) << '\n', 0;
  for (int x = 1; x < 10; ++x) for (int y = x + 1; y < 10; ++y) if (ca[x] & ca[y] or cb[x] & cb[y]) return cout << -1 << '\n', 0;
  cout << 0 << '\n';
}