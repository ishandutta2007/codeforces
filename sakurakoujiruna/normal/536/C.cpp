#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 200011;
typedef long long intl;

struct Point
{
	int x, y;
	Point() { }
	Point(int x, int y) : x(x), y(y) { }
	Point operator -(const Point &rhs) const
	{
		return Point(x - rhs.x, y - rhs.y);
	}
	bool operator <(const Point &rhs) const
	{
		return x > rhs.x || (x == rhs.x && y < rhs.y);
	}
	bool operator ==(const Point &rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
	int cross(const Point &rhs) const
	{
		return x * rhs.y - y * rhs.x;
	}
}p[N], old[N];

Point s[N];

intl gcd(intl a, intl b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

intl cross(Point a, Point b, Point c)
{
	/*
	intl nxa = b.x - a.x;
	intl dxa = a.x * b.x;

	//cout << nxa << '/' << dxa << '\n';

	intl nya = b.y - a.y;
	intl dya = a.y * b.y;

	intl nxb = d.x - c.x;
	intl dxb = c.x * d.x;

	intl nyb = d.y - c.y;
	intl dyb = c.y * d.y;

	intl nl = nxa * nyb;
	intl dl = dxa * dyb;
	
	intl gl = gcd(nl, dl);
	nl /= gl;
	dl /= gl;
	if(dl < 0)
	{
		nl = -nl;
		dl = -dl;
	}

	intl nr = nxb * nya;
	intl dr = dxb * dya;
	if(dr < 0)
	{
		nr = -nr;
		dr = -dr;
	}

	//cout << (int)nl << '/' << (int)dl << '\n';
	//cout << (int)nr << '/' << (int)dr << '\n';

	intl g = gcd(dl, dr);
	intl n = nl * (dr / g) - nr * (dl / g);
	//cout << (intl)n << '\n';
	if(n > 0)
		return 1;
	if(n < 0)
		return -1;
	return 0;
	*/
	return (intl)(a.x - b.x) * (b.y - c.y) * c.x * a.y
		- (intl)(b.x - c.x) * (a.y - b.y) * a.x * c.y;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> p[i].x >> p[i].y;
		old[i].x = p[i].x;
		old[i].y = p[i].y;
	}
	sort(p, p + n);
	int top = 0;
	for(int i = 0; i < n; i ++)
	{
		if(i != 0 && p[i] == p[i - 1])
			continue;
		if(top > 0 && p[i].y <= s[top - 1].y)
			continue;
		/*
		if(i == 2)
			cout << (p[i] - s[top - 1]).cross(s[top - 1] - s[top - 2]) << '\n';
		*/	
		/*
		if(i == 2)
		{
			cout << cross(p[i], s[top - 1], s[top - 1], s[top - 2]) << '\n';
			cout << p[i].x << ' ' << p[i].y << ' ' << s[top - 1].x << ' ' << s[top - 1].y << '\n';
		}
		*/
		while((top >= 1 && p[i].x == s[top - 1].x && p[i].y > s[top - 1].y) ||
			(top >= 2 && cross(s[top - 2], s[top - 1], p[i]) < 0))
			top --;
		s[top ++] = p[i];
		//cout << i << ' ' << top << '\n';
	}
	set <Point> st;
	for(int i = 0; i < top; i ++)
		st.insert(s[i]);
	for(int i = 0; i < n; i ++)
		if(st.find(old[i]) != st.end())
			cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}