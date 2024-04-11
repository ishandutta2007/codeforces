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
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 6005;

struct Point
{
	double x, y;
	Point(double _x = 0, double _y = 0) { x = _x, y = _y; }
	Point operator + (const Point &b) const { return Point(x + b.x, y + b.y); }
	double operator * (const Point &b) const { return x * b.y - y * b.x; }
};

struct Line
{
	int a, b, c;
	bool operator < (const Line &d) const { return 1LL * a * d.b > 1LL * b * d.a; }
} l[MAXN];

Point Cross(Line x, Line y)
{
	return Point((double)(1LL * x.c * y.b - 1LL * x.b * y.c) / (1LL * x.a * y.b - 1LL * x.b * y.a), (double)(1LL * x.c * y.a - 1LL * x.a * y.c) / (1LL * x.b * y.a - 1LL * x.a * y.b));
}

int n;
double ans;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
	{
		l[i].a = Read(), l[i].b = Read(), l[i].c = Read();
		if (!l[i].b && l[i].a < 0)
			l[i].a = -l[i].a, l[i].c = -l[i].c;
		if (l[i].b && l[i].b < 0)
			l[i].a = -l[i].a, l[i].b = -l[i].b, l[i].c = -l[i].c;
	}
	sort(l + 1, l + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		Point cur(0, 0), tmp;
		for (int j = i % n + 1; j ^ i; j = j % n + 1)
			tmp = Cross(l[i], l[j]), ans += cur * tmp, cur = cur + tmp;
	}
	return printf("%lf\n", ans * 3 / n / (n - 1) / (n - 2)), 0;
}