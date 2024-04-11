#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define maxn 1005

int n, m;
int a[maxn][maxn];
bool used[maxn][maxn];
int cnt[maxn], c;

bool ok(int x)
{
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; ++i)
	{
		c = 0;
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] >= x)
			{
				cnt[c++] = j;
			}
		}
		for (int pp = 0; pp < c - 1; ++pp)
		{
			for (int pk = pp + 1; pk < c; ++pk)
			{
				if (used[cnt[pp]][cnt[pk]])
				{
					return true;
				}
				used[cnt[pp]][cnt[pk]] = true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	int mm = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
			mm = max(mm, a[i][j]);
		}
	}
	int l = 0, r = mm + 1;
	while (l < r - 1)
	{
		int m = (l + r) / 2;
		if (ok(m))
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	printf("%d\n", l);
	return 0;
}