
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream> 
#include <fstream> 
#include <vector> 
#include <cmath> 
#include <string>
#include <algorithm>

using namespace std;

struct point
{
	long long x;
	long long y;
};

vector <point> p;
int n;
point pnt;

long double dlina(point p1, point p2)
{
	return sqrt((long double)((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)));
}
long double visotap2(point p1, point p2, point p3)
{
	long long dvas = (p2.x - p1.x) * (p2.y + p1.y) + (p3.x - p2.x) * (p3.y + p2.y) + (p1.x - p3.x) * (p3.y + p1.y);
	dvas = abs(dvas);
	return ((long double)(dvas) / dlina(p1, p3));
}

long long a, b;
int s1, s2, s3;
long double h[1010];

void main()
{
	cout << fixed;
	cout.precision(10);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		pnt.x = a;
		pnt.y = b;
		p.push_back(pnt);
	}
	long double ans = 1e18;
	for (int i = 1; i <= n; i++)
	{
		s1 = i - 1;
		s2 = i % n;
		s3 = (i + 1) % n;
		ans = min(ans, visotap2(p[s1], p[s2], p[s3]));
	}
	cout << ans / 2;
}