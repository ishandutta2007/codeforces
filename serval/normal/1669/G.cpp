#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 50 + 5;

int n, m;
char p[N][N];

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%c", &p[i][j]);
			while (p[i][j] != '.' && p[i][j] != '*' && p[i][j] != 'o')
				scanf("%c", &p[i][j]);
		}
	for (int k = 1; k <= n; k++)
		for (int i = n; i > 1; i--)
			for (int j = 1; j <= m; j++)
				if (p[i][j] == '.' && p[i - 1][j] == '*')
					swap(p[i][j], p[i - 1][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%c", p[i][j]);
		printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}