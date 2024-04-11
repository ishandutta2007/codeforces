#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int t; cin >> t;
  auto inter = [](lint x1, lint x2, lint x3, lint x4) -> lint {
    return max<lint>(min(x2, x4) - max(x1, x3), 0);
  };
  for (int it = 0; it < t; ++it) {
    lint n, m; cin >> n >> m;
    lint x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2, --x1, --y1;
    lint x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4, --x3, --y3;
    lint w0 = n * m / 2, b0 = w0;
    if (n & 1 and m & 1) ++w0;
    lint w1 = (x2 - x1) * (y2 - y1) / 2, b1 = w1;
    if (x2 - x1 & 1 and y2 - y1 & 1) ++(x1 + y1 & 1 ? b1 : w1);
    lint w2 = (x4 - x3) * (y4 - y3) / 2, b2 = w2;
    if (x4 - x3 & 1 and y4 - y3 & 1) ++(x3 + y3 & 1 ? b2 : w2);
    if (inter(x1, x2, x3, x4) and inter(y1, y2, y3, y4)) {
      lint x5 = max(x1, x3), x6 = min(x2, x4);
      lint y5 = max(y1, y3), y6 = min(y2, y4);
      lint w3 = (x6 - x5) * (y6 - y5) / 2, b3 = w3;
      if (x6 - x5 & 1 and y6 - y5 & 1) ++(x5 + y5 & 1 ? b3 : w3);
      cout << w0 + (b1 - b3) - w2 << ' ' << b0 - (b1 - b3) + w2 << '\n';
    } else {
      cout << w0 + b1 - w2 << ' ' << b0 - b1 + w2 << '\n';
    }
  }
}