#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <math.h>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct point {double x, y, z;};

point operator * (double x, point A)
{
	point B;
	B.x = A.x * x, B.y = A.y * x, B.z = A.z * x;
	return B;
}

point operator + (point A, point B)
{
	point C;
	C.x = A.x + B.x;
	C.y = A.y + B.y;
	C.z = A.z + B.z;
	return C;
}

inline double dist(point &a, point &b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

int ax, ay, az, vx, vy, vz, R;
double res = 1e20;
int n;
int iters = 80;

double solve(point A, point B, point v, double t0, double t1)
{
	double l = t0, r = t1;
	int t = 0;
	while (t < 2)
	{
		double k1 = (l + l + r) / 3.0, k2 = (l + r + r) / 3.0;
		double x = dist(A, B + k1 * v);
		double y = dist(A, B + k2 * v);
		if (x < y) r = k2; else l = k1;
		t ++;
	}
	return dist(A, B + l * v);
}

double solve(point A, point v1, double t0, double t1, point B, point v2, double p0, double p1, double R)
{
	double l = t0, r = t1;
	int t = 0;
	while (t < 200)
	{
		double k1 = (l + l + r) / 3.0, k2 = (l + r + r) / 3.0;
		double x = solve(A + k1 * v1, B, v2, p0, p1);
		double y = solve(A + k2 * v1, B, v2, p0, p1);
		if (x < y) r = k2; else l = k1;
		t ++;
	}
	double a = solve(A + l * v1, B, v2, p0, p1);
	if (sqrt(a) < R + 1e-9)
	{
		double l1 = t0, r1 = l;
		int t = 0;
		while (t < 100)
		{
			double key = (l1 + r1) / 2.0;
			double x = solve(A + key * v1, B, v2, p0, p1);
			if (sqrt(x) < R) r1 = key; else l1 = key;
			t ++;
		}
		return l1;
	}
	return 1e20;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d%d%d%d%d", &ax, &ay, &az, &vx, &vy, &vz, &R);
	point A;
	A.x = ax, A.y = ay, A.z = az;
	point v;
	v.x = vx, v.y = vy, v.z = vz;
	scanf("%d", &n);
	for (int t = 1; t <= n; t ++)
	{
		int ox, oy, oz, r, m;
		scanf("%d%d%d%d%d", &ox, &oy, &oz, &r, &m);
		point O;
		O.x = ox, O.y = oy, O.z = oz;
		res = min(res, solve(A, v, 0.0, 1e9, O, v, 0.0, 0.0, R + r));
		for (int i = 1; i <= m; i ++)
		{
			int px, py, pz;
			scanf("%d%d%d", &px, &py, &pz);
			point p;
			p.x = px, p.y = py, p.z = pz;
			res = min(res, solve(A, v, 0, 1e9, O, p, 0.0, 0.0, R));
			res = min(res, solve(A, v, 0, 1e9, O + p, p, 0.0, 0.0, R));
		}
	}

	if (res > 1e9 - 1e-9) printf("-1\n"); else printf("%.10lf\n", res);

	return 0;
}