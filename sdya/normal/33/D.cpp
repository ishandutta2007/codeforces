#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <map>
#include <set>

using namespace std;

int n, m, k;
long long kx[2000], ky[2000];
long long r[2000], cx[2000], cy[2000];
bitset < 1024 > d[2000], buf;

long long dist(long long x1, long long y1, long long x2, long long y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		kx[i] = a, ky[i] = b;
	}
	for (int i = 1; i <= m; i ++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		r[i] = a, cx[i] = b, cy[i] = c;
	}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (dist(kx[i], ky[i], cx[j], cy[j]) <= r[j] * r[j]) d[i][j] = 1;

	for (int i = 1; i <= k; i ++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		buf = d[a] ^ d[b];
		printf("%d\n", (int)(buf.count()));
	}
	return 0;
}