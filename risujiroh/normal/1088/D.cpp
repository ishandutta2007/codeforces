#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int query(int c, int d) {
  cout << "? " << c << ' ' << d << endl;
  int res; cin >> res;
  return res;
}

int main() {
  int a = 0, b = 0;
  int sgn = query(0, 0);
  for (int i = 29; i >= 0; --i) {
    if (sgn >= 0) {
      int x = query(a ^ 1 << i, b);
      int y = query(a, b ^ 1 << i);
      if (x == y) {
        sgn = x;
        a |= 1 << i;
      } else if (y == 1) {
        a |= 1 << i;
        b |= 1 << i;
      }
    } else {
      int x = query(a ^ 1 << i, b);
      int y = query(a, b ^ 1 << i);
      if (x == y) {
        sgn = x;
        b |= 1 << i;
      } else if (y == 1) {
        a |= 1 << i;
        b |= 1 << i;
      }
    }
  }
  cout << "! " << a << ' ' << b << endl;
}