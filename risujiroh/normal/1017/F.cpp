#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template<class T> V<T> sieve(T a, T b) {
  a = max((T) 2, a); V<T> res; T q = ceil(sqrt(b));
  V<bool> mem(b - a, true), sub(q - 2, true);
  for (T i = 2; i < q; i++) {
    if (sub[i - 2]) {
      for (T j = max(i, (a + i - 1) / i) * i; j < b; j += i) mem[j - a] = false;
      for (T j = i * i; j < q; j += i) sub[j - 2] = false;
    }
  }
  for (T i = a; i < b; i++) if (mem[i - a]) res.push_back(i);
  return res;
}

uint f(uint x, uint a, uint b, uint c, uint d) { return a * x * x * x + b * x * x + c * x + d; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  uint n; cin >> n;
  uint a, b, c, d; cin >> a >> b >> c >> d;
  uint m = 1e6, res = 0;
  for (int i = 0; i * m < n; i++) {
    auto ps = sieve(i * m, min((i + 1) * m, n + 1));
    for (uint p : ps) {
      uint k = 0;
      for (uint t = n / p; t; t /= p) k += t;
      res += k * f(p, a, b, c, d);
    }
  }
  cout << res << '\n';
}