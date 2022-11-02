#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 121;
struct Point
{
	double x, y;
	Point operator -(Point p) {
		return Point{x - p.x, y - p.y};
	}
	double length() {
		return sqrt(x * x + y * y);
	}
}p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	double ans = 0;
	for(int i = 1; i < n; i ++)
		ans += (p[i] - p[i - 1]).length();
	cout << setprecision(8) << ans / 50 * m << '\n';
	return 0;
}