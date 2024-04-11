#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
#include <iostream>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;
using fp = double;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

struct pt {
  fp x, y;
  pt() = default;
  pt(fp _x, fp _y) : x(_x), y(_y) {}
  pt(const pt &a, const pt &b) : x(b.x - a.x), y(b.y - a.y) {}
};
using vec = pt;

fp dot(const vec &a, const vec &b) { return a.x * b.x + a.y * b.y; }
fp cross(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }

const int N = 1005;
const fp MAX_ANS = 1e9 + 30;
const fp eps = 1e-6;
const fp PI = 3.141592653589793238462643383279502884, PI_2 = 2 * 3.141592653589793238462643383279502884;

mt19937 rng;

pt R[N], B[N];
int n, m;

struct event {
  fp angle;
  int val;
  event() = default;
  event(fp _a, int _v) : angle(_a), val(_v) {}
  bool operator<(const event &rhs) const { return angle < rhs.angle; }
};

struct intersect {
  fp l, r;
  bool exist;
  intersect() = default;
  intersect(fp _l, fp _r, bool _e) : l(_l), r(_r), exist(_e) {}
};

intersect circle_intersect(const pt &P, fp r, const pt &Q) {
  fp d2 = (Q.y - P.y) * (Q.y - P.y) + (Q.x - P.x) * (Q.x - P.x);
  if (d2 > 4 * r * r) return {0, 0, false};
  fp med = atan2(Q.y - P.y, Q.x - P.x);
  fp d = sqrt(d2);
  fp ang = acos(d / r * 0.5);
  fp L = fmod(med - ang + PI_2, PI_2);
  fp R = fmod(med + ang, PI_2);
  if (L >= PI) L -= PI_2;
  if (R >= PI) R -= PI_2;
  return {L, R, true};
}

bool check(pt P, fp r, bool add_R) {
  vector<event> E;
  int cur = 0;
  if (add_R) {
    for (int i = 0; i < n; ++i) {
      const auto [lb, rb, exi] = circle_intersect(P, r, R[i]);
      if (exi) {
        E.emplace_back(lb, 1); E.emplace_back(rb, -1);
        if (lb > rb) ++cur;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (B[i].x == P.x && B[i].y == P.y) continue;
    const auto &[lb, rb, exi] = circle_intersect(P, r, B[i]);
    if (exi) {
      E.emplace_back(lb, -N); E.emplace_back(rb, N);
      if (lb > rb) cur -= N;
    }
  }
  sort(all(E));
  if (E.empty() && !add_R) return true;
  for (const auto &e : E) {
    cur += e.val;
    if (cur >= (int)add_R) return true;
  }
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m);
  for (int i = 0; i < n; ++i)
    read(R[i].x, R[i].y);
  for (int i = 0; i < m; ++i)
    read(B[i].x, B[i].y);
  shuffle(R, R + n, rng);
  shuffle(B, B + m, rng);

  fp res = 0.1;
  for (int i = 0; i < n; ++i) {
    if (!check(R[i], res, false)) continue;
    fp l = res, r = MAX_ANS;
    while (r - l > eps) {
      fp mid = (l + r) / 2;
      if (check(R[i], mid, false)) l = mid;
      else r = mid;
    }
    res = l;
  }
  for (int i = 0; i < m; ++i) {
    if (!check(B[i], res, true)) continue;
    fp l = res, r = MAX_ANS;
    while (r - l > eps) {
      fp mid = (l + r) / 2;
      if (check(B[i], mid, true)) l = mid;
      else r = mid;
    }
    res = l;
  }
  if (res > 1e9) puts("-1");
  else printf("%.9g\n", res);
  return 0;
}