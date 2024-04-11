#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

#define double long double
const double Eps = 1e-8;
const double Pi = 4 * atan(1);
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	Point operator *(double d) {
		return {x * d, y * d};
	}
	Point operator /(double d) {
		return {x / d, y / d};
	}
	double length2() {
		return x * x + y * y;
	}
	double length() {
		return sqrt(length2());
	}
	Point rotate(double a) {
		double rx = x * cos(a) - y * sin(a);
		double ry = y * cos(a) + x * sin(a);
		return {rx, ry};
	}
	double dot(Point p) {
		return x * p.x + y * p.y;
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
};

double xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

Point line_inter(Point p1, Point p2, Point q1, Point q2)
{
	double u = xmul(p1, p2, q1);
	double v = xmul(p2, p1, q2);
	double ret_x = (q1.x * v + q2.x * u) / (v + u);
	double ret_y = (q1.y * v + q2.y * u) / (v + u);
	return {ret_x, ret_y};
}

vector <Point> circle_inter(Point c1, double r1, Point c2, double r2)
{
	vector <Point> ret;
	double x = (c1 - c2).length2();
	double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
	double d = r1 * r1 / x - y * y;
	if(sgn(d) == -1)
		return ret;
	d = max(d, (double)0);
	Point p1 = c1 + (c2 - c1) * y;
	Point p2 = ((c2 - c1) * sqrt(d)).rotate(Pi / 2);
	ret.push_back(p1 - p2);
	ret.push_back(p1 + p2);
	return ret;
}

vector <Point> circle_line_inter(Point c, double r, Point p, Point q)
{
	vector <Point> ret;
	double x = (p - c).dot(q - p);
	double y = (q - p).length2();
	double d = x * x - y * ((p - c).length2() - r * r);
	if(sgn(d) == -1)
		return ret;
	d = max(d, (double)0);
	Point p1 = p - ((q - p) * (x / y));
	Point p2 = (q - p) * (sqrt(d) / y);
	ret.push_back(p1 - p2);
	ret.push_back(p1 + p2);
	return ret;
}

pair <Point, double> solve(Point o1, Point o2, double k)
{
	if(sgn(k, 1) < 0)
		return solve(o2, o1, 1 / k);
	Point p1 = o1 + (o2 - o1) / (1 + k) * k;
	Point p2 = o1 + (o2 - o1) / (k - 1) * k;
	Point p = (p1 + p2) / 2;
	double r = (p - p1).length();
	return {p, r};
}

int main()
{
	ios :: sync_with_stdio(false);
	Point c1, c2, c3;
	double r1, r2, r3;
	cin >> c1.x >> c1.y >> r1;
	cin >> c2.x >> c2.y >> r2;
	cin >> c3.x >> c3.y >> r3;
	if(sgn(r1, r2) != 0)
	{
		swap(c1, c3);
		swap(r1, r3);
	}
	if(sgn(r1, r3) == 0)
	{
		swap(c2, c3);
		swap(r2, r3);
	}
	cout << fixed << setprecision(5);
	if(sgn(r1, r2) == 0 && sgn(r1, r3) == 0)
	{
		Point p1 = (c1 + c2) / 2;
		Point p2 = p1 + (c1 - c2).rotate(Pi / 2);
		Point q1 = (c1 + c3) / 2;
		Point q2 = q1 + (c1 - c3).rotate(Pi / 2);
		if(sgn((p1 - p2).cross(q1 - q2)) != 0)
		{
			Point inter = line_inter(p1, p2, q1, q2);
			cout << inter.x << ' ' << inter.y << '\n';
		}
	}
	else if(sgn(r1, r2) == 0 && sgn(r1, r3) != 0)
	{
		pair <Point, double> c13 = solve(c1, c3, r1 / r3);
		//cout << c13.first.x << ' ' << c13.first.y << ' ' << c13.second << '\n';
		Point p1 = (c1 + c2) / 2;
		Point p2 = p1 + (c1 - c2).rotate(Pi / 2);
		vector <Point> v = circle_line_inter(c13.first, c13.second, p1, p2);
		if(v.size())
		{
			if(v.size() == 2 && (v[0] - c1).length() > (v[1] - c1).length())
				swap(v[0], v[1]);
			cout << v[0].x << ' ' << v[0].y << '\n';
		}
	}
	else
	{
		pair <Point, double> c12 = solve(c1, c2, r1 / r2);
		pair <Point, double> c13 = solve(c1, c3, r1 / r3);
		vector <Point> v = circle_inter(c12.first, c12.second, c13.first, c13.second);
		if(v.size())
		{
			if(v.size() == 2 && (v[0] - c1).length() > (v[1] - c1).length())
				swap(v[0], v[1]);
			cout << v[0].x << ' ' << v[0].y << '\n';
		}
	}
	return 0;
}