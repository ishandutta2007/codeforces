#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  int n; cin >> n;
  auto query = [&](int x0, int y0, int x1, int y1) -> int {
    assert(0 <= x0 and x0 < x1 and x1 <= n);
    assert(0 <= y0 and y0 < y1 and y1 <= n);
    cout << "? " << x0 + 1 << ' ' << y0 + 1 << ' ' << x1 << ' ' << y1 << endl;
    int res; cin >> res;
    return res;
  };
  auto answer = [&](int x0, int y0, int x1, int y1) -> void {
    assert(0 <= x0 and x0 < n);
    assert(0 <= y0 and y0 < n);
    assert(0 <= x1 and x1 < n);
    assert(0 <= y1 and y1 < n);
    cout << "! " << x0 + 1 << ' ' << y0 + 1 << ' ' << x1 + 1 << ' ' << y1 + 1 << endl;
    exit(0);
  };
  V<> px(n), py(n);
  for (int i = 1; i < n; ++i) {
    px[i] = query(0, 0, i, n) & 1;
    py[i] = query(0, 0, n, i) & 1;
  }
  int sx = accumulate(begin(px), end(px), 0);
  int sy = accumulate(begin(py), end(py), 0);
  auto fx = [&]() -> pair<int, int> {
    int x0 = -1, x1 = -1;
    for (int i = 0; i < n; ++i) if (px[i]) {
      x0 = i - 1;
      break;
    }
    for (int i = n - 1; i >= 0; --i) if (px[i]) {
      x1 = i;
      break;
    }
    return {x0, x1};
  };
  auto fy = [&]() -> pair<int, int> {
    int y0 = -1, y1 = -1;
    for (int i = 0; i < n; ++i) if (py[i]) {
      y0 = i - 1;
      break;
    }
    for (int i = n - 1; i >= 0; --i) if (py[i]) {
      y1 = i;
      break;
    }
    return {y0, y1};
  };
  if (sx and sy) {
    int x0, y0, x1, y1;
    tie(x0, x1) = fx();
    tie(y0, y1) = fy();
    if (query(x0, y0, x0 + 1, y0 + 1) != 1) swap(y0, y1);
    answer(x0, y0, x1, y1);
  }
  if (!sx) {
    assert(sy);
    int y0, y1;
    tie(y0, y1) = fy();
    int ok = 0, ng = n;
    while (ng - ok > 1) {
      int md = ok + ng >> 1;
      (query(md, y0, n, y0 + 1) & 1 ? ok : ng) = md;
    }
    int x0 = ok;
    ok = 0, ng = n;
    while (ng - ok > 1) {
      int md = ok + ng >> 1;
      (query(md, y1, n, y1 + 1) & 1 ? ok : ng) = md;
    }
    int x1 = ok;
    answer(x0, y0, x1, y1);
  }
  if (!sy) {
    assert(sx);
    int x0, x1;
    tie(x0, x1) = fx();
    int ok = 0, ng = n;
    while (ng - ok > 1) {
      int md = ok + ng >> 1;
      (query(x0, md, x0 + 1, n) & 1 ? ok : ng) = md;
    }
    int y0 = ok;
    ok = 0, ng = n;
    while (ng - ok > 1) {
      int md = ok + ng >> 1;
      (query(x1, md, x1 + 1, n) & 1 ? ok : ng) = md;
    }
    int y1 = ok;
    answer(x0, y0, x1, y1);
  }
}