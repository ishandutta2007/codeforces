#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint a, b; cin >> a >> b;
  auto f = [](lint x) {
    lint ok = 0, ng = x + 1;
    while (ng - ok > 1) {
      lint med = (ok + ng) / 2;
      if (med * (med + 1) / 2 <= x) ok = med;
      else ng = med;
    }
    return ok;
  };
  lint k = f(a + b);
  V<> resa, resb;
  for (lint i = k; i; i--) {
    if (i <= a) {
      resa.push_back(i);
      a -= i;
    } else {
      resb.push_back(i);
    }
  }
  sort(resa.begin(), resa.end());
  sort(resb.begin(), resb.end());
  int n = resa.size();
  cout << n << '\n';
  for (int i = 0; i < n; i++) cout << resa[i] << (i != n - 1 ? ' ' : '\n');
  int m = resb.size();
  cout << m << '\n';
  for (int i = 0; i < m; i++) cout << resb[i] << (i != m - 1 ? ' ' : '\n');
}