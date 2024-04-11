#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long intl;

const int N = 101111;
const double Eps = 1e-20;

int sgn(double a, double b = 0.0)
{
	a -= b;
	if(a > Eps)
		return 1;
	if(a < -Eps)
		return -1;
	return 0;
}

struct Point
{
	intl x, y;
	Point() { }
	Point(intl x, intl y) : x(x), y(y) { }
	intl cross(const Point &rhs) const
	{
		return x * rhs.y - y * rhs.x;
	}
	double length() const
	{
		return sqrt(x * x + y * y);
	}
}p[N];

pair <pair <double, double>, int> sp[N];
bool cmp(pair <pair <double, double>, int> lhs, pair <pair <double, double>, int> rhs)
{
	if(sgn(lhs.first.first, rhs.first.first) == 0)
		return sgn(lhs.first.second, rhs.first.second) < 0;
	return sgn(lhs.first.first, rhs.first.first) < 0;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[i].x >> p[i].y;
		if(i > 1)
		{
			p[i].x -= p[1].x;
			p[i].y -= p[1].y;
			sp[i].first.first = atan2(p[i].y, p[i].x);
			sp[i].first.second = (p[i]).length();
			sp[i].second = i;
		}
	}
	sort(sp + 2, sp + n + 1, cmp);
	/*
	int last = sp[2].second;
	for(int i = 2; i <= n; i ++)
		if(sgn(sp[i].first.first, sp[i + 1].first.first) != 0)
		{
			cout << 1 << ' ' << last << ' ' << sp[i + 1].second << '\n';
			return 0;
		}
	*/
	vector <int> vec;
	vec.push_back(sp[2].second);
	for(int i = 3; i <= n; i ++)
		if(sgn(sp[i].first.first, sp[i - 1].first.first) != 0)
			vec.push_back(sp[i].second);

	int m = vec.size();
	vec.push_back(vec[0]);
	for(int i = 0; i < m; i ++)
		if(p[vec[i]].cross(p[vec[i + 1]]) > 0)
		{
			cout << 1 << ' ' << vec[i] << ' ' << vec[i + 1] << '\n';
			return 0;
		}

	return 0;
}