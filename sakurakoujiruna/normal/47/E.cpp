#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
const double Eps = 1e-8;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Cannon
{
	double a;
	int id;
	bool operator <(Cannon c) const {
		return sgn(a, c.a) < 0;
	}
}c[N];
double cx[N];
double ansx[N], ansy[N];

struct Wall
{
	double x, y;
	bool operator <(Wall w) const {
		if(sgn(x, w.x) == 0)
			return sgn(y, w.y) < 0;
		return sgn(x, w.x) < 0;
	}
}w[N];

double solve(double a, double x, double v)
{
	double t = x / (v * cos(a));
	return v * sin(a) * t - 4.9 * t * t;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, v;
	cin >> n >> v;
	for(int i = 0; i < n; i ++)
	{
		cin >> c[i].a;
		c[i].id = i;
	}
	sort(c, c + n);

	int m;
	cin >> m;
	for(int i = 0; i < m; i ++)
		cin >> w[i].x >> w[i].y;
	sort(w, w + m);

	int p = 0;
	for(int i = 0; i < n; i ++)
	{
		while(p < m && sgn(solve(c[i].a, w[p].x, v), w[p].y) > 0)
				p ++;
		if(p == m || sgn(solve(c[i].a, w[p].x, v)) < 0)
			cx[i] = v * v * sin(c[i].a * 2) / 9.8;
		else
			cx[i] = w[p].x;
	}

	cout << setprecision(6);
	for(int i = 0; i < n; i ++)
	{
		double x = cx[i];
		double t = x / (v * cos(c[i].a));
		double y = v * sin(c[i].a) * t - 4.9 * t * t;
		ansx[c[i].id] = x;
		ansy[c[i].id] = y;
	}
	for(int i = 0; i < n; i ++)
		cout << ansx[i] << ' ' << ansy[i] << '\n';
	return 0;
}