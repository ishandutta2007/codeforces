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
  int q; cin >> q;
  auto f = [](lint x) -> lint {
    if (x & 1) return -(x + 1 >> 1);
    return x + 1 >> 1; 
  };
  for (int i = 0; i < q; ++i) {
    int l, r; cin >> l >> r;
    cout << f(r) - f(l - 1) << '\n';
  }
}