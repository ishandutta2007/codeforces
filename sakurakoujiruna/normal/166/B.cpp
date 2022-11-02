#include <iostream>
using namespace std;

const int N = 100011;
typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	intl cross(Point p) {
		return x * p.y - y * p.x;
	}
}p[N];

intl xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	int m;
	cin >> m;

	bool flag = true;
	while(m --)
	{
		Point q;
		cin >> q.x >> q.y;
		int left = 1, right = n - 1;
		while(left + 1 < right)
		{
			int mid = (left + right) / 2;
			if(xmul(p[0], q, p[mid]) < 0)
				right = mid;
			else
				left = mid;
		}
		if(xmul(q, p[left], p[left + 1]) >= 0)
			flag = false;
		if(xmul(p[0], p[1], q) >= 0)
			flag = false;
		if(xmul(p[0], p[n - 1], q) <= 0)
			flag = false;
	}
	cout << (flag ? "YES" : "NO") << '\n';
	return 0;
}