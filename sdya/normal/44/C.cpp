#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int a[1000];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
	{
		int p, q;
		cin >> p >> q;
		for (int j = p; j <= q; j ++)
			a[j] ++;
	}
	for (int i = 1; i <= n; i ++)
		if (a[i] != 1) 
		{
			printf("%d %d\n", i, a[i]);
			return 0;
		}
	printf("OK\n");
	return 0;
}