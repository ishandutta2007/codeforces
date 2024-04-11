#include <bits/extc++.h>
using namespace std;

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };
auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    p[i] = {count(begin(s), end(s), 'B'), count(begin(s), end(s), 'N')};
  }
  int mx, my;
  auto chk = [&](int m, bool f = false) {
    int lx = 0, rx = inf<int>;
    int ly = 0, ry = inf<int>;
    int lyx = -inf<int>, ryx = inf<int>;
    for (auto [x, y] : p) {
      chmax(lx, x - m);
      chmin(rx, x + m);
      chmax(ly, y - m);
      chmin(ry, y + m);
      chmax(lyx, y - x - m);
      chmin(ryx, y - x + m);
    }
    if (lx > rx) return false;
    if (ly > ry) return false;
    if (lyx > ryx) return false;
    if (ly - rx > ryx) return false;
    if (ry - lx < lyx) return false;
    if (f) {
      for (int x = lx; x <= rx; ++x) {
        if (max(ly, x + lyx) <= min(ry, x + ryx)) {
          mx = x, my = max(ly, x + lyx);
          break;
        }
      }
    }
    return true;
  };
  int ng = -1, ok = 3e5;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  chk(ok, true);
  cout << ok << '\n';
  if (mx == 0 and my == 0) {
    mx = my = 1;
  }
  cout << string(mx, 'B') + string(my, 'N') << '\n';
}