#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	int length2() {
		return x * x + y * y;
	}
};

struct Circle
{
	Point o;
	int r;
	bool inter(Circle c) {
		int dis2 = (o - c.o).length2();
		if((r - c.r) * (r - c.r) < dis2 &&
			dis2 < (r + c.r) * (r + c.r))
			return true;
		return false;
	}
};

bool check(Circle c, Circle p, Circle q)
{
	if(c.inter(p) || c.inter(q))
		return false;
	int dis1 = (c.o - p.o).length2();
	int dis2 = (c.o - q.o).length2();
	if((c.r - p.r) * (c.r - p.r) >= dis1 && c.r > p.r &&
		(c.r - q.r) * (c.r - q.r) >= dis2 && c.r < q.r)
		return false;
	if((c.r + p.r) * (c.r + p.r) <= dis1 &&
		(c.r - q.r) * (c.r - q.r) >= dis2 && c.r < q.r)
		return false;
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);
	int x1, y1, r1, R1;
	cin >> x1 >> y1 >> r1 >> R1;
	int x2, y2, r2, R2;
	cin >> x2 >> y2 >> r2 >> R2;
	Circle o1 = {{x1, y1}, r1};
	Circle o2 = {{x1, y1}, R1};
	Circle o3 = {{x2, y2}, r2};
	Circle o4 = {{x2, y2}, R2};

	int ans = check(o1, o3, o4) +
				check(o2, o3, o4) +
				check(o3, o1, o2) +
				check(o4, o1, o2);
	cout << ans << '\n';
	return 0;
}