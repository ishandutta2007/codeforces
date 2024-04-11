#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> sx(n), tx(n), sy(n), ty(n), xs, ys;
  for (int i = 0; i < n; ++i) {
    cin >> sx[i] >> sy[i] >> tx[i] >> ty[i];
    xs.push_back(sx[i]);
    xs.push_back(tx[i]);
    ys.push_back(sy[i]);
    ys.push_back(ty[i]);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  sort(begin(ys), end(ys));
  ys.erase(unique(begin(ys), end(ys)), end(ys));
  for (int i = 0; i < n; ++i) {
    sx[i] = lower_bound(begin(xs), end(xs), sx[i]) - begin(xs);
    tx[i] = lower_bound(begin(xs), end(xs), tx[i]) - begin(xs);
    sy[i] = lower_bound(begin(ys), end(ys), sy[i]) - begin(ys);
    ty[i] = lower_bound(begin(ys), end(ys), ty[i]) - begin(ys);
  }
  int X = xs.size() - 1, Y = ys.size() - 1;
  auto fn = [&](const auto& fn, int lx, int ux, int ly, int uy) -> bool {
    int c = 0;
    for (int i = 0; i < n; ++i) {
      c += lx <= sx[i] and tx[i] <= ux and ly <= sy[i] and ty[i] <= uy;
    }
    if (c < 2) return true;
    V<> cx(X + 1), cy(Y + 1);
    for (int i = 0; i < n; ++i) if (lx <= sx[i] and tx[i] <= ux and ly <= sy[i] and ty[i] <= uy) {
      ++cx[sx[i] + 1], --cx[tx[i]];
      ++cy[sy[i] + 1], --cy[ty[i]];
    }
    for (int x = 0; x < X; ++x) cx[x + 1] += cx[x];
    for (int y = 0; y < Y; ++y) cy[y + 1] += cy[y];
    for (int x = lx + 1; x < ux; ++x) if (!cx[x]) {
      return fn(fn, lx, x, ly, uy) and fn(fn, x, ux, ly, uy);
    }
    for (int y = ly + 1; y < uy; ++y) if (!cy[y]) {
      return fn(fn, lx, ux, ly, y) and fn(fn, lx, ux, y, uy);
    }
    return false;
  };
  cout << (fn(fn, 0, X, 0, Y) ? "YES" : "NO") << '\n';
}