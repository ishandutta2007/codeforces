#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;
const intl Inf = (~0ULL >> 1);

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	intl length2() {
		return x * x + y * y;
	}
}p[N];
bool by_x(Point a, Point b)
{
	return a.x < b.x;
}
bool by_y(Point a, Point b)
{
	return a.y < b.y;
}

intl s[N];

intl solve(int l, int r)
{
	if(l + 1 == r)
		return Inf;
	int mid = (l + r) / 2;
	sort(p + l, p + r, by_x);
	intl ret = min(solve(l, mid), solve(mid, r));

	intl mx = p[mid].x;
	vector <Point> v;
	for(int i = l; i < r; i ++)
		if(Point{p[i].x - mx, 0}.length2() < ret)
			v.push_back(p[i]);
	sort(v.begin(), v.end(), by_y);
	for(int i = 0; i < v.size(); i ++)
		for(int j = i + 1; j < v.size(); j ++)
		{
			if(Point{0, v[i].y - v[j].y}.length2() > ret)
				break;
			ret = min(ret, (v[i] - v[j]).length2());
		}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
		p[i] = {i, s[i]};
	}
	cout << solve(1, n + 1) << '\n';
	return 0;
}