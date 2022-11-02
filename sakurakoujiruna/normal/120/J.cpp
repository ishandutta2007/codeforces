#include <iostream>
#include <tuple>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 400011;
typedef long long intl;
const intl Inf = ~0ULL>>1;

struct Point
{
	intl x, y;
	int id;
	Point operator -(Point p) {
		return {x - p.x, y - p.y, -1};
	}
	intl length2() {
		return x * x + y * y;
	}
}p[N];

bool by_x(Point a, Point b)
{
	return tie(a.x, a.y) < tie(b.x, b.y);
}
bool by_y(Point a, Point b)
{
	return a.y < b.y;
}

struct Ans
{
	intl len;
	int i, j;
};
Ans min(Ans a, Ans b)
{
	if(a.len < b.len)
		return a;
	return b;
}
Ans solve(int l, int r)
{
	if(l + 1 == r)
		return {Inf, -1, -1};
	int mid = (l + r) / 2;
	//sort(p + l, p + r, by_x);
	Ans ret = min(solve(l, mid), solve(mid, r));

	intl mx = p[mid].x;
	vector <Point> v;
	for(int i = l; i < r; i ++)
		if(Point{p[i].x - mx, 0, -1}.length2() < ret.len)
			v.push_back(p[i]);
	sort(v.begin(), v.end(), by_y);
	for(int i = 0; i < v.size(); i ++)
		for(int j = i + 1; j < v.size(); j ++)
		{
			if(Point{0, v[i].y - v[j].y, -1}.length2() > ret.len)
				break;
			if(v[i].id / 4 != v[j].id / 4)
				ret = min(ret, {(v[i] - v[j]).length2(), v[i].id, v[j].id});
		}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		p[4 * i] = {x, y, 4 * i};
		p[4 * i + 1] = {-x, y, 4 * i + 1};
		p[4 * i + 2] = {x, -y, 4 * i + 2};
		p[4 * i + 3] = {-x, -y, 4 * i + 3};
	}
	sort(p, p + 4 * n, by_x);
	Ans ans = solve(0, 4 * n);
	int a = ans.i;
	int b = ans.j;
	cout << a / 4 + 1 << ' ' << a % 4 + 1 << ' ';
	cout << b / 4 + 1 << ' ' << 4 - b % 4 << '\n';
	return 0;
}