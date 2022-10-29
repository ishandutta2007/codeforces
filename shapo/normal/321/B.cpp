#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 150

int n, m;
vector < int > atk, def;
int ciel[maxn];
char buf[maxn];
int maxHarm[maxn][maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int cur;
		scanf(" %s%d", buf, &cur);
		if (buf[0] == 'A')
		{
			atk.push_back(cur);
		}
		else
		{
			def.push_back(cur);
		}
	}
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", ciel + i);
	}
	sort(ciel, ciel + m);
	int pa = 0, pd = 0;
	int curHarm = 0;
	bool canAll = true;
	int res = 0;
	for (int i = 0; i < m && canAll; ++i)
	{
		if (pd != (int)def.size() && ciel[i] > def[pd])
		{
			++pd;
		}
		else
		{
			if (pa != (int)atk.size() && ciel[i] >= atk[pa])
			{
				curHarm += ciel[i] - atk[pa];
				++pa;
			}
			else
			{
				curHarm += ciel[i];
			}
		}
	}
	if (pa == (int)atk.size() && pd == (int)def.size())
	{
		res = curHarm;
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j <= (int)atk.size(); ++j)
		{
			if (j == 0)
			{
				maxHarm[i][j] = 0;
			}
			else
			{
				if (ciel[i - 1] >= atk[j - 1])
				{
					//fprintf(stderr, "ok %d %d\n", i, j);
					for (int k = j - 1; k >= 0; --k)
					{
						maxHarm[i][j] = max(maxHarm[i][j], maxHarm[i - 1][k] + ciel[i - 1] - atk[j - 1]);
					}
				}
			}
			//fprintf(stderr, "maxHarm[%d][%d] = %d\n", i, j, maxHarm[i][j]);
			res = max(res, maxHarm[i][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}