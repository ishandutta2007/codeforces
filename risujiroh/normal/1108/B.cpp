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
  V<> d(n); for (int i = 0; i < n; ++i) cin >> d[i];
  sort(rbegin(d), rend(d));
  int x = d[0];
  cout << x << ' ';
  for (int i = 0; i < n; ++i) {
    if (x % d[i] or d[i] == d[i + 1]) return cout << d[i] << '\n', 0;
  }
  assert(false);
}