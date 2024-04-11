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
  int t; cin >> t;
  for (int it = 0; it < t; ++it) {
    lint n, k; cin >> n >> k;
    if (n == 1) {
      if (k == 1) cout << "YES 0" << '\n';
      else cout << "NO" << '\n';
    } else if (n == 2) {
      if (k <= 2) cout << "YES 1" << '\n';
      else if (4 <= k and k <= 5) cout << "YES 0" << '\n';
      else cout << "NO" << '\n';
    } else if (n <= 30 and k > ((1LL << 2 * n) - 1) / 3) cout << "NO" << '\n';
    else {
      if (k <= 6) cout << "YES " << n - 1 << '\n';
      else {
        for (int x = min<lint>(60, n); x > 0; --x) {
          if (k >= (1LL << x + 1) - (x + 2)) {
            cout << "YES " << n - x << '\n';
            break;
          }
        }
      }
    }
  }
}