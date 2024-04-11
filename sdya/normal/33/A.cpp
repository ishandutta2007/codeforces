#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <map>
#include <set>

using namespace std;

int m, n, k;
int a[2000];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++)
		a[i] = 1000000000;

	for (int i = 1; i <= n; i ++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		a[p] = min(a[p], q);
	}

	int res = 0;
	for (int i = 1; i <= m; i ++)
		if (a[i] != 1000000000) res += a[i];
	res = min(res, k);
	printf("%d\n", res);
	return 0;
}