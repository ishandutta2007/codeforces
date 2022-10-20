#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n, m; cin >> n >> m;
  lint d = __gcd(n, m);
  lint a = n / d, b = m / d;

  auto fn = [&](lint x, lint y) -> lint {
    if (x == 1){
      return y / a;
    } else {
      return y / b;
    }
  };

  int q; cin >> q;
  while (q--) {
    lint sx, sy; cin >> sx >> sy, --sy;
    lint tx, ty; cin >> tx >> ty, --ty;
    cout << (fn(sx, sy) == fn(tx, ty) ? "YES" : "NO") << '\n';
  }
}