#include <bits/stdc++.h>
using namespace std;

#define double long double
typedef long long intl;

const double Eps = 1e-18;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	bool operator ==(Point p) {
		return tie(x, y) == tie(p.x, p.y);
	}
	double arg() {
		return atan2(y, x);
	}
	intl len2() {
		return (intl)x * x + (intl)y * y;
	}
	intl cross(Point p) {
		return (intl)x * p.y - (intl)y * p.x;
	}
}p[3];
intl sxmul(Point a, Point b, Point c)
{
	intl t = (b - a).cross(c - a);
	return (t > 0) - (t < 0);
}

class Cmp
{
public:
	bool operator ()(double a, double b)
	{
		return sgn(a, b) < 0;
	}
};
map <double, Point, Cmp> conv;

bool check(Point t)
{
	double ta = (t - p[0]).arg();
	if(conv.find(ta) != conv.end())
		return (conv[ta] - p[0]).len2() >= (t - p[0]).len2();
	
	auto r = conv.upper_bound(ta);
	if(r == conv.end())
		r = conv.begin();
	auto l = (r == conv.begin()) ? prev(conv.end()) : prev(r);

	return sxmul(p[0], l -> second, r -> second) >= 0 &&
		sxmul(t, l -> second, r -> second) >= 0;
}

void add(Point t)
{
	double ta = (t - p[0]).arg();
	//cout << t.x << ' ' << t.y << ' ' << ta << '\n';
	while(conv.size() >= 2)
	{
		auto r = conv.upper_bound(ta);
		if(r == conv.end())
			r = conv.begin();
		auto l = (r == conv.begin()) ? prev(conv.end()) : prev(r);
		auto l2 = (l == conv.begin()) ? prev(conv.end()) : prev(l);
		
		if(sxmul(p[0], t, l -> second) >= 0 || sxmul(p[0], l -> second, l2 -> second) >= 0)
			break;

		if(sxmul(t, l -> second, l2 -> second) >= 0)
			conv.erase(l);
		else
			break;
	}
	/*
	for(auto &p : conv)
		cout << p.first << ' ' << p.second.x << ' ' << p.second.y << '\n';
	cout << '\n';
	*/
	while(conv.size() >= 2)
	{
		auto r = conv.upper_bound(ta);
		if(r == conv.end())
			r = conv.begin();
		auto r2 = next(r);
		if(r2 == conv.end())
			r2 = conv.begin();
		if(sxmul(p[0], t, r -> second) <= 0 || sxmul(p[0], r -> second, r2 -> second) <= 0)
			break;
		if(sxmul(t, r -> second, r2 -> second) <= 0)
			conv.erase(r);
		else
			break;
	}
	conv[ta] = t;
}

int main()
{
	ios :: sync_with_stdio(false);
	int q;
	cin >> q;
	q -= 3;

	for(int i = 0; i < 3; i ++)
		cin >> p[i].x >> p[i].x >> p[i].y;
	conv[(p[1] - p[0]).arg()] = p[1];
	conv[(p[2] - p[0]).arg()] = p[2];

	while(q --)
	{
		int type;
		cin >> type;
		Point t;
		cin >> t.x >> t.y;

		//cout << "------\n";
		if(t == p[0])
		{
			if(type == 2)
				cout << "YES\n";
			continue;
		}
		if(type == 2)
			cout << (check(t) ? "YES" : "NO") << '\n';
		else if(!check(t))
		{
			conv.erase((t - p[0]).arg());
			add(t);
		}
		/*
		for(auto &p : conv)
			cout << p.first << ' ' << p.second.x << ' ' << p.second.y << '\n';
		*/
	}
	return 0;
}