#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, s; cin >> n >> s, --s;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<> b(n); for (int i = 0; i < n; ++i) cin >> b[i];
  if (!a[0]) return cout << "NO" << '\n', 0;
  if (a[s]) return cout << "YES" << '\n', 0;
  if (!b[s]) return cout << "NO" << '\n', 0;
  for (int i = s + 1; i < n; ++i) if (a[i] and b[i]) return cout << "YES" << '\n', 0;
  cout << "NO" << '\n';
}