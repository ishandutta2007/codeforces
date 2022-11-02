#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int d[200], a[200];
int kill[200];

int check(int n, int d, int x)
{
	return (bool)(x % d == 0 && x - d <= n);
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
		cin >> d[i];
	for (int i = 1; i <= k; i ++)
		cin >> a[i];

	for (int i = 1; i <= m; i ++)
		for (int j = 1; j <= k; j ++)
			kill[i] += check(n, d[i], a[j]);

	int best = 1000000000;
	for (int i = 1; i <= m; i ++)
		best = min(best, kill[i]);
	int res = 0;
	for (int i = 1; i <= m; i ++)
		if (kill[i] == best) res ++;
	printf("%d\n", res);
	for (int i = 1; i <= m; i ++)
		if (kill[i] == best)
			printf("%d ", i);
	printf("\n");
	return 0;
}