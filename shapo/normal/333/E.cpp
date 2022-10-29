#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <bitset>

using namespace std;

bitset< 3001 > cur[3001];

struct ok
{
	int i, j, dst;
};

int n;
int cnt;
ok sm[3000 * 1501];
int x[3001], y[3001];

bool cmp(const ok &a, const ok &b)
{
	return (a.dst > b.dst);
}

int add(int xx, int yy)
{
	sm[cnt].i = xx;
	sm[cnt].j = yy;
	sm[cnt++].dst = (x[xx] - x[yy]) * (x[xx] - x[yy])
		+ (y[xx] - y[yy]) * (y[xx] - y[yy]);
	return 0;
}

bool link(int x, int y)
{
	cur[x].set(y, true);
	cur[y].set(x, true);
	return ((cur[x] & cur[y]).any());
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	cnt = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		cur[i].reset();
		for (int j = i + 1; j < n; ++j)
		{
			add(i, j);
		}
	}
	stable_sort(sm, sm + cnt, cmp);
	for (int i = 0; i < cnt; ++i)
	{
		if (link(sm[i].i, sm[i].j))
		{
			printf("%.15lf\n", sqrt(sm[i].dst) / 2.);
			return 0;
		}
	}
	return 0;
}