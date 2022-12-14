#include <bits/stdc++.h>
using namespace std;
#define ep 1e-9
#define M 200010
struct pnt {
	double x, y;
	pnt (double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator + (pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator - (pnt a) {return pnt(x - a.x, y - a.y);}
	pnt operator * (double a) {return pnt(x * a, y * a);}
	pnt operator / (double a) {return pnt(x / a, y / a);}
	double operator ^ (pnt a) {return x * a.y - y * a.x;}
	double operator & (pnt a) {return x * a.x + y * a.y;}
	double dist() {return sqrt(x * x + y * y);}
	double DIST() {return x * x + y * y;}
	void input() {scanf("%lf %lf", &x, &y);}
} p[M], q[M];

bool inside(pnt a, pnt b, pnt c) {
	return fabs((a - b).dist() + (a - c).dist() - (b - c).dist()) < ep;
}

int insideP(pnt *p, pnt q, int n) {
	int cross = 0;
	for (int i = 0; i < n; i ++) {
		int j = (i + 1) % n;
		if (inside(q, p[i], p[j])) return 1;
		if (p[j].y > q.y && p[i].y <= q.y ||
			p[i].y > q.y && p[j].y <= q.y) {
			double x = (p[j] - q ^ p[i] - q) * (p[i].y - p[j].y);
			if (x > ep) cross ++;
		}
	}
	return cross % 2;
}

bool intersect(pnt a, pnt b, pnt c, pnt d, pnt &res) {
	double den = a - b ^ c - d;
	if (fabs(den) < ep) return 0;		//The two lines are parallel...
	double x = (a - d ^ c - d) / den;
	res = a * (1 - x) + b * x;
	return 1;						//The two lines are intersect...
}

pnt rot(pnt p) {return pnt(-p.y, p.x);}

int main() {
	//freopen("E.in", "r", stdin);
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) p[i].input();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) q[i].input();

	pnt o = pnt(0, 0);
	for (int i = 0; i < n; i++) o.x += p[i].x, o.y += p[i].y;
	o = o / n;
	pnt pos;
  if (insideP(q, o, m)) pos = o;
  else {
  	double mn = 1e20;
  	for (int i = 0; i < m; i++) {
  		if ((o - q[i]).dist() < mn) mn = (o - q[i]).dist(), pos = q[i];
  	}
  	q[m] = q[0];
  	for (int i = 0; i < m; i++) {
			if (((q[i+1] - q[i]) & (o - q[i])) > -ep && ((q[i] - q[i+1]) & (o - q[i+1])) > -ep) {
				double tmp = fabs((q[i] - o) ^ (q[i+1] - o)) / (q[i+1] - q[i]).dist();
				if (tmp < mn) {
					mn = tmp;	intersect(q[i], q[i+1], o, o + rot(q[i] - q[i+1]), pos);
				}
			}
  	}
  }
  double ans = 0;
  for (int i = 0; i < n; i++) ans += (pos - p[i]).DIST();
	printf("%.12lf\n", ans);
}