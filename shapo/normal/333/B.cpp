#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;;

#define maxk 1050

bool bad[maxk][maxk];
bool badr[maxk], badc[maxk];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	memset(bad, 0, sizeof(bad));
	for (int i = 0; i < m; ++i)
	{
		int cx, cy;
		scanf("%d%d", &cx, &cy);
		bad[cx][cy] = true;
		badr[cx] = badc[cy] = true;
	}
	int res = 0;
	for (int j = 2; j <= n - j + 1; ++j)
	{
		if (j != n - j + 1)
		{
			int cp = 0;
			if (!badr[j])
			{
				++cp;
			}
			if (!badr[n - j + 1])
			{
				++cp;
			}
			if (!badc[j])
			{
				++cp;
			}
			if (!badc[n - j + 1])
			{
				++cp;
			}
			res += cp;
		}
		else
		{
			if (!badr[j] || !badc[j])
			{
				++res;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}