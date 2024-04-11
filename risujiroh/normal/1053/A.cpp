#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template<class T> set<T> divisor(T n) {
  set<T> res;
  for (T i = 1; i * i <= n; i++) if (n % i == 0) res.insert(i), res.insert(n / i);
  return res;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, m, k; cin >> n >> m >> k;
  if (k == 1) return cout << "NO" << '\n', 0;
  if (2 * n * m % k) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  lint s = 2 * n * m / k;
  auto x = divisor(k);
  for (auto&& i : x) {
    lint j = k / i;
    lint a, b;
    bool ok = false;
    if (!(2 * n % i) and !(m % j)) {
      a = 2 * n / i, b = m / j;
      if (a > n or b > m) ok = false;
      else ok = true;
    }
    if (!ok and !(n % i) and !(2 * m % j)) {
      a = n / i, b = 2 * m / j;
      if (a > n or b > m) ok = false;
      else ok = true;
    }
    if (!ok) continue;
    cout << 0 << ' ' << 0 << '\n';
    cout << a << ' ' << 0 << '\n';
    cout << 0 << ' ' << b << '\n';
    return 0;
  }
}