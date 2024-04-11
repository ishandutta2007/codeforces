#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  int x, y; cin >> x >> y;
  if (x + y - n & 1 or abs(x) + abs(y) > n) return cout << -1 << '\n', 0;
  struct P { int x, y; };
  auto mk = [](char c) -> P {
    if (c == 'U') return {0, 1};
    if (c == 'D') return {0, -1};
    if (c == 'L') return {-1, 0};
    if (c == 'R') return {1, 0};
  };
  V<P> a(n + 1), b(n + 1);
  b[0] = {x, y};
  for (int i = 0; i < n; ++i) {
    P d = mk(s[i]);
    a[i + 1] = {a[i].x + d.x, a[i].y + d.y};
  }
  for (int i = 0; i < n; ++i) {
    P d = mk(s[n - 1 - i]);
    b[i + 1] = {b[i].x - d.x, b[i].y - d.y};
  }
  int res = n, pb = 0;
  int pa = 0;
  while (pa < n and abs(a[pa + 1].x - x) + abs(a[pa + 1].y - y) <= n - pa - 1) ++pa;
  for (; pa >= 0; --pa) {
    while (pa + pb < n and abs(a[pa].x - b[pb + 1].x) + abs(a[pa].y - b[pb + 1].y) <= n - pa - pb - 1) ++pb;
    if (abs(a[pa].x - b[pb].x) + abs(a[pa].y - b[pb].y) <= n - pa - pb) res = min(res, n - pa - pb);
  }
  cout << res << '\n';
}