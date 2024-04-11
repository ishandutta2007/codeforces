#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

int n;
long long y;
int m, g[16][16];
int c[16], l[16], r[16], a[16], f[16];
long long d[1 << 16];

long long calc(int mask)
{
	if (d[mask] != -1) return d[mask];
	d[mask] = 0;
	if (mask == 0) return d[mask] = 1;

	int bits = 0;
	for (int i = 0; i < n; i ++)
		if (!(mask & (1 << i))) bits ++;

	bits = f[bits];

	for (int i = 0; i < n; i ++)
		if (r[i] > bits && bits > l[i] && (mask & (1 << i)) && (c[i] & mask) == c[i]) d[mask] += calc(mask - (1 << i));
	return d[mask];
}

long long get(int k)
{
	for (int i = 0; i < k; i ++)
		for (int j = 0; j < k; j ++)
			if (g[i][j] && a[i] <= a[j]) return 0;

	for (int i = 0; i < n; i ++)
		l[i] = -1, r[i] = n + 1;
	for (int i = 0; i < k; i ++)
		for (int j = k; j < n; j ++)
		{
			if (g[i][j]) r[j] = min(r[j], a[i]);
			if (g[j][i]) l[j] = max(l[j], a[i]);
		}
	for (int i = 0; i < k; i ++)
		f[i] = a[i];
	int cur = k;
	for (int i = 0; i < n; i ++)
	{
		bool good = true;
		for (int j = 0; j < k; j ++)
			if (i == a[j]) good = false;
		if (good) f[cur ++] = i;
	}

	for (int i = k; i < n; i ++)
	{
		c[i] = 0;
		for (int j = k; j < n; j ++)
			if (g[j][i]) c[i] += (1 << j);
	}

	memset(d, -1, sizeof(d));
	return calc((1 << n) - (1 << k));
}


void solve(long long y)
{
	long long res = get(0);
	if (res < y)
	{
		printf("The times have changed\n");
		return ;
	}

	int mask = (1 << n) - 1;
	int used[20];
	for (int i = 0; i < n; i ++) used[i] = 0;
	
	for (int i = 0; i < n; i ++)
	{
		long long cur = 0;
		for (int j = n - 1; j >= 0; j --)
			if (!used[j])
			{
				a[i] = j;
				long long add = get(i + 1);
				if (cur + add >= y)
				{
					printf("%d ", n - j);
					used[j] = true;
					y -= cur;
					break;
				} else cur += add;
			}
	}

	printf("\n");
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> y >> m;
	y -= 2000;
	for (int i = 0; i < m; i ++)
	{
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u][v] = 1;
	}

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (g[j][i])
				c[i] += (1 << j);

	solve(y);


	return 0;
}