#include <bits/stdc++.h>
using namespace std;
#define M 100010
#define ep 1e-7

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
} pos[M], A, B;

double vec[M], a[M], w[M];
int n;

double angle(pnt b, pnt a, pnt c) {
	return acos((b - a & c - a) / (c - a).dist() / (b - a).dist());
}

double D;
int P;

double f(double x, int i, double d, double t, double dl, double v, double al) {
	return dl + v * x - d * sin(w[i] * x) / sin(al + w[i] * x);
}

bool check(double v) {
	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (tot > P) return 0;
		pnt tp = pnt(cos(a[i]), sin(a[i]));
		double t = angle(pos[i] + tp, pos[i], B) / w[i];
		if (v * t < D) {tot++; continue;}
		t = angle(pos[i] + tp, pos[i], A) / w[i];
		if (v * t > D - ep) continue;
		double al = angle(pos[i], A, B);
		if (al > pi / 2 - ep) continue;
    double d = (pos[i] - A).dist();
    double T = (D - v * t) / v, dl = v * t;
    double st = 0, en = T;
    while (st < en - ep) {
			double x = (2 * st + en) / 3, y = (st + 2 * en) / 3;
			if (f(x, i, d, t, dl, v, al) < f(y, i, d, t, dl, v, al)) en = y;
			else st = x;
    }
    if (f(st, i, d, t, dl, v, al) < ep) tot++;
	}
	if (tot > P) return 0;
	return 1;
}

int main() {
	//freopen("F.in", "r", stdin);
	A.input(), B.input();
	D = (A - B).dist();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		pos[i].input(); cin >> a[i] >> w[i];
	}
	scanf("%d", &P);
	double l = 0, r = 1e9;
	while (l < r - ep) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.12lf\n", l);
}