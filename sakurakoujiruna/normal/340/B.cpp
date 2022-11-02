#include <iostream>
#include <iomanip>
using namespace std;

const int N = 311;
const int Inf = 0x3f3f3f3f;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	int cross(Point p) {
		return x * p.y - y * p.x;
	}
}p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;

	int ans = 0;
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
		{
			int lmin = Inf;
			int lmax = 0;
			int rmin = Inf;
			int rmax = 0;
			for(int k = 0; k < n; k ++)
			{
				int area = (p[k] - p[i]).cross(p[k] - p[j]);
				if(area > 0)
				{
					lmin = min(lmin, area);
					lmax = max(lmax, area);
				}
				else if(area < 0)
				{
					rmin = min(rmin, -area);
					rmax = max(rmax, -area);
				}
			}

			if(lmax && rmax)
				ans = max(ans, lmax + rmax);
			else if(lmax)
				ans = max(ans, lmax - lmin);
			else
				ans = max(ans, rmax - rmin);
		}

	cout << setprecision(12) << ans / 2.0 << '\n';
	return 0;
}