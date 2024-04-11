#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  using num = double;
  constexpr num eps = 1e-10, inf = 1e10;

  num tx, ty;
  {
    num ox, oy;
    cin >> ox >> oy >> tx >> ty;
    tx -= ox;
    ty -= oy;
  }
  num r, t;
  cin >> r >> t;
  num vx, vy;
  cin >> vx >> vy;
  num wx, wy;
  cin >> wx >> wy;

  if (hypot(tx, ty) < eps) {
    cout << num(0) << '\n';
    exit(0);
  }

  if (hypot(tx - vx * t, ty - vy * t) <= r * t) {
    num ex = tx, ey = ty;
    ex /= hypot(tx, ty);
    ey /= hypot(tx, ty);
    assert(abs(hypot(ex, ey) - 1) < eps);
    num ok = 0, ng = 1e4;
    for (int _ = 60; _--;) {
      num mid = (ok + ng) / 2;
      (hypot(ex * mid - vx, ey * mid - vy) <= r ? ok : ng) = mid;
    }
    num x = ex * ok, y = ey * ok;
    cout << hypot(tx, ty) / hypot(x, y) << '\n';
    exit(0);
  }

  num ox = tx - vx * t, oy = ty - vy * t;
  auto f = [&](num th) -> num {
    num ex = cos(th), ey = sin(th);
    num ok = 0, ng = 1e4;
    for (int _ = 60; _--;) {
      num mid = (ok + ng) / 2;
      (hypot(ex * mid - wx, ey * mid - wy) <= r ? ok : ng) = mid;
    }
    num x = ex * ok, y = ey * ok;
    num d = ox * ey - oy * ex;
    if (abs(d) > r * t + eps) return inf;
    num len = sqrt(max((r * t) * (r * t) - d * d, eps * eps));
    num nx = ox - ey * d - ex * len;
    num ny = oy + ex * d - ey * len;
    return hypot(nx, ny) / hypot(x, y);
  };

  num center = atan2(oy, ox);
  assert(f(center) < inf);
  num ll;
  {
    num ng = center - acos(0), ok = center;
    for (int _ = 60; _--;) {
      num mid = (ng + ok) / 2;
      (f(mid) < inf ? ok : ng) = mid;
    }
    ll = ok;
  }
  num rr;
  {
    num ok = center, ng = center + acos(0);
    for (int _ = 60; _--;) {
      num mid = (ok + ng) / 2;
      (f(mid) < inf ? ok : ng) = mid;
    }
    rr = ok;
  }
  for (int _ = 100; _--;) {
    num ml = (2 * ll + rr) / 3;
    num mr = (ll + 2 * rr) / 3;
    if (f(ml) < f(mr))
      rr = mr;
    else
      ll = ml;
  }
  cout << t + f(ll) << '\n';
}