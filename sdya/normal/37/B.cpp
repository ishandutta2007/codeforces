#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int n, mx, rg;
int p[1100], d[1100];
int num[1100], used[1100];
int s[1100], mode[1100], g = 0;

bool comp(int a, int b)
{
	return d[a] > d[b];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> mx >> rg;
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &p[i], &d[i]), num[i] = i;

	sort(num + 1, num + n + 1, comp);
	int t = 0;
	int cur = mx;
	int uron = 0;
	while (t <= 10000)
	{
		for (int i = 1; i <= n; i ++)
		{
			int v = num[i];
			if (!used[v])
			{
				if (cur * 100 <= p[v] * mx)
				{
					g ++, s[g] = t, mode[g] = v;
					uron += d[v];
					used[v] = true;
					break;
				}
			}
		}
		cur -= uron;
		cur = min(mx, cur + rg);
		t ++;
		if (cur <= 0) break;
	}

	if (t == 10001)
		printf("NO\n"); else
	{
		printf("YES\n");
		printf("%d %d\n", t, g);
		for (int i = 1; i <= g; i ++)
			printf("%d %d\n", s[i], mode[i]);
	}

	return 0;
}