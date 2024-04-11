// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y)
	{
		this->x = x; this->y = y;
	}
	Point operator + (Point rhs)
	{
		return Point(x + rhs.x, y + rhs.y);
	} 
	Point operator - (Point rhs)
	{
		return Point(x - rhs.x, y - rhs.y);
	}
	i64 Dot(Point rhs)
	{
		return 1LL * x * rhs.x + 1LL * y * rhs.y; 
	}
	i64 Crs(Point rhs)
	{
		return 1LL * x * rhs.y - 1LL * y * rhs.x;
	}
};

bool operator < (Point lhs, Point rhs)
{
	return (lhs.x == rhs.x) ? (lhs.y < rhs.y) : (lhs.x < rhs.x);
}

const int MAXN = 100010;

int N;
Point p[MAXN];

#include<vector>
vector<Point> H[2];

#define bk(q) q.back()
#define nbk(q) q[q.size() - 2]

int pcx[2333333], pcy[2333333];
int *cx = pcx + 1233333, *cy = pcy + 1233333;
i64 cip;

double Stat(int* e, int Min, int Max)
{
	double ret = 0;
	double Count = 0, sumPlain = 0, sumSquare = 0;
	int i;
	fortodo(i, Min, Max)
		{
			ret += e[i] * (Count * i * i + sumSquare - 2.0 * i * sumPlain);
			Count += e[i];
			sumPlain += e[i] * 1.0 * i;
			sumSquare += e[i] * 1.0 * i * i;
		}
	return ret;
}

int main()
{
	scanf("%d", &N);
	int i;
	fortodo(i, 1, N)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			p[i] = Point(x, y);
		}
	sort(p + 1, p + N + 1);
	int ml = 1;
	while ((ml < N) && (p[ml + 1].x == p[1].x)) ml++;
	H[0].clear(); H[1].clear();
	H[0].push_back(p[1]);
	H[1].push_back(p[ml]);
	fortodo(i, ml + 1, N)
		{
			while ((H[0].size() > 1) && ((bk(H[0]) - nbk(H[0])).Crs(p[i] - bk(H[0])) <= 0)) H[0].pop_back();
			while ((H[1].size() > 1) && ((bk(H[1]) - nbk(H[1])).Crs(p[i] - bk(H[1])) >= 0)) H[1].pop_back();
			H[0].push_back(p[i]);
			H[1].push_back(p[i]);
		}	
	while ((H[0].size() > 1) && (bk(H[0]).x == nbk(H[0]).x)) H[0].pop_back();
	vector<Point>::iterator lit = H[0].begin(), rit = H[1].begin();
	int minX = p[1].x, maxX = p[N].x, minY = p[1].y, maxY = p[1].y;
	fortodo(i, 2, N)
		{
			minY = min(minY, p[i].y);
			maxY = max(maxY, p[i].y);
		}
	fortodo(i, minY, maxY) cy[i] = 0;
	cx[maxX] = H[1].back().y - H[0].back().y + 1;
	cy[H[1].back().y + 1]--;
	cy[H[0].back().y]++;
	fortodo(i, minX, maxX - 1)
		{
			if ((lit + 1)->x <= i) lit++;
			if ((rit + 1)->x <= i) rit++;
			int ly = ceil(double((lit + 1)->y - lit->y) / ((lit + 1)->x - lit->x) * (i - lit->x) + lit->y - 1e-9);
			int ry = floor(double((rit + 1)->y - rit->y) / ((rit + 1)->x - rit->x) * (i - rit->x) + rit->y + 1e-9);
			cx[i] = ry - ly + 1;
			cy[ry + 1]--;
			cy[ly]++;
		}
	fortodo(i, minY + 1, maxY) cy[i] += cy[i - 1];
	cip = 0;
	fortodo(i, minX, maxX) cip += cx[i];
	double ans = Stat(cx, minX, maxX) + Stat(cy, minY, maxY);
	ans /= cip;
	ans /= cip - 1;
	printf("%.10f\n", ans);
}