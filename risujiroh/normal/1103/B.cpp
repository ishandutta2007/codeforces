#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


bool query(int x, int y) {
  cout << "? " << x << ' ' << y << endl;
  char c; cin >> c;
  assert(c != 'e');
  return c == 'x';
}

int rec(int l, int r) {
  if (r - l == 1) return r;
  int m = l + r >> 1;
  if (query(m, r)) {
    return rec(m, r);
  } else {
    return rec(l, m);
  }
}

int main() {
  while (true) {
    string str; cin >> str;
    if (str == "end") break;
    int k = 1;
    while (!query(1 << k - 1, 1 << k)) ++k;
    int res;
    if (k == 1) {
      res = query(0, 1) ? 1 : 2;
    } else {
      res = rec(1 << k - 1, 1 << k);
    }
    cout << "! " << res << endl;
  }
}