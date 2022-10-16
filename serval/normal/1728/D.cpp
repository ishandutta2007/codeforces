#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2005;

int n;
char s[N];
int f[N][N], g[N][N];

void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int x = 1; x <= n; x++)
		for (int l = 1, r = x; r <= n; l++, r++)
		{
			if (x == 1)
			{
				f[l][r] = 0;
				g[l][r] = l;
				continue;
			}
			if (f[l + 1][r] == -1 || f[l][r - 1] == -1)
			{
				f[l][r] = 1;
				continue;
			}
			if (f[l + 1][r] == 1 && f[l][r - 1] == 1)
			{
				f[l][r] = -1;
				continue;
			}
			if (x & 1)
			{
				f[l][r] = 0;
				if (f[l + 1][r] == 0)
					g[l][r] = l;
				if (f[l][r - 1] == 0)
					g[l][r] = r;
				if (f[l + 1][r] == 0 && f[l][r - 1] == 0)
					g[l][r] = s[l] < s[r] ? l : r;
				continue;
			}
			f[l][r] = -1;
			if (f[l + 1][r] == 0)
			{
				if (s[l] == s[g[l + 1][r]])
					f[l][r] = max(f[l][r], 0);
				else
					if (s[l] < s[g[l + 1][r]])
						f[l][r] = max(f[l][r], 1);
			}
			if (f[l][r - 1] == 0)
			{
				if (s[r] == s[g[l][r - 1]])
					f[l][r] = max(f[l][r], 0);
				else
					if (s[r] < s[g[l][r - 1]])
						f[l][r] = max(f[l][r], 1);
			}
		}
	if (f[1][n] == 0)
		printf("Draw\n");
	if (f[1][n] == 1)
		printf("Alice\n");
	if (f[1][n] == -1)
		printf("Bob\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}