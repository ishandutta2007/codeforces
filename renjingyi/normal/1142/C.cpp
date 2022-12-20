#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 1e5 + 5;
long long sqr(const long long &v)
{
	return v * v;
}
struct Point
{
	long long x, y;
	Point(const long long &x = 0, const long long &y = 0) : x(x), y(y) {}
	Point operator-(const Point &p)const	{return Point(x - p.x, y - p.y);}
	long long operator*(const Point &p)const	{return x * p.y - y * p.x;}
	friend istream &operator>>(istream &in, Point &p)
	{
		in >> p.x >> p.y;
		return in;
	}
}p[maxn], q[maxn];
bool cmp1(const Point &a, const Point &b)
{
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}
bool cmp2(const Point &a, const Point &b)
{
	return a.y == b.y ? a.x > b.x : a.y > b.y;
}
int ed = 0;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[i];
		p[i].y -= sqr(p[i].x);
	}
	sort(p + 1, p + n + 1, cmp1);
	for(int i = 1; i <= n; i ++)
	{
		while(ed >= 2 && (p[i] - q[ed - 1]) * (p[i] - q[ed - 2]) <= 0)
			ed --;
		q[ed ++] = p[i];
	}
	int ans = ed - 1;
	for(int i = 1; i < ed && q[i - 1].x >= q[i].x; i ++)
		ans --;
	ed = 0;
	sort(p + 1, p + n + 1, cmp2);
	for(int i = 1; i <= n; i ++)
	{
		while(ed >= 2 && (p[i] - q[ed - 1]) * (p[i] - q[ed - 2]) <= 0)
			ed --;
		q[ed ++] = p[i];
	}
	ans += ed - 1;
	for(int i = ed - 2; i >= 0 && q[i + 1].x <= q[i].x; i --)
		ans --;
	cout << ans << endl;
	
	return 0;
}