#include <iostream>
#include <cmath>
using namespace std;

#define double long double
const double Eps = 1e-15;
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return Point{x - p.x, y - p.y};
	}
	double length() {
		return sqrt(x * x + y * y);
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	double r;
	Point o1, o2;
	cin >> r >> o1.x >> o1.y >> o2.x >> o2.y;
	double dis = (o1 - o2).length();
	cout << (int)ceil(dis / r / 2 - Eps) << '\n';
	return 0;
}