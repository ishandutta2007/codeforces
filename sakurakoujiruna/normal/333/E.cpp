#include <bits/stdc++.h>
using namespace std;

const int N = 3011;
struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	bool operator <(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	int cross(Point p) {
		return x * p.y - y * p.x;
	}
	int len2() {
		return x * x + y * y;
	}
}p[N];

int xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

void convex(vector <Point> &v)
{
	vector <Point> r;
	//sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i ++) {
		while(r.size() > 1 && xmul(*++r.rbegin(), v[i], *r.rbegin()) >= 0)
			r.pop_back();
		r.push_back(v[i]);
	}
	int d = r.size();
	for(int i = (int)v.size() - 2; i >= 0; i --) {
		while(r.size() > d && xmul(*++r.rbegin(), v[i], *r.rbegin()) >= 0)
			r.pop_back();
		if(i != 0)
			r.push_back(v[i]);
	}
	v = r;
}

inline int max(int x, int y)
{
	return (((y-x)>>(32-1))&(x^y))^y;
}

int solve(vector <Point> &v)
{
	convex(v);
	int ret = 0;
	int n = v.size();
	int p = 0;
	for(int i = 0; i < n; i ++)
	{
		//int r = (i + 1) % n;
		while(p < 2 * n - 1 &&
			abs(xmul(v[(p + 1) % n], v[i], v[(i + 1) % n])) >=
			abs(xmul(v[p % n], v[i], v[(i + 1) % n])))
			p ++;
		ret = max(ret, (v[p % n] - v[i]).len2());
		ret = max(ret, (v[p % n] - v[(i + 1) % n]).len2());
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	sort(p, p + n);
	double l = 0, r = 3e4;
	for(int _ = 0; _ < 35; _ ++)
	{
		double m = (l + r) / 2;
		bool flag = false;
		for(int i = 0; i < n; i ++)
		{
			vector <Point> tmp;
			for(int j = 0; j < n; j ++)
				if((p[j] - p[i]).len2() > m * m)
					tmp.push_back(p[j]);
			if(solve(tmp) > m * m)
				flag = true;
		}
		if(flag)
			l = m;
		else
			r = m;
	}
	cout << setprecision(12) << l / 2 << '\n';
	return 0;
}