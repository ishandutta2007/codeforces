#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
const int MAXN = 500005;

struct event{
	int x;
	int type;
	int p;
};

bool operator < (event a, event b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.type < b.type;
}

event a[MAXN];
int ca = 0;

int d[101];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, m;
	cin >> n >> m;
	FOR(i, n)
	{
		int x, h, l, r;
		scanf("%d%d%d%d", &x, &h, &l, &r);
		event w;
		w.x = x - h;
		w.type = 0;
		w.p = 100 - l;
		a[ca++] = w;
		w.x = x;
		w.type = 1;
		a[ca++] = w;
		w.type = 3;
		w.p = 100 - r;
		a[ca++] = w;
		w.x = x + h;
		w.type = 4;
		a[ca++] = w;
	}
	FOR(i, m)
	{
		int b, z;
		scanf("%d%d", &b, &z);
		a[ca].x = b;
		a[ca].type = 2;
		a[ca++].p = z;
	}
	n = ca;
	sort(a, a + n);
	clr(d);
	double ans = 0;
	FOR(i, n)
	{
		if (a[i].type == 2)
		{
			double w = a[i].p;
			FOR(i, 101)
			{
				if (d[i] == 0)
					continue;
				w *= pow(((double)i) / 100, d[i]);
			}
			ans += w;
		}
		if (a[i]. type == 0 || a[i].type == 3)
		{
			d[a[i].p]++;
		}
		if (a[i]. type == 1 || a[i].type == 4)
		{
			d[a[i].p]--;
		}
	}
	printf("%.5lf", ans);
	return 0;
}