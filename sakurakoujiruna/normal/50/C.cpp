#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long intl;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	intl cross(Point p) {
		return (intl)x * p.y - (intl)y * p.x;
	}
	int dis(Point p) {
		return max(abs(x - p.x), abs(y - p.y));
	}
};
intl xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

namespace Convex_hull
{
	bool cmp(Point p, Point q)
	{
		return tie(p.x, p.y) < tie(q.x, q.y);
	}
	vector <Point> convex(vector <Point> v)
	{
		vector <Point> r;
		sort(v.begin(), v.end(), cmp);
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
		return r;
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	vector <Point> p;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		p.push_back({x, y});
	}
	p = Convex_hull :: convex(p);

	intl ans = 4;
	for(int i = 0; i < p.size(); i ++)
		ans += p[i].dis(p[(i + 1) % p.size()]);
	cout << ans << '\n';
	return 0;
}