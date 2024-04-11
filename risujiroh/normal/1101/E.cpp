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
  int n; cin >> n;
  int a = 0, b = 0;
  while (n--) {
    char c; cin >> c;
    if (c == '+') {
      int x, y; cin >> x >> y;
      if (x > y) swap(x, y);
      a = max(a, x);
      b = max(b, y);
    } else {
      int h, w; cin >> h >> w;
      if (h > w) swap(h, w);
      if (h >= a and w >= b) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    }
  }
}