#include <iostream>
#include <vector>

using namespace std;

int n;
int a[110000];
int c[110000];

vector < int > f[110000];

vector < vector < int > > s;
int ans[110000];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), c[a[i]] ++, f[a[i]].push_back(i);
	for (int i = 2; i <= 100000; i ++)
		if (c[i] > c[i - 1])
		{
			printf("-1\n");
			return 0;
		}

	int res = 0;
	while (true)
	{
		int v = -1;
		for (int i = 1; i <= 100000; i ++)
			if (c[i] == 0) {v = i - 1; break;}
		if (v == 0) break;
		res ++;
		for (int i = 1; i <= v; i ++)
			ans[f[i].back()] = res, f[i].pop_back(), c[i] --;
	}

	printf("%d\n", res);
	for (int i = 1; i <= n; i ++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}