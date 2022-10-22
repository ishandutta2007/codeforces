#include <bits/stdc++.h>

const int N = 505;

int n, k, pos, val, ans = 1;
bool com;

int main()
{
	int x, y;
	scanf("%d%d", &n, &k);
	printf("? ");
	for (int i = 1; i <= k; i++) printf("%d ", i);
	puts(""); fflush(stdout);
	scanf("%d%d", &pos, &val);
	printf("? ");
	for (int i = 1; i <= k; i++) if (i != pos) printf("%d ", i);
	printf("%d\n", k + 1); fflush(stdout);
	scanf("%d%d", &x, &y); com = y < val;
	for (int i = 1; i <= k; i++) if (i != pos)
	{
		printf("? ");
		for (int j = 1; j <= k; j++) if (j != i) printf("%d ", j);
		printf("%d\n", k + 1); fflush(stdout);
		scanf("%d%d", &x, &y);
		if ((x != pos) ^ com) ans++;
	}
	return printf("! %d\n", ans), 0;
}