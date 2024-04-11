#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); a++)

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

struct point{
	ll x, y;
	point operator - (point b)
	{
		point a = *this;
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}
};

point p[100001];
point s[100001];

bool _lessangle(point a, point b)
{
	ll x1 = a.x - p[0].x;
	ll x2 = b.x - p[0].x;
	ll y1 = a.y - p[0].y;
	ll y2 = b.y - p[0].y;
	ll q = x1 * y2;
	ll w = x2 * y1;
	if (q == w) return abs((int)x1) + abs((int)y1) > abs((int)x2) + abs((int)y2);
	return q > w;
}

bool wrongangle(point a, point b)
{
	if ((a.x == 0 && a.y == 0) ||(b.x == 0 && b.y == 0)) return true;
	//if (atan2((a.x * b.y - b.x * a.y), a.x * a.y + b.x * b.y) - eps > 0) return true;
	if (a.x * b.y - b.x * a.y < 0) return true;
	return false;
}

ll dist(point a, point b)
{
	int dx = abs((int)(a.x - b.x));
	int dy = abs((int)(a.y - b.y));
	return (ll)max(dx, dy);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, n)
		cin >> p[i].x >> p[i].y;

	if (n == 1)
	{
		cout << 4;
		return 0;

	}
	int mini = 0;
	FOR(i, n)
		if (p[i].y < p[mini].y || (p[i].y == p[mini].y && p[i].x < p[mini].x)) mini = i;
	swap(p[mini], p[0]);
	sort(p + 1, p + n, _lessangle);
	p[n] = p[0];

//	FOR(i, n)
//		cerr << p[i].x << ' '<< p[i].y << '\n';
	int m = 2;
	s[0] = p[0];
	s[1] = p[1];

	for(int i = 2; i <= n; i++)
	{
		s[m++] = p[i];
		while (m > 2 && wrongangle(s[m - 2] - s[m - 3], s[m - 1] - s[m - 2])) s[m - 2] = s[--m];
	}
	m--;

	//cerr << m << '\n';
//	FOR(i, m)
//		cerr << s[i].x << ' '<< s[i].y << '\n';

	int ans = 0;
	FOR(i, m)  {ans += dist(s[i], s[i + 1]);}//cerr << ans << ' ';}
	cout << ans + 4;

	return 0;
}