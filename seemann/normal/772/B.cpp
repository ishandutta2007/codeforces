#include <iostream>
#include <vector>
#include <cmath>

#define X first
#define Y second

using namespace std;
typedef pair<int, int> point;

double f(double x1, double y1, double x2, double y2) {
	//cout << x1 << ' ' << y1 << "   " << x2 << " " << y2 << '\n';
	return fabs(x1*y2 - x2*y1) / 2 / sqrt(x2*x2 + y2*y2);
}

int main() {
	int n;
	vector<point> x;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int _x, _y;
		cin >> _x >> _y;
		x.push_back({_x, _y});
	}
	x.push_back(x[0]);
	x.push_back(x[1]);
	
	double ans = 1e19;
	
	for(int i = 0; i < n; i++) {
		ans = min(ans, f(x[i+1].X - x[i].X, x[i+1].Y - x[i].Y, x[i+2].X - x[i].X, x[i+2].Y - x[i].Y));
	}
	
	cout.precision(20);
	cout << ans;
	
	return 0;
}