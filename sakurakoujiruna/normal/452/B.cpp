#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	bool operator <(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	bool operator ==(Point p) const {
		return tie(x, y) == tie(p.x, p.y);
	}
	double length() {
		return sqrt(x * x + y * y);
	}
}p[8];

int q[8];
Point his[4];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <Point> v = {
		{0, 0},
		{0, 1},
		{1, 0},
		{n, m},
		{n - 1, m},
		{n, m - 1},
		{n, 0},
		{0, m}
	};
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	int l = 0;
	for(auto &pp : v)
		if(0 <= pp.x && pp.x <= n &&
			0 <= pp.y && pp.y <= m)
			p[l ++] = pp;

	double ans = 0;
	iota(q, q + l, 0);
	do
	{
		double tmp = 0;
		for(int i = 1; i < 4; i ++)
			tmp += (p[q[i]] - p[q[i - 1]]).length();
		if(tmp > ans)
		{
			ans = tmp;
			for(int i = 0; i < 4; i ++)
				his[i] = p[q[i]];
		}
	}while(next_permutation(q, q + l));
	for(int i = 0; i < 4; i ++)
		cout << his[i].x << ' ' << his[i].y << '\n';
	return 0;
}