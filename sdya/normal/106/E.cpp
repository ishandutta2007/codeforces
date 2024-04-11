#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct point {double x, y, z;};

double dist(point A, point B)
{
	double x = A.x - B.x;
	double y = A.y - B.y;
	double z = A.z - B.z;
	return x * x + y * y + z * z;
}

int n;
point p[110], res;

double get(point A)
{
	double res = 0.0;
	for (int i = 1; i <= n; i ++)
		res = max(res, dist(A, p[i]));
	return res;
}

pair < double, double > solve(double x, double y)
{
	double l = -10000.0, r = 10000.0;
	int t = 0;
	point p;
	p.x = x, p.y = y, p.z = 0;
	while (t < 60)
	{
		double p1 = (l + l + r) / 3.0, p2 = (l + r + r) / 3.0;
		double k1, k2;
		p.z = p1;
		k1 = get(p);
		p.z = p2;
		k2 = get(p);
		if (k1 > k2)
			l = p1; else r = p2;
		t ++;
	}
	return make_pair(get(p), l);
}

pair < double, double > solve(double x)
{
	double l = -10000.0, r = 10000.0;
	int t = 0;
	while (t < 60)
	{
		double p1 = (l + l + r) / 3.0, p2 = (l + r + r) / 3.0;
		pair < double, double > k1 = solve(x, p1), k2 = solve(x, p2);
		if (k1 > k2)
			l = p1; else r = p2;
		t ++;
	}
	return make_pair(solve(x, l).first, l);
}

double solve()
{
	double l = -10000.0, r = 10000.0;
	int t = 0;
	while (t < 60)
	{
		double p1 = (l + l + r) / 3.0, p2 = (l + r + r) / 3.0;
		pair < double, double > k1 = solve(p1), k2 = solve(p2);
		if (k1 > k2)
			l = p1; else r = p2;
		t ++;
	}
	return l;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);

	double x = solve();
	double y = solve(x).second;
	double z = solve(x, y).second;
	printf("%.10lf %.10lf %.10lf\n", x, y, z);


	return 0;
}