#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

bool banc[21][360], bans[21][360];
bool vis[21][360];

int check(int r, int c)
{
	if (r > 20)
		return 1;
	if (vis[r][c])
		return 0;
	vis[r][c] = 1;
	if (r > 1 && !banc[r - 1][c])
		if (check(r - 1, c))
			return 1;
	if (!banc[r][c])
		if (check(r + 1, c))
			return 1;
	if (!bans[r][c])
		if (check(r, (c + 359) % 360))
			return 1;
	if (!bans[r][(c + 1) % 360])
		if (check(r, (c + 1) % 360))
			return 1;
	return 0;
}

void solve()
{
	int n;
	scanf("%d", &n);
	memset(banc, 0, sizeof(banc));
	memset(bans, 0, sizeof(bans));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		char c;
		int r1, r2, t1, t2;
		scanf("%c", &c);
		while (c != 'C' && c != 'S')
			scanf("%c", &c);
		if (c == 'C')
		{
			scanf("%d%d%d", &r1, &t1, &t2);
			for (int i = t1; i != t2; i = (i + 1) % 360)
				banc[r1][i] = 1;
		}
		else
		{
			scanf("%d%d%d", &r1, &r2, &t1);
			for (int i = r1 + 1; i <= r2; i++)
				bans[i][t1] = 1;
		}
	}
	if (check(1, 0))
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}