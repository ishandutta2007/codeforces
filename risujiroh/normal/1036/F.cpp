#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

const lint N = 1e7;
V<bool> b(N + 10);
V<> c(N + 10);

template<class T> inline T powi(T a, int n) { return !n ? 1 : powi(a * a, n >> 1) * (n & 1 ? a : 1); }

inline lint rec(lint n) {
  if (n <= N) return c[n];
  lint res = 0;
  for (int i = 2; i < 8; i++) if (i & 3) {
    for (lint j = i * i; j <= n; j *= i) res++;
  }
  for (int i = 2; i < 100; i++) {
    lint q = pow(n, 1.0L / i) + 1;
    while (powi(q, i) > n) q--;
    if (q < 10) break;
    res += q - 6 - (q <= N ? c[q] : rec(q));
  }
  return res;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  for (lint m = 2; m * m < N + 10; m++) {
    if (b[m]) continue;
    lint p = m * m;
    while (p < N + 10) {
      b[p] = true;
      p *= m;
    }
  }
  for (int i = 2; i < N + 10; i++) c[i] = c[i - 1] + b[i];
  int t; cin >> t;
  for (int it = 0; it < t; it++) {
    lint n; cin >> n;
    cout << n - 1 - rec(n) << '\n';
  }
}