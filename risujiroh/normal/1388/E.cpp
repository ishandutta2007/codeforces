#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <bool Max = false> struct line_set {
  using ld = long double;
  struct line {
    mutable ld a, b, r = numeric_limits<ld>::max();
    ld operator()(ld x) const { return a * x + b; }
    friend bool operator<(const line& a, const line& b) { return a.a < b.a; }
    friend bool operator<(const line& a, ld b) { return a.r < b; }
  };
  multiset<line, less<>> ms;
  bool add(ld a, ld b) {
    if (not Max) a = -a, b = -b;
    auto needs = [&](auto it) {
      if (it == begin(ms)) return true;
      if (next(it) == end(ms)) return *prev(it) < *it or prev(it)->b < it->b;
      line l = *prev(it), r = *next(it);
      return it->b * (r.a - l.a) > l.b * (r.a - it->a) + r.b * (it->a - l.a);
    };
    auto it = ms.insert({a, b});
    if (not needs(it)) return ms.erase(it), false;
    while (it != begin(ms) and not needs(prev(it))) ms.erase(prev(it));
    if (it != begin(ms)) prev(it)->r = (prev(it)->b - b) / (a - prev(it)->a);
    while (next(it) != end(ms) and not needs(next(it))) ms.erase(next(it));
    if (next(it) != end(ms)) it->r = (b - next(it)->b) / (next(it)->a - a);
    return true;
  }
  ld operator()(ld x) {
    while (begin(ms)->r < x) ms.erase(begin(ms));
    ld res = (*begin(ms))(x);
    return Max ? res : -res;
  }
};

using ld = long double;
constexpr ld eps = 1e-14;
int sgn(ld a) { return (a > eps) - (a < -eps); }
int sgn(ld a, ld b) { return sgn(a - b); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<ld> xl(n), xr(n), y(n), v{0};
  for (int i = 0; i < n; ++i) {
    cin >> xl[i] >> xr[i] >> y[i];
  }
  vector<pair<ld, ld>> lr;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (sgn(y[i], y[j]) >= 0) continue;
      ld l = (xl[i] - xr[j]) / (y[j] - y[i]);
      ld r = (xr[i] - xl[j]) / (y[j] - y[i]);
      v.push_back(l);
      v.push_back(r);
      lr.emplace_back(l, r);
    }
  }
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v), [&](ld a, ld b) { return sgn(a, b) == 0; }), end(v));
  int sz = size(v);
  vector<int> cum(sz + 1);
  for (auto [l, r] : lr) {
    int li = upper_bound(begin(v), end(v), l) - begin(v);
    int ri = lower_bound(begin(v), end(v), r) - begin(v);
    ++cum[li];
    --cum[ri];
  }
  for (int i = 0; i < sz; ++i) {
    cum[i + 1] += cum[i];
  }
  line_set lo;
  line_set<true> hi;
  for (int i = 0; i < n; ++i) {
    lo.add(y[i], xl[i]);
    hi.add(y[i], xr[i]);
  }
  ld res = numeric_limits<ld>::max();
  for (int i = 0; i < sz; ++i) {
    if (cum[i] == 0) {
      res = min(res, hi(v[i]) - lo(v[i]));
    }
  }
  cout << res << '\n';
}