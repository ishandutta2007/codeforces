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
  int x; cin >> x;
  for (int a = 1; a <= x; ++a) for (int b = 1; b <= x; ++b) {
    if (a % b) continue;
    if (a * b <= x) continue;
    if (a >= b * x) continue;
    cout << a << ' ' << b << '\n';
    return 0;
  }
  cout << -1 << '\n';
}