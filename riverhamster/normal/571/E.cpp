// submitted with luogu
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <map>
#include <cmath>
#include <tuple>
#include <stdexcept>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int M = 1000000007;

int power(int x, ll y) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll ret = exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - a / b * y;
  return ret;
}

using num = map<int, ll>;

num to_num(int n) {
  num res;
  for (int i = 2, li = sqrt(n); i <= li; ++i) {
    if (n % i == 0) {
      auto p = res.emplace(i, 0).first;
      do ++p->second, n /= i; while (n % i == 0);
    }
  }
  if (n > 1) res.emplace(n, 1);
  return res;
}

int to_int(const num &n) {
  int res = 1;
  for (const auto &p : n)
    res = (ll)res * power(p.first, p.second) % M;
  return res;
}

void fail() { puts("-1"); exit(0); }

const ll is_point = -7e18;

struct line {
  ll A, B, C;
  line() : A(0), B(0), C(0) {} // no constraints
  line(ll a, ll b, ll c) : A(a), B(b), C(c) {}
  line normalize() const {
    ll d = gcd(abs(A), abs(B)); d = gcd(d, abs(C));
    if (A < 0) d = -d;
    return {A / d, B / d, C / d};
  }
  bool on_line(const line &rhs) const {
    assert(rhs.C == is_point);
    return A * rhs.A + B * rhs.B + C == 0;
  }
  bool operator==(const line &rhs) const { return A == rhs.A && B == rhs.B && C == rhs.C; }
};

line intersect(line a, line b) {
  // printf("ADD LINE : %lldx + %lldy + %lld = 0\n", b.A, b.B, b.C);
  if (a == line()) return b;
  if (b == line()) return a;
  if (a.C == is_point && b.C == is_point) {
    if (a == b) return a;
    fail();
  }
  if (a.C == is_point || b.C == is_point) {
    if (a.C == is_point) swap(a, b);
    if (a.on_line(b)) return b;
    fail();
  }
  a = a.normalize(); b = b.normalize();
  if (a == b) return a;
  if (a.A == b.A && a.B == b.B) fail();
  ll det = a.A * b.B - a.B * b.A;
  if (det == 0) fail();
  ll d1 = -a.C * b.B + a.B * b.C;
  if (d1 % det != 0) fail();
  ll d2 = -a.A * b.C + a.C * b.A;
  if (d2 % det != 0) fail();
  return line(d1 / det, d2 / det, is_point);
}

ll value(const num &n, int key) {
  auto it = n.find(key);
  if (it != n.end()) return it->second;
  return 0;
}

// returns first solution and step size
pair<ll, ll> solve_nonnegative(const line &l) {
  if (l.A == 0 && l.B == 0) return make_pair(0, 1);
  ll x, y; ll d = exgcd(abs(l.A), abs(l.B), x, y);
  if (l.C % d != 0) fail();
  if (l.A < 0) x = -x;
  if (l.B < 0) y = -y;
  x *= -l.C / d; y *= -l.C / d;
  ll stepx = abs(l.B / d), stepy = abs(l.A / d);
  ll cx = l.B < 0 ? -1 : 1, cy = l.A < 0 ? -1 : 1;
  if (stepx) {
    if (x < 0) {
      ll c = (-x + stepx - 1) / stepx * cx;
      x += c * stepx * cx; y -= stepy * c * cy;
      assert(x >= 0);
      if (x >= 0 && y >= 0) return make_pair(x, stepx);
    }
    else {
      ll c = x / stepx * cx;
      x -= c * stepx * cx; y += stepy * c * cy;
      assert(x >= 0);
      if (x >= 0 && y >= 0) return make_pair(x, stepx);
    }
  }
  if (stepy) {
    if (y < 0) {
      ll c = (-y + stepy - 1) / stepy * cy;
      y += c * stepy * cy; x -= stepx * c * cx;
      assert(y >= 0);
      if (x >= 0 && y >= 0) return make_pair(x, stepx);
    }
    else {
      ll c = y / stepy * cy;
      y -= c * stepy * cy; x += c * stepx * cx;
      assert(y >= 0);
      if (x >= 0 && y >= 0) return make_pair(x, stepx);
    }
  }
  throw logic_error("solution not found, maybe A, B are of the same sign?");
}

pair<num, num> combine(const num &p1, const num &q1, const num &p2, const num &q2) {
  vector<int> f;
  auto insert_factors = [&](const num &n) { for (const auto &p : n) f.push_back(p.first); };
  insert_factors(p1); insert_factors(q1); insert_factors(p2); insert_factors(q2);
  sort(f.begin(), f.end());
  f.erase(unique(f.begin(), f.end()), f.end());
  line L;
  for (int p : f) {
    ll P1 = value(p1, p), Q1 = value(q1, p), P2 = value(p2, p), Q2 = value(q2, p);
    L = intersect(L, line(Q1, -Q2, P1 - P2));
  }
  if (L.C == is_point) {
    if (L.A < 0 || L.B < 0) fail();
    num ret = p1;
    for (const auto &p : q1) {
      ret[p.first] += p.second * L.A;
    }
    return make_pair(ret, num());
  }
  auto _ret = solve_nonnegative(L);
  num first, step;
  first = p1;
  for (const auto &p : q1)
    first[p.first] += p.second * _ret.first;
  step = q1;
  for (auto &p : step)
    p.second *= _ret.second;
  return make_pair(first, step);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, u, v;
  num a, b;
  read(n);
  read(u, v);
  a = to_num(u); b = to_num(v);
  for (int i = 2; i <= n; ++i) {
    read(u, v);
    tie(a, b) = combine(a, b, to_num(u), to_num(v));
  }
  printf("%d\n", to_int(a));
  return 0;
}