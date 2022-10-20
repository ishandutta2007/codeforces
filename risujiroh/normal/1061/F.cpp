#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int n, k; cin >> n >> k;
  int h = -1, _n = n, t = 1;
  while (_n) {
    _n -= t;
    t *= k;
    ++h;
  }
  uniform_int_distribution<> rng(1, n);
  while (true) {
    int a = rng(mt), c = rng(mt);
    while (a == c) c = rng(mt);
    int k = 0;
    V<> bs;
    for (int b = 1; b <= n; ++b) if (b != a and b != c) {
      cout << "? " << a << ' ' << b << ' ' << c << endl;
      string s; cin >> s;
      if (s == "Yes") {
        bs.push_back(b);
        ++k;
      }
    }
    if (k == 2 * h - 1) {
      for (int r : bs) {
        int m = 0;
        for (int b : bs) {
          cout << "? " << a << ' ' << b << ' ' << r << endl;
          string s; cin >> s;
          m += s == "Yes";
        }
        if (m == h) return cout << "! " << r << endl, 0;
      }
    }
  }
}