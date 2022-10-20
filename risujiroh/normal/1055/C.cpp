#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint la, ra, ta; cin >> la >> ra >> ta, ++ra;
  lint lb, rb, tb; cin >> lb >> rb >> tb, ++rb;
  if (ta < tb) {
    swap(la, lb);
    swap(ra, rb);
    swap(ta, tb);
  }
  lint d = __gcd(ta, tb);
  lint res = 0;
  for (lint i = ((la - lb) / d - 10) * d; i < ((la - lb) / d + 10) * d; i += d) {
    res = max(res, min(ra, rb + i) - max(la, lb + i));
  }
  for (lint i = ((ra - rb) / d - 10) * d; i < ((ra - rb) / d + 10) * d; i += d) {
    res = max(res, min(ra, rb + i) - max(la, lb + i));
  }
  cout << res << '\n';
}