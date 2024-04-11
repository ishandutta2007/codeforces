#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint H; cin >> H;
  int n; cin >> n;
  V<lint> d(n); for (auto&& e : d) cin >> e;
  lint h = H, mn = 9e18;
  for (int i = 0; i < n; ++i) {
    if ((h += d[i]) <= 0) {
      return cout << i + 1 << '\n', 0;
    }
    mn = min(mn, h);
  }
  if (h >= H) return cout << -1 << '\n', 0;
  lint k = (mn + (H - h) - 1) / (H - h) - 1;
  lint res = n * k;
  h = H - (H - h) * k;
  for (int i = 0; i < 10 * n; ++i) {
    if ((h += d[i % n]) <= 0) {
      res += i + 1;
      break;
    }
  }
  cout << res << '\n';
}