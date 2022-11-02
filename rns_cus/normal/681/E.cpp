#include <bits/stdc++.h>
using namespace std;
#define M 400010
#define ep 1e-12

const double pi = acos(-1);

struct pnt {
	double x, y;
	pnt (double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator +(pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator -(pnt a) {return pnt(x - a.x, y - a.y);}
	pnt operator /(double a) {return pnt(x / a, y / a);}
	pnt operator *(double a) {return pnt(x * a, y * a);}
	double operator ^ (pnt a) {return x * a.y - y * a.x;}
	double operator & (pnt a) {return x * a.x + y * a.y;}
	double dist() {return sqrt(x * x + y * y);}
	void input() {scanf("%lf %lf", &x, &y);}
	void print() {printf("%lf %lf\n", x, y);}
	double angle() {return atan2(y, x);}
} c[M], o;

pnt cr[10];

inline pnt rot(pnt p) { return pnt(-p.y, p.x); }

int TangentPoint(pnt c, double r, pnt a){
	double d = (c - a).dist();
	if (d < r - ep) return 0;
	if (fabs(d - r) < ep) {
		cr[0] = a;
		return 1;
	}
	double x = r * r / d;
	pnt cp = (c * (d - x) + a * x) / d;
	double h = sqrt(r * r - x * x);
	pnt dv = rot(c - a) * h / d;
	cr[0] = cp + dv;
	cr[1] = cp - dv;
	return 2;
}

int intersect_CC(pnt c, double r, pnt cc, double rr) {
	double d = (c - cc).dist();
	if (r + rr < d + ep || r + d < rr + ep || rr + d < r + ep) return 0;
	double x = (r * r - rr * rr + d * d) / (d * 2);
	pnt cp = (c * (d - x) + cc * x) / d;
	double h = sqrt(r * r - x * x);
	pnt dv = rot(cc - c) * h / d ;
	cr[0] = cp - dv;
	cr[1] = cp + dv;
	return 1;
}

pair <double, double> p[M];

int cnt;

void ins(double l, double r) {
  if (l > r) swap(l, r);
  if (r - l > pi) {
    ins(r, pi); ins(-pi, l); return;
  }
  p[cnt++] = make_pair(l, r);
}

double v, t;
double r[M];
int n;

int main() {
  //freopen("in.txt", "r", stdin);
  o.input();
  scanf("%lf %lf", &v, &t);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    c[i].input(); scanf("%lf", r + i);
  }
  double R = v * t;
  for (int i = 0; i < n; i++) {
    if ((o - c[i]).dist() <= r[i]){
      return printf("%.12lf\n", 1.), 0;
    }
    if ((o - c[i]).dist() < r[i] + R - ep) {
      if ((o - c[i]).dist() < R || (o - c[i]).dist() < sqrt(R * R + r[i] * r[i])) {
        TangentPoint(c[i], r[i], o);
        double al = (cr[0] - o).angle(), be = (cr[1] - o).angle();
        ins(al, be);
      }
      else {
        intersect_CC(o, R, c[i], r[i]);
        double al = (cr[0] - o).angle(), be = (cr[1] - o).angle();
        ins(al, be);
      }
    }
  }
  sort(p, p + cnt);
  double tot = 0;
  double st = p[0].first, en = p[0].second;
  for (int i = 1; i < cnt; i++) {
    if (p[i].first > en + ep) {
      tot += (en - st); st = p[i].first, en = p[i].second;
    }
    else {
      en = max(en, p[i].second);
    }
  }
  tot += (en - st);
  printf("%.12lf\n", tot / pi / 2);
}