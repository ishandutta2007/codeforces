#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    int d; cin >> d;
    if (d and d < 4) {
      cout << 'N' << '\n';
      continue;
    }
    cout << "Y ";
    double a = 0.5 * (d + sqrt(d * (d - 4))), b = d - a;
    cout << fixed << setprecision(15) << a << ' ' << b << '\n';
  }
}