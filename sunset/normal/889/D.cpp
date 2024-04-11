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

typedef long double ldb;

#define double ldb

const int MAXN = 2005;
const double eps = 1e-9;

struct Point
{
	double x, y;
	Point(double _x = 0, double _y = 0) { x = _x, y = _y; }
	Point operator + (const Point &b) const { return Point(x + b.x, y + b.y); }
	Point operator - (const Point &b) const	{ return Point(x - b.x, y - b.y); }
	Point operator * (const double &b) const { return Point(x * b, y * b); }
	bool operator == (const Point &b) const { return x == b.x && y == b.y; }
	double operator * (const Point &b) const { return x * b.y - y * b.x; }
	inline double Len() { return sqrt(x * x + y * y); }
} sum, p[MAXN];

vector <Point> ans;
bool b[MAXN];
int n;

inline Point Get(Point p)
{
	double l = p.Len();
	return Point(p.x / l, p.y / l);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		p[i].x = Read(), p[i].y = Read(), sum = sum + p[i];
	for (int i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
			if ((p[i] + p[j]) * n == sum * 2)
				b[i] = 1, b[j] = 1;
	sum.x /= n, sum.y /= n;
	int lst_n = n;
	n = 0;
	for (int i = 1; i <= lst_n; i ++)
		if (!b[i])
			p[++ n] = p[i];
	if (!n)
		return puts("-1"), 0;
	for (int i = 1; i <= n; i ++)
		p[i] = p[i] - sum;
	for (int i = 1; i <= n; i ++)
	{
		Point e = Get(p[1] + p[i]);
		vector <double> a, b;
		for (int j = 1; j <= n; j ++)
		{
			double v = p[j] * e;
			if (fabs(v) > eps)
				if (v > 0)
					a.pb(v);
				else
					b.pb(-v);
		}
		if (a.size() != b.size())
			continue;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		bool flg = true;
		for (int j = 0; j < a.size() && flg; j ++)
			if (fabs(a[j] - b[j]) > eps)
				flg = false;
		if (flg)
			ans.pb(e);
	}
	int ret = 0;
	for (int i = 0; i < ans.size(); i ++)
	{
		bool flg = true;
		for (int j = 0; j < i && flg; j ++)
			if (fabs((ans[i] + ans[j]).Len()) < eps || fabs((ans[i] - ans[j]).Len()) < eps)
				flg = false;
		if (flg)
			ret ++;
	}
	return printf("%d\n", ret), 0;
}