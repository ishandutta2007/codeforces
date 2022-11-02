#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double r1, r2, r3;
double a12, a13, a23;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double f(double p, int mode = 0)
{
	double A = r1 / r3 / 2.0 + r3 / r1 / 2.0 - a13 * a13 / (2.0 * r1 * r3 * p * p);
	double B = r2 / r3 / 2.0 + r3 / r2 / 2.0 - a23 * a23 / (2.0 * r2 * r3 * p * p);
	double C = r1 / r2 / 2.0 + r2 / r1 / 2.0 - a12 * a12 / (2.0 * r1 * r2 * p * p);
	if (A > 1.0) A = 1.0;
	if (A < -1.0) A = -1.0;

	if (B > 1.0) B = 1.0;
	if (B < -1.0) B = -1.0;

	if (C > 1.0) C = 1.0;
	if (C < -1.0) C = -1.0;

	double a = 1.0, b = 1.0, c = 1.0;
	if (mode == 1) a = -1.0;
	if (mode == 2) b = -1.0;
	if (mode == 3) c = -1.0;

	double res = a * acos(A) + b * acos(B) + c * acos(C);
	return res;
}

double pi=2*acos(0.0);

struct point{
	double x,y;
};

struct circle{
	double x,y;
	double r;
};

struct line{
	double A, B, C;
};

double build_ang(point a,point b){
	double cx=b.x-a.x;
	double cy=b.y-a.y;

	double dx=fabs(cx), dy=fabs(cy);
	double dist=sqrt(dx*dx+dy*dy);
	double ang=acos(dx/dist);

	if (cx>=0&&cy>=0) return ang;
	if (cx>=0&&cy<=0) return 2*pi-ang;
	if (cx<=0&&cy>=0) return pi-ang;
	return pi+ang;
}

vector <point> intersect_circles(circle a,circle b){
	vector <point> rs;
	double dist=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	if (a.r+b.r-dist>-1e-9&&a.r+dist-b.r>-1e-9&&b.r+dist-a.r>-1e-9){
		double A=a.r, B=b.r, C=dist;
		double ang1=acos((A*A+C*C-B*B)/2.0/A/C);
		point a1,a2;
		a1.x=a.x, a1.y=a.y;
		a2.x=b.x, a2.y=b.y;
		double ang2=build_ang(a1,a2);
		point cur1,cur2;
		cur1.x=A*cos(ang2+ang1)+a.x, cur1.y=A*sin(ang2+ang1)+a.y;
		cur2.x=A*cos(ang2-ang1)+a.x, cur2.y=A*sin(ang2-ang1)+a.y;
		rs.push_back(cur1);
		if (!(fabs(cur2.x-cur1.x)<1e-9&&fabs(cur2.y-cur1.y)<1e-9)) rs.push_back(cur2);
		return rs;
	} else return rs;
}

double calc_l(double r1, double r3, double a13)
{
	double A = r1 / 2.0 / r3 + r3 / 2.0 / r1;
	double B = (a13 * a13) / (2.0 * r1 * r3);
	return sqrt(B / (A + 1.0));
}

double calc_r(double r1, double r3, double a13)
{
	double A = r1 / 2.0 / r3 + r3 / 2.0 / r1;
	double B = (a13 * a13) / (2.0 * r1 * r3);
	return sqrt(B / (A - 1.0));
}

point solve(circle A, circle B, circle C)
{
	vector < point > cur;
	vector < point > buf = intersect_circles(A, B);
	for (int i = 0; i < buf.size(); i ++)
		cur.push_back(buf[i]);
	buf = intersect_circles(A, C);
	for (int i = 0; i < buf.size(); i ++)
		cur.push_back(buf[i]);
	buf = intersect_circles(C, B);
	for (int i = 0; i < buf.size(); i ++)
		cur.push_back(buf[i]);

	for (int i = 0; i < cur.size(); i ++)
		for (int j = i + 1; j < cur.size(); j ++)
			if (fabs(cur[i].x - cur[j].x) < 1e-8 && fabs(cur[i].y - cur[j].y) < 1e-8)
				return cur[i];

	point res;
	res.x = -1000000, res.y = -1000000;
	return res;
}

double best = 0.0;
point res;

int main()
{
	res.x = -1000000, res.y = -1000000;
	double x1, y1, x2, y2, x3, y3;
	scanf("%lf%lf%lf", &x1, &y1, &r1);
	scanf("%lf%lf%lf", &x2, &y2, &r2);
	scanf("%lf%lf%lf", &x3, &y3, &r3);
	a12 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	a13 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	a23 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));

	double l = 0.0, r = 2000.0;
	l = max(l, calc_l(r1, r2, a12));
	l = max(l, calc_l(r1, r3, a13));
	l = max(l, calc_l(r3, r2, a23));

	r = min(r, calc_r(r1, r2, a12));
	r = min(r, calc_r(r1, r3, a13));
	r = min(r, calc_r(r3, r2, a23));
	double ol = l, or = r;
	int t = 0;
	while (t < 60)
	{
		t ++;
		double key = (l + r) / 2.0;
		if (f(key) < 4.0 * acos(0.0))
			r = key; else l = key;
	}

	if (fabs(f(l) - 4.0 * acos(0.0)) > 1e-8)
	{
		for (int i = 1; i <= 3; i ++)
		{
			l = ol, r = or;
			int t = 0;
			while (t < 60)
			{
				t ++;
				double k1 = (l + l + r) / 3.0;
				double k2 = (l + r + r) / 3.0;
				if (f(k1, i) > f(k2, i))
					r = k2; else l = k1;
			}

			double mid = l;
			l = ol, r = mid;
			t = 0;
			while (t < 60)
			{
				t ++;
				double key = (l + r) / 2.0;
				if (f(key, i) > 0)
					r = key; else l = key;
			}

			circle A, B, C;
			A.x = x1, A.y = y1, A.r = r1 * l;
			B.x = x2, B.y = y2, B.r = r2 * l;
			C.x = x3, C.y = y3, C.r = r3 * l;

			point ans = solve(A, B, C);
			if (ans.x > -100000)
			{
				if (asin(1.0 / l) > best)
					best = asin(1.0 / l), res = ans;
				//printf("%.10lf %.10lf\n", ans.x, ans.y);
			}

			l = mid, r = or;
			t = 0;
			while (t < 60)
			{
				t ++;
				double key = (l + r) / 2.0;
				if (f(key, i) < 0)
					r = key; else l = key;
			}

			A, B, C;
			A.x = x1, A.y = y1, A.r = r1 * l;
			B.x = x2, B.y = y2, B.r = r2 * l;
			C.x = x3, C.y = y3, C.r = r3 * l;

			ans = solve(A, B, C);
			if (ans.x > -100000)
			{
				if (asin(1.0 / l) > best)
					best = asin(1.0 / l), res = ans;
				//printf("%.10lf %.10lf\n", ans.x, ans.y);
			}
		}
		if (res.x > -100000)
		{
			printf("%.10lf %.10lf\n", res.x, res.y);
		}
	}

	circle A, B, C;
	A.x = x1, A.y = y1, A.r = r1 * l;
	B.x = x2, B.y = y2, B.r = r2 * l;
	C.x = x3, C.y = y3, C.r = r3 * l;

	point ans = solve(A, B, C);
	if (ans.x > -100000)
	{
		printf("%.10lf %.10lf\n", ans.x, ans.y);
	}


	return 0;
}