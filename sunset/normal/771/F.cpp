#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;
typedef long double dec;

const int MAXN = 400020;
const dec pi = acos( -1 );
const dec eps = 1e-15;

struct Point
{
	double x, y, k;
	Point() {}
	Point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	Point operator + ( const Point &b )
	{
		return Point( x + b.x, y + b.y );
	}
	Point operator - ( const Point &b )
	{
		return Point( x - b.x, y - b.y );
	}
	Point operator * ( const double &b )
	{
		return Point( x * b, y * b );
	}
	double operator * ( const Point &b )
	{
		return x * b.y - y * b.x;
	}
	Point operator / ( const double &b )
	{
		return Point( x / b, y / b );
	}
	bool operator < ( const Point &b )
	{
		return k < b.k;
	}
} p[MAXN];
int T, n, m, cnt;
int zqq[2][2] = { { 1,4 } ,{ 2,3 } };
inline int sgn(dec x)
{
	return ( fabs( x ) < eps ) ? 0 : ( x > 0 ? 1 : -1 );
}
struct node
{
	dec x, y;
	int p;
	node() {}
	node(dec x, dec y) :x(x), y(y), p(zqq[x<0][y<0]) {}
	node operator+(node a) const
	{
		return node(x + a.x, y + a.y);
	}
	node operator-(node a) const
	{
		return node(x - a.x, y - a.y);
	}
	dec operator/(node a) const
	{
		return  x * a.y - a.x * y;
	}
	bool operator<(node& a) const
	{
		return (p == a.p) ? sgn(*this / a) > 0 : p < a.p;
	}
	bool operator==(node a) const
	{
		return x == a.x && y == a.y;
	}
	bool vecequal(node a) const
	{
		return sgn(*this / a) == 0 && sgn(x) == sgn(a.x) && sgn(y) == sgn(a.y);
	}
};
typedef node vec;
struct half_plane
{
	node a;
	vec b;
	half_plane() {}
	half_plane(node from, node to) :a(from), b(to - from) {}
	bool operator<(half_plane& x) const
	{
		return b.vecequal(x.b) ? (sgn(b / (x.a - a)) > 0) : b < x.b;
	}
	bool contain(node x) const
	{
		return sgn((x - a) / b) >= 0;
	}
};
node getsec(half_plane& a, half_plane& b)
{
	dec s1 = (b.a - a.a) / a.b;
	dec s2 = a.b / (b.a + b.b - a.a);
	dec k = s1 / (s1 + s2);
	return node(b.a.x + b.b.x*k, b.a.y + b.b.y*k);
}
half_plane tmp[MAXN * 2];
node tmp1[MAXN * 2];
half_plane workpool[MAXN * 2];
int plane_cnt;
half_plane queue[MAXN * 2];
int head, tail;
dec half_plane_cut(half_plane* src, int size)
{
	dec inf = 1e6, S = 0;
	for (int i = 1; i <= size; ++i) tmp[i] = src[i];
	tmp[++size] = half_plane(node(-inf, -inf), node(-inf, inf));
	tmp[++size] = half_plane(node(-inf, inf), node(inf, inf));
	tmp[++size] = half_plane(node(inf, inf), node(inf, -inf));
	tmp[++size] = half_plane(node(inf, -inf), node(-inf, -inf));
	sort(tmp + 1, tmp + 1 + size);
	plane_cnt = 0;
	workpool[++plane_cnt] = tmp[1];
	for (int i = 2; i <= size; ++i) if (!tmp[i].b.vecequal(tmp[i - 1].b)) workpool[++plane_cnt] = tmp[i];
	if (plane_cnt < 2) return 0;
	head = tail = 0;
	queue[tail++] = workpool[1], queue[tail++] = workpool[2];
	for (int i = 3; i <= plane_cnt; ++i)
	{
		while (tail - head > 1 && (!workpool[i].contain(getsec(queue[tail - 1], queue[tail - 2])))) --tail;
		while (tail - head > 1 && (!workpool[i].contain(getsec(queue[head], queue[head + 1])))) ++head;
		queue[tail++] = workpool[i];
	}
	while (tail - head > 1 && (!queue[head].contain(getsec(queue[tail - 1], queue[tail - 2])))) --tail;
	while (tail - head > 1 && (!queue[tail - 1].contain(getsec(queue[head], queue[head + 1])))) ++head;
	if (tail - head <= 2) return 0;
	int nd_ct = 0;
	for (int i = head; i < tail - 1; ++i)
		tmp1[++nd_ct] = getsec(queue[i], queue[i + 1]);
	node zero(0, 0);
	tmp1[++nd_ct] = getsec(queue[tail - 1], queue[head]);
	for (int i = 1; i < nd_ct; ++i)
		S += (tmp1[i] - zero) / (tmp1[i + 1] - zero);
	S += (tmp1[nd_ct] - zero) / (tmp1[1] - zero);
	return S / 2;
}

half_plane l[MAXN << 1];

inline void solve()
{
	scanf("%d", &n);
	m = 2 * n - 1;
	cnt = 0;
	for (int i = 0, x, y; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		p[i].x = x;
		p[i].y = y;
		if (i) p[i].k = atan2(p[i].y - p[0].y, p[i].x - p[0].x);
	}
	sort(p + 1, p + n);
	for (int i = 1; i < n; i++) p[i + n - 1] = p[i], p[i + n - 1].k += 2 * pi;
	for (int i = 1, j = 1; i < n; i++)
	{
		while (j + 1 < m && sgn(p[i].k + pi - p[j + 1].k) >= 0) j++;
		if (!sgn(p[i + 1].k - p[i].k) || ((i != j) && !sgn(p[j].k - p[i].k - pi)))
		{
			puts("0");
			return;
		}
		if (i ^ j)
		{
			l[++cnt] = half_plane(node(p[i + 1].x, p[i + 1].y),node(p[i].x, p[i].y));
			l[++cnt] = half_plane(node(p[j].x, p[j].y),node(p[i].x, p[i].y));
		}
	}
	dec S = half_plane_cut(l, cnt);
	printf("%.8Lf\n", S);
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}