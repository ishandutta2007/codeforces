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
  while (t--) {
    lint n, l, r; cin >> n >> l >> r;
    V<lint> b(n);
    lint x, y, z; cin >> x >> y >> z;
    cin >> b[0] >> b[1];
    for (int i = 2; i < n; ++i) {
      b[i] = ((b[i - 2] * x + b[i - 1] * y + z) % (1LL << 32) + (1LL << 32)) % (1LL << 32);
    }
    V<lint> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = b[i] % (r - l + 1) + l;
    }
    V<lint> mn(n + 1, 2e9), mx(n + 1, -2e9);
    for (int i = 0; i < n; ++i) {
      mn[i + 1] = min(mn[i], a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
      mx[i] = max(mx[i + 1], a[i]);
    }
    lint res = 9e18;
    for (int i = 0; i < n; ++i) if (a[i] < 0) {
      if (mx[i + 1] > a[i]) {
        res = min(res, a[i] * mx[i + 1]);
      }
    }
    for (int i = n - 1; i >= 0; --i) if (a[i] >= 0) {
      if (mn[i] < a[i]) {
        res = min(res, mn[i] * a[i]);
      }
    }
    cout << (res != 9e18 ? to_string(res) : "IMPOSSIBLE") << '\n';
  }
}