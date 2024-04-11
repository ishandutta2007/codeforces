#include <iostream>

using namespace std;

int a[60];
bool used[60][60];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n * (n - 1) / 2 - 1; i ++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a[u] ++;
		used[u][v] = used[v][u] = true;
	}

	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (!used[i][j])
			{
				a[i] ++;
				bool good = true;
				for (int k = 1; k <= n; k ++)
					for (int l = k + 1; l <= n; l ++)
						if (a[k] == a[l]) good = false;
				if (good)
					printf("%d %d\n", i, j); else
					printf("%d %d\n", j, i);
			}
	return 0;
}