#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint n, m; cin >> n >> m;
  lint sum = 0;
  for (int i = 0; i < m; ++i) {
    lint x, d; cin >> x >> d;
    sum += x * n;
    if (d >= 0) sum += n * (n - 1) / 2 * d;
    else {
      if (n & 1) sum += (n * n - 1) / 4 * d;
      else sum += n * n / 4 * d;
    }
  }
  cout << fixed << setprecision(15) << (double) sum / n << '\n';
}