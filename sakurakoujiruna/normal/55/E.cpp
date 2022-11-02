#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
typedef long long intl;

int sgn(intl x)
{
	return (x > 0) - (x < 0);
}

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

bool in(Point p, Point t1, Point t2, Point t3)
{
	int s1 = sgn(xmul(p, t1, t2));
	int s2 = sgn(xmul(p, t2, t3));
	int s3 = sgn(xmul(p, t3, t1));
	return s1 == s2 && s1 == s3;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	reverse(p, p + n);
	copy(p, p + n, p + n);

	int kase;
	cin >> kase;
	while(kase --)
	{
		Point q;
		cin >> q.x >> q.y;

		bool flag = false;
		for(int i = 1; i < n - 1; i ++)
			if(in(q, p[0], p[i], p[i + 1]))
				flag = true;
		if(!flag)
		{
			cout << 0 << '\n';
			continue;
		}

		intl ans = (intl)n * (n - 1) * (n - 2) / 6;
		int t = 0;
		for(int i = 0; i < n; i ++)
		{
			if(t == i)
				t ++;
			while(sgn(xmul(p[i], p[t], q)) != sgn(xmul(p[i], q, p[t + 1])))
				t ++;
			if(t - i + 1 >= 3)
				ans -= (intl)(t - i) * (t - i - 1) / 2;
		}
		cout << ans << '\n';
	}
	return 0;
}