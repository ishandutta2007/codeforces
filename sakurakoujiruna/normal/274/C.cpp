#include <bits/stdc++.h>
using namespace std;

#define double long double
const int N = 111;
const double Eps = 1e-6;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}
const double Pi = 4 * atan(1);

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	Point operator /(double d) {
		return {x / d, y / d};
	}
	bool operator <(Point p) const {
		if(sgn(x, p.x) == 0)
			return sgn(y, p.y) < 0;
		return sgn(x, p.x) < 0;
	}
	Point rot(double d) {
		double rx = x * cos(d) - y * sin(d);
		double ry = x * sin(d) + y * cos(d);
		return {rx, ry};
	}
	double len2() {
		return x * x + y * y;
	}
	double len() {
		return sqrt(len2());
	}
	double dot(Point p) {
		return x * p.x + y * p.y;
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
}p[N];
double xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

Point inter(Point p1, Point p2, Point q1, Point q2)
{
	double u = xmul(p1, p2, q1);
	double v = xmul(p2, p1, q2);
	double rx = (q1.x * v + q2.x * u) / (v + u);
	double ry = (q1.y * v + q2.y * u) / (v + u);
	return {rx, ry};
}

class Cmp
{
public:
	bool operator ()(double a, double b) const {
		return sgn(a, b) < 0;
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	set <Point> st;
	for(int i = 0; i < n; i ++)
	{
		cin >> p[i].x >> p[i].y;
		st.insert(p[i]);
	}

	bool found = false;
	double ans = 0;
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			for(int k = j + 1; k < n; k ++)
			{
				if(sgn((p[j] - p[i]).dot(p[k] - p[i])) > 0 &&
					sgn((p[k] - p[j]).dot(p[i] - p[j])) > 0 &&
					sgn((p[i] - p[k]).dot(p[j] - p[k])) > 0)
				{
					Point mij = (p[i] + p[j]) / 2;
					Point dij = (p[i] - p[j]).rot(Pi / 2);
					Point mjk = (p[j] + p[k]) / 2;
					Point djk = (p[j] - p[k]).rot(Pi / 2);
					Point o = inter(mij, mij + dij, mjk, mjk + djk);
					bool flag = true;
					for(int r = 0; r < n; r ++)
						if(sgn((p[r] - o).len2(), (p[i] - o).len2()) < 0)
							flag = false;
					if(flag)
					{
						found = true;
						ans = max(ans, (p[i] - o).len());
					}
				}
			}

	/*
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			for(int k = j + 1; k < n; k ++)
				for(int r = k + 1; r < n; r ++)
				{
					map <double, int, Cmp> mp;
					mp[(p[i] - p[j]).len2()] ++;
					mp[(p[i] - p[k]).len2()] ++;
					mp[(p[i] - p[r]).len2()] ++;
					mp[(p[j] - p[k]).len2()] ++;
					mp[(p[j] - p[r]).len2()] ++;
					mp[(p[k] - p[r]).len2()] ++;
					if(mp.size() == 2 && mp.begin() -> second == 4)
					{
						Point o = (p[i] + p[j] + p[k] + p[r]) / 4;
						bool flag = true;
						for(int s = 0; s < n; s ++)
							if(sgn((p[s] - o).len2(), (p[i] - o).len2()) < 0)
								flag = false;
						if(flag)
						{
							found = true;
							ans = max(ans, (p[i] - o).len());
						}
					}
				}
				*/

	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
		{
			Point mij = (p[i] + p[j]) / 2;
			Point dij = (p[j] - p[i]) / 2;
			Point pk = mij + dij.rot(Pi / 2);
			Point ps = mij - dij.rot(Pi / 2);
			if(st.find(pk) != st.end() &&
				st.find(ps) != st.end())
			{
				Point &o = mij;
				bool flag = true;
				for(int s = 0; s < n; s ++)
					if(sgn((p[s] - o).len2(), (p[i] - o).len2()) < 0)
						flag = false;
				if(flag)
				{
					found = true;
					ans = max(ans, (p[i] - o).len());
				}
			}
		}

	if(!found)
		cout << -1 << '\n';
	else
		cout << setprecision(6) << ans << '\n';
	return 0;
}