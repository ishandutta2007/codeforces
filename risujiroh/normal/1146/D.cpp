#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int m, a, b; cin >> m >> a >> b;
  int d = __gcd(a, b);
  auto s = [&](lint n) -> lint {
    lint nn = n / d;
    lint res = d * nn * (nn + 1) / 2;
    res += n % d * (n / d + 1);
    return res;
  };
  int x = 0, mx = x;
  V<> f(a + b);
  int c = 1;
  f[mx] = c;
  while (true) {
    while (x < b) {
      x += a;
      mx = max(mx, x);
      f[mx] = ++c;
    }
    while (x - b >= 0) {
      if (x -= b) {
        f[mx] = ++c;
      }
    }
    if (!x) break;
  }
  for (int i = 1; i < a + b; ++i) f[i] = max(f[i], f[i - 1]);
  lint res = 0;
  for (int i = 0; i <= m and i < a + b; ++i) res += f[i];
  if (m >= a + b) {
    res += s(m + 1) - s(a + b);
  }
  cout << res << '\n';
}