#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>


using namespace std;


struct point {
	double x, y;

	point() {
		x = 0;
		y = 0;
	}


	point(double x, double y) : x(x), y(y) {

	}

};


double a, b, c;
double mx1, my1, mx2, my2;
point A, B;
point A1, A2, B1, B2;
vector<double> res;


double dist(point p1, point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


int main() {
	cin >> a >> b >> c;
	cin >> mx1 >> my1 >> mx2 >> my2;
	A = point(mx1, my1);
	B = point(mx2, my2);
	A1 = point(-(b * my1 + c) / a, my1);
	B1 = point(-(b * my2 + c) / a, my2);
	A2 = point(mx1, -(a * mx1 + c) / b);
	B2 = point(mx2, -(a * mx2 + c) / b);
	res.push_back(abs(mx1 - mx2) + abs(my1 - my2));
	res.push_back(dist(A, A1) + dist(A1, B1) + dist(B1, B));
	res.push_back(dist(A, A1) + dist(A1, B2) + dist(B2, B));
	res.push_back(dist(A, A2) + dist(A2, B1) + dist(B1, B));
	res.push_back(dist(A, A2) + dist(A2, B2) + dist(B2, B));
	double m = 8e18;
	for (int i = 0; i < res.size(); ++i) {
		m = min(m, res[i]);
	}
	cout << fixed;
	cout << setprecision(18) << m << "\n";
	return 0;
}