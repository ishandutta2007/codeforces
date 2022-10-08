#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

const db eps = 1e-8;

int sgn(db x) {
  if (x > eps) return 1; else
  if (x < -eps) return -1;
  return 0;
}

db ssqrt(db x) {
  return sqrt(max(x, 0.0));
}

struct P {
  db x, y;
  P() {}
  P(db _x, db _y):x(_x), y(_y) {}
  P operator + (const P&a) const {return P(x+a.x, y+a.y);}
  P operator - (const P&a) const {return P(x-a.x, y-a.y);}
  P operator * (db a) const {return P(x*a, y*a);}
  P operator / (db a) const {return P(x/a, y/a);}
  db crs (const P&a) const {return x*a.y - y*a.x;}
  db dot (const P&a) const {return x*a.x + y*a.y;}
  db abs2 () const {return x*x+y*y;}
  db abs () const {return sqrt(abs2());}
  db dis (const P&a) const {return (*this-a).abs();}
  db dis2 (const P&a) const {return (*this-a).abs2();}
  db tan() const {return atan2(y, x);}
  db rad(const P&a) const {return atan2(crs(a), dot(a));}
  P rot90() const {return P(-y, x);}
  bool operator < (const P&a) const {
    return x < a.x - eps || x < a.x + eps && y < a.y - eps;
  }
  bool operator == (const P&a) const {
    return fabs(x-a.x) < eps && fabs(y-a.y) < eps;
  }
  void get () {cin >> x >> y;}
  void out () const {printf ("%.9lf %.9lf\n", x, y);}
};

int main() {
	int a, b, c, x1, y1, x2, y2;
	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
	db S = (db)abs(x1-x2) + abs(y1-y2);
	vector<P> p1, p2;
	// p1.pb(P(x1, y1));
	if (b != 0) p1.pb(P(x1, (db)(-c-(db)a*x1)/b));
	if (a != 0) p1.pb(P((db)(-c-(db)b*y1)/a, y1));
	// p2.pb(P(x2, y2));
	if (b != 0) p2.pb(P(x2, (db)(-c-(db)a*x2)/b));
	if (a != 0) p2.pb(P((db)(-c-(db)b*y2)/a, y2));

	for (auto w1 : p1)
		for (auto w2 : p2)
			S = min(S, w1.dis(P(x1, y1)) + w1.dis(w2) + w2.dis(P(x2, y2)));
	printf("%.9lf\n", S);
	return 0;
}