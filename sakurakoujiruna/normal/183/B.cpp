#include <bits/stdc++.h>
using namespace std;

const int N = 1000011;
const int M = 261;
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
}p[M];
intl xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

int ans[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
		cin >> p[i].x >> p[i].y;
	fill(ans + 1, ans + n + 1, 1);
	for(int i = 0; i < m; i ++)
		for(int j = i + 1; j < m; j ++)
		{
			int acc = 2;
			for(int k = 0; k < m; k ++)
				if(k != i && k != j && xmul(p[k], p[i], p[j]) == 0)
					acc ++;
			intl dx = p[i].x - p[j].x;
			intl dy = p[i].y - p[j].y;
			intl gcd = __gcd(dx, dy);
			dx /= gcd;
			dy /= gcd;
			if(dy != 0 && p[i].y % dy == 0)
			{
				intl x = p[i].x - p[i].y / dy * dx;
				if(x >= 1 && x <= n)
					ans[x] = max(ans[x], acc);
			}
		}
	cout << accumulate(ans + 1, ans + n + 1, 0LL) << '\n';
	return 0;
}