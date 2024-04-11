#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> point;

#define x first
#define y second

const int N = 200010;

struct line {
  ll a, b, c;

  line (ll _a = 0, ll _b = 0, ll _c = 0) {
    a = _a, b = _b, c = _c;
    if (a < 0 or (a == 0 and b < 0)) a = -a, b = -b, c = -c;
    ll g = __gcd(abs(c), __gcd(abs(a), abs(b)));
    a /= g, b /= g, c /= g;
  }

  line (point P, point Q) {
    ll dx = P.x - Q.x, dy = P.y - Q.y;
    a = dy, b = -dx, c = dy * P.x - dx * P.y;
    if (a < 0 or (a == 0 and b < 0)) a = -a, b = -b, c = -c;
    ll g = __gcd(abs(c), __gcd(abs(a), abs(b)));
    a /= g, b /= g, c /= g; 
  }
};

pair <ld, ld> intersecc (line P, line Q) {
  pair <ld, ld> ret;
  ret.x = (ld) (P.c * Q.b - P.b * Q.c) / (P.a * Q.b - P.b * Q.a);
  ret.y = (ld) (P.a * Q.c - P.c * Q.a) / (P.a * Q.b - P.b * Q.a);
  return ret;
}

inline ld dist (point a, point b) {
  return hypotl(a.x - b.x, a.y - b.y);
}

inline ll area (point a, point b, point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

point p[N];
int n; ll H;

int main() {
  cin >> n >> H;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &p[i].x, &p[i].y);
  }
  int last = n - 1;
  point eye(p[n].x, p[n].y + H);
  ld ans = dist(p[n - 1], p[n]);
  for (int i = n - 2; i >= 1; --i) {
    if (area(eye, p[last], p[i]) > 0) continue;
    if (area(eye, p[last], p[i]) == 0 and area(eye, p[last], p[i + 1]) == 0) {
      ans += dist(p[i], p[i + 1]);
      last = i; continue;
    }
    line eyeLine(eye, p[last]), curLine(p[i], p[i + 1]);
    pair <ld, ld> inter = intersecc(eyeLine, curLine);
    ans += hypotl(abs(inter.x - p[i].x), abs(inter.y - p[i].y));
    last = i;
  }
  printf("%0.16f\n", (double) ans);
  return 0;
}