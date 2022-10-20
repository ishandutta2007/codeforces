#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class T> map<T, int> factor(T n) {
  map<T, int> res;
  for (T i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n), b(n); for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  auto lcm = [](lint a, lint b) { return a * b / __gcd(a, b); };
  lint res = 0;
  for (int i = 0; i < n; i++) {
    res = __gcd(res, lcm(a[i], b[i]));
  }
  if (res == 1) cout << -1 << '\n';
  else {
    for (int i = 0; i < n; ++i) {
      if (res % a[i] == 0) return cout << begin(factor(a[i]))->first << '\n', 0;
      if (res % b[i] == 0) return cout << begin(factor(b[i]))->first << '\n', 0;
    }
    cout << begin(factor(res))->first << '\n';
  }
}