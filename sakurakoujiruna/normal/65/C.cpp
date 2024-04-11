#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 10011;
const double Eps = 1e-8;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y, z;
	Point operator -(Point p) {
		return {x - p.x, y - p.y, z - p.z};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y, z + p.z};
	}
	Point operator *(double d) {
		return {x * d, y * d, z * d};
	}
	Point operator /(double d) {
		return {x / d, y / d, z / d};
	}
	double length2() {
		return x * x + y * y + z * z;
	}
	double length() {
		return sqrt(length2());
	}
}p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i <= n; i ++)
		cin >> p[i].x >> p[i].y >> p[i].z;
	double vp, vs;
	cin >> vp >> vs;
	Point o;
	cin >> o.x >> o.y >> o.z;

	double acc = 0;
	for(int i = 1; i <= n; i ++)
	{
		double t = (p[i] - p[i - 1]).length() / vs;
		double left = 0;
		double right = t;
		for(int _ = 0; _ < 50; _ ++)
		{
			double mid = (left + right) / 2;
			Point ps = p[i - 1] + (p[i] - p[i - 1]) * mid / t;
			if((ps - o).length() / vp < mid + acc)
				right = mid;
			else
				left = mid;
		}
		Point ps = p[i - 1] + (p[i] - p[i - 1]) * left / t;
		if(sgn((ps - o).length() / vp, left + acc) <= 0)
		{
			cout << "YES\n";
			cout << setprecision(8);
			cout << left + acc << '\n';
			cout << ps.x << ' ' << ps.y << ' ' << ps.z << '\n';
			return 0;
		}
		acc += t;
	}
	cout << "NO\n";
	return 0;
}