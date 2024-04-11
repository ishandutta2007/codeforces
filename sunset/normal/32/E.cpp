#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int r = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		r = r * 10 + c - '0';
	return r * f;
}

const double eps = 1e-9;

struct Point
{
	double x, y;
	Point(double _x = 0, double _y = 0) { x = _x, y = _y; }
	Point operator + (const Point &b) const { return Point(x + b.x, y + b.y); }
	Point operator - (const Point &b) const { return Point(x - b.x, y - b.y); }
	Point operator * (const double &b) const { return Point(x * b, y * b); }
	double operator * (const Point &b) const { return x * b.y - y * b.x; }
} yjq, hja, w1, w2, m1, m2;

struct Line
{
	Point p, v;
	Line(Point _p = Point(0, 0), Point _v = Point(0, 0)) { p = _p, v = _v; }
} w, m;

inline int Sgn(double x)
{
	return fabs(x) < eps ? 0 : x > 0 ? 1 : -1;
}

inline bool In(double x, double l, double r)
{
	if (l > r)
		swap(l, r);
	return Sgn(x - l) >= 0 && Sgn(x - r) <= 0;
}

inline bool Online(Point p, Line l)
{
	if (!In(p.x, l.p.x, l.p.x + l.v.x) || !In(p.y, l.p.y, l.p.y + l.v.y))
		return 0;
	return !Sgn(l.v * (p - l.p));
}

inline Point GetCross(Line l1, Line l2)
{
	return l1.p + l1.v * (((l2.p - l1.p) * l2.v) / (l1.v * l2.v));
}

inline int Cross(Line a, Line b)
{
	if (a.v.x < 0 || (a.v.x == 0 && a.v.y < 0))
	{
		Point tmp = a.p + a.v;
		a = Line(tmp, Point(-a.v.x, -a.v.y));
	}
	if (b.v.x < 0 || (b.v.x == 0 && b.v.y < 0))
	{
		Point tmp = b.p + b.v;
		b = Line(tmp, Point(-b.v.x, -b.v.y));
	}
	int d1 = __gcd((int)a.v.x, (int)a.v.y), d2 = __gcd((int)b.v.x, (int)b.v.y);
	if (a.v.x / d1 == b.v.x / d2 && a.v.y / d1 == b.v.y / d2)
	{
		if (!Online(a.p, b) && !Online(b.p, a))
			return 1;
		return 0;
	}
	else
	{
		Point tmp = GetCross(a, b);
		if (In(tmp.x, a.p.x, a.p.x + a.v.x))
			if (In(tmp.x, b.p.x, b.p.x + b.v.x))
				if (In(tmp.y, a.p.y, a.p.y + a.v.y))
					if (In(tmp.y, b.p.y, b.p.y + b.v.y))
						return -1;
		return 1;
	}
}

inline Point Trans(Point a, Line b)
{
	Line c = Line(a, Point(-b.v.y, b.v.x));
	Point d = GetCross(b, c);
	return d * 2 - a;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	hja.x = Read(), hja.y = Read(), yjq.x = Read(), yjq.y = Read();
	w1.x = Read(), w1.y = Read(), w2.x = Read(), w2.y = Read();
	m1.x = Read(), m1.y = Read(), m2.x = Read(), m2.y = Read();
	w.p = w1; w.v = w2 - w1;
	m.p = m1; m.v = m2 - m1;
	if (Cross(Line(hja, yjq - hja), m) == -1)
		return puts("NO"), 0;
	if (Cross(Line(hja, yjq - hja), w) == 1)
		return puts("YES"), 0;
	Point yjq2 = Trans(yjq, m), w12 = Trans(w1, m), w22 = Trans(w2, m);
	if (Cross(Line(hja, yjq2 - hja), m) != 1 && Cross(Line(hja, yjq2 - hja), w) == 1 && Cross(Line(hja, yjq2 - hja), Line(w12, w22 - w12)) == 1)
		return puts("YES"), 0;
	return puts("NO"), 0;
}