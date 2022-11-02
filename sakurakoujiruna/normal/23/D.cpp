#include <bits/stdc++.h>
using namespace std;

//#define double long double
const double Eps = 1e-6;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}
const double Pi = 4 * atan(1);

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	Point operator /(double d) {
		return {x / d, y / d};
	}
	Point operator *(double d) {
		return {x * d, y * d};
	}
	Point rot(double d) {
		double rx = x * cos(d) - y * sin(d);
		double ry = x * sin(d) + y * cos(d);
		return {rx, ry};
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
};
double xmul(Point a, Point b, Point c) {
	return (b - a).cross(c - a);
}
Point inter(Point p1, Point p2, Point q1, Point q2) {
	double u = xmul(p1, p2, q1);
	double v = xmul(p2, p1, q2);
	double rx = (q1.x * v + q2.x * u) / (v + u);
	double ry = (q1.y * v + q2.y * u) / (v + u);
	return {rx, ry};
}

Point circum(Point p, Point q, Point r) {
	Point mpq = (p + q) / 2;
	Point dpq = (q - p).rot(Pi / 2);
	Point mqr = (q + r) / 2;
	Point dqr = (r - q).rot(Pi / 2);
	return inter(mpq, mpq + dpq, mqr, mqr + dqr);
}

Point A, B, C, D;
bool solve(Point p, Point q, Point r)
{
	if(sgn(xmul(p, q, r)) == 0)
		return false;
	Point sr = p * 2 - r;
	C = circum(sr, p, q);
	D = q * 2 - C;
	B = p * 2 - C;
	A = r * 2 - B;
	if(sgn(xmul(A, B, D)) > 0 &&
		sgn(xmul(B, C, A)) > 0 &&
		sgn(xmul(C, D, B)) > 0 &&
		sgn(xmul(D, A, C)) > 0)
		return true;
	return false;
}

int main()
{
	//ios :: sync_with_stdio(false);
	int kase;
	//cin >> kase;
	scanf("%d", &kase);
	//cout << fixed << setprecision(9);
	while(kase --)
	{
		Point p, q, r;
		//cin >> p.x >> p.y;
		//cin >> q.x >> q.y;
		//cin >> r.x >> r.y;
		scanf("%lf%lf%lf%lf%lf%lf", &p.x, &p.y, &q.x, &q.y, &r.x, &r.y);
		if(sgn(xmul(p, q, r)) <= 0)
			swap(q, r);
		if(solve(p, q, r) ||
			solve(q, r, p) ||
			solve(r, p, q))
		{
			//cout << "YES\n";
			printf("YES\n");
			//cout << A.x << ' ' << A.y << ' ';
			printf("%.9f %.9f ", A.x, A.y);
			//cout << B.x << ' ' << B.y << ' ';
			printf("%.9f %.9f ", B.x, B.y);
			//cout << C.x << ' ' << C.y << ' ';
			printf("%.9f %.9f ", C.x, C.y);
			//cout << D.x << ' ' << D.y << '\n';
			printf("%.9f %.9f\n", D.x, D.y);
		}
		else
			//cout << "NO\n\n";
			printf("NO\n\n");
	}
	return 0;
}