#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct point
{
	double x, y;
	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
};

struct triangle
{
	point A, B, C;
	void read()
	{
		A.read();
		B.read();
		C.read();
	}
};

struct line
{
	double A, B, C;
};

triangle t[110];
int n;

vector < pair < double, double > > s;

point intersect(line l1, line l2)
{
	double d = l1.A * l2.B - l1.B * l2.A;
	double dx = -l1.C * l2.B + l1.B * l2.C;
	double dy = -l1.A * l2.C + l1.C * l2.A;

	if (fabs(d) < 1e-9) 
	{
		point ans;
		ans.x = -1;
		ans.y = -1;
		return ans;
	}
	point ans;
	ans.x = dx / d;
	ans.y = dy / d;
	return ans;
}

line build(point A, point B)
{
	line l;
	l.A = A.y - B.y, l.B = B.x - A.x, l.C = A.x * B.y - A.y * B.x;
	return l;
}

double dist(point A, point B)
{
	double dx = A.x - B.x, dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}

bool in(point A, point B, point C)
{
	double a = dist(A, B), b = dist(A, C), c = dist(B, C);
	if (fabs(a - b - c) < 1e-9) return true;
	return false;
}

point intersect(point A, point B, point C, point D)
{
	line l1, l2;
	l1 = build(A, B);
	l2 = build(C, D);
	point ans = intersect(l1, l2);
	if (ans.x < -0.5) return ans;
	if (in(A, B, ans) && in(C, D, ans)) return ans;
	ans.x = -1;
	ans.y = -1;
	return ans;
}

double plos(point A, point B, point C)
{
	double x = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
	return fabs(x / 2.0);
}

bool in(point A, triangle T)
{
	double s = plos(T.A, T.B, T.C);
	double s1 = plos(A, T.B, T.C);
	double s2 = plos(T.A, A, T.C);
	double s3 = plos(T.A, T.B, A);
	if (fabs(s - s1 - s2 - s3) < 1e-9) return true;
	return false;
}

void add(point A, point B, triangle T)
{
	if (in(A, T) && in(B, T)) 
	{
		s.push_back(make_pair(0.0, 1.0));
		return ;
	}

	point P1 = intersect(A, B, T.A, T.B);
	point P2 = intersect(A, B, T.A, T.C);
	point P3 = intersect(A, B, T.B, T.C);

	vector < point > P;

	int good = 0;
	if (P1.x > -0.5) P.push_back(P1);
	if (P2.x > -0.5) P.push_back(P2);
	if (P3.x > -0.5) P.push_back(P3);
	if (P.size() == 0) return ;
	if (P.size() >= 2)
	{
		double mn = 1.0, mx = 0.0;
		for (int i = 0; i < P.size(); i ++)
			mn = min(dist(A, P[i]) / dist(A, B), mn),
			mx = max(dist(A, P[i]) / dist(A, B), mx);
		s.push_back(make_pair(mn, mx));
		return ;
	}
	double x = dist(A, P[0]) / dist(A, B);
	if (in(A, T))
		s.push_back(make_pair(0.0, x)); else
		s.push_back(make_pair(x, 1.0));
}

double solve(point A, point B, int k)
{
	s.clear();
	for (int i = 1; i <= n; i ++)
		if (i != k)
			add(A, B, t[i]);
	sort(s.begin(), s.end());
	double d = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	if (s.size() == 0) return d;
	double l = s[0].first, r = s[0].second;
	double res = r - l;

	for (int i = 1; i < s.size(); i ++)
		if (s[i].first > r) res += s[i].second - s[i].first, l = s[i].first, r = s[i].second; else
		{
			if (s[i].second > r)
				res += s[i].second - r, r = s[i].second;
		}
	return (1.0 - res) * d;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		t[i].read();

	double res = 0.0;
	for (int i = 1; i <= n; i ++)
		res += solve(t[i].A, t[i].B, i) + solve(t[i].B, t[i].C, i) + solve(t[i].C, t[i].A, i);
	printf("%.10lf\n", res);
	return 0;
}