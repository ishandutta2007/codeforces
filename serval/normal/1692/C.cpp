#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 15;

char s[N][N];

void solve()
{
	for (int i = 1; i <= 8; i++)
		scanf("%s", s[i] + 1);
	for (int i = 2; i <= 7; i++)
		for (int j = 2; j <= 7; j++)
			if (s[i - 1][j - 1] == '#' &&
				s[i + 1][j - 1] == '#' &&
				s[i - 1][j + 1] == '#' &&
				s[i + 1][j + 1] == '#' &&
				s[i][j] == '#')
			{
				printf("%d %d\n", i, j);
				return;
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