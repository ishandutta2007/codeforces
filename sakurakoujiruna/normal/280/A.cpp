#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const double Eps = 1e-8;
const double Pi = 4 * atan(1);
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	Point rotate(const double &arg) const
	{
		double tx = x * cos(arg) - y * sin(arg);
		double ty = y * cos(arg) + x * sin(arg);
		return {tx, ty};
	}
};
double xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

namespace Hp_inter
{
	struct Seg
	{
	    Point s, e;
	    double ang;
	    Seg() { }
	    Seg(Point s, Point e) : s(s), e(e) {
	        ang = atan2(e.y - s.y, e.x - s.x);
	    }
	};

	Point inter(Seg s1, Seg s2)
	{
	    double u = xmul(s1.s, s1.e, s2.s);
	    double v = xmul(s1.e, s1.s, s2.e);
	    double tx = (s2.s.x * v + s2.e.x * u) / (u + v);
	    double ty = (s2.s.y * v + s2.e.y * u) / (u + v);
	    return {tx, ty};
	}

	bool cmp(Seg a, Seg b)
	{
	    if(sgn(a.ang - b.ang) == 0)
	        return sgn(xmul(a.s, a.e, b.s)) < 0;
	    return sgn(a.ang - b.ang) < 0;
	}

	bool parallel(Seg p, Seg q)
	{
	    return sgn((p.e - p.s).cross(q.e - q.s)) == 0;
	}

	const int N = 121;
	Seg q[N];
	Seg seg[N];

	Point hull[N];
	double hp_inter(int n)
	{
	    sort(seg, seg + n, cmp);
	    int tmp = 1;
	    for(int i = 1; i < n; i ++)
	    {
	        if(sgn(seg[i].ang - seg[tmp - 1].ang) != 0)
	                seg[tmp ++] = seg[i];
	    }
	    n = tmp;
	    q[0] = seg[0];
	    q[1] = seg[1];
	    int hd = 0, tl = 1;
	    for(int i = 2; i < n; i ++)
	    {
	        if(parallel(q[tl], q[tl - 1]) || parallel(q[hd], q[hd + 1]))
	            return 0;
	        while (hd < tl && xmul(seg[i].s, seg[i].e, inter(q[tl], q[tl - 1])) < -Eps)
	            -- tl;
	        while (hd < tl && xmul(seg[i].s, seg[i].e, inter(q[hd], q[hd + 1])) < -Eps)
	            ++ hd;
	        q[++ tl] = seg[i];
	    }
	    while(hd < tl && xmul(q[hd].s, q[hd].e, inter(q[tl], q[tl - 1])) < -Eps)
	        tl --;
	    while(hd < tl && xmul(q[tl].s, q[tl].e, inter(q[hd], q[hd + 1])) < -Eps)
	        hd ++;

	    int cnt = 0;
	    q[++ tl] = q[hd];
	    for(int i = hd; i < tl; i ++)
	        hull[cnt ++] = inter(q[i], q[i + 1]);

	    double ans = 0;
	    for(int i = 1; i < cnt - 1; i ++)
	        ans += fabs((hull[i] - hull[0]).cross(hull[i + 1] - hull[0]));
	    return ans / 2;
	}
}

int main()
{
	double w, h, a;
	cin >> w >> h >> a;
	a = a / 180 * Pi;
	Point p[5] = {
		{w / 2, h / 2},
		{-w / 2, h / 2},
		{-w / 2, -h / 2},
		{w / 2, -h / 2},
		{w / 2, h / w}
	};
	for(int i = 0; i < 4; i ++)
		Hp_inter :: seg[i] = Hp_inter :: Seg(p[i], p[i + 1]);
	for(int i = 0; i < 5; i ++)
		p[i] = p[i].rotate(a);
	for(int i = 0; i < 4; i ++)
		Hp_inter :: seg[i + 4] = Hp_inter :: Seg(p[i], p[i + 1]);
	cout << setprecision(8) << Hp_inter :: hp_inter(8) << '\n';
	return 0;
}