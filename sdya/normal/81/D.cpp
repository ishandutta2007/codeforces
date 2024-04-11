#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

int n, m, l, r;
pair < int, int > a[1100];

int b[1100];
bool good;

bool comp(pair < int, int > A, pair < int, int > B)
{
	return A.first > B.first;
}

void rec(int k)
{
	if (good) return ;
	if (k == r + 1)
	{
		bool gd = true;
		for (int i = l; i <= r; i ++)
			if (b[i - 1] == b[i] || b[i] == b[i + 1]) gd = false;
		if (b[1] == b[n]) gd = false;
		if (gd)
		{
			good = true;
			return ;
		}
		return ;
	}

	for (int i = 1; i <= m && !good; i ++)
		if (a[i].first != 0)
		{
			b[k] = a[i].second, a[i].first --;
			rec(k + 1);
			a[i].first ++;
		}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &a[i].first), a[i].second = i;

	sort(a + 1, a + m + 1, comp);
	int s = 0;
	for (int i = 1; i <= m; i ++)
		s += a[i].first;
	if (s < n)
	{
		printf("-1\n");
		return 0;
	}

	if (m == 1)
	{
		printf("-1\n");
		return 0;
	}
	if (n <= 4)
	{
		l = 1, r = n;
		rec(l);
		if (!good)
		{
			printf("-1\n");
			return 0;
		}
		for (int i = 1; i <= n; i ++)
			printf("%d ", b[i]);
		printf("\n");
		return 0;
	}
	b[1] = a[1].second;
	a[1].first --;
	for (int i = 2; i <= n - 4; i ++)
	{
		sort(a + 1, a + m + 1, comp);
		bool good = false;
		for (int j = 1; j <= m; j ++)
			if (a[j].first != 0 && a[j].second != b[i - 1])
			{
				b[i] = a[j].second, a[j].first --;
				good = true;
				break;
			}
		if (!good)
		{
			printf("-1\n");
			return 0;
		}
	}

	l = n - 3, r = n;

	rec(l);

	if (!good)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i ++)
		printf("%d ", b[i]);
	printf("\n");
	
	return 0;
}