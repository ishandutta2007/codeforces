#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 1005, INF = 0x3f3f3f3f, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int n, m, T, len, dis[N][N], qx[N * N], qy[N * N];
char s[N][N];
bool vis[N][N];

int main()
{
	int x, y; ll p;
	read(n); read(m); read(T);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++) if (i + j & 1)
			s[i][j] = s[i][j] == '0' ? '1' : '0';
	}
	memset(dis, INF, sizeof(dis));
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
		{
			bool is = 0;
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i], ty = y + dy[i];
				if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if (s[x][y] != s[tx][ty]) is = 1;
			}
			if (is) qx[++len] = x, qy[len] = y, dis[x][y] = 0, vis[x][y] = 1;
		}
	for (int i = 1; i <= len; i++)
	{
		int x = qx[i], y = qy[i];
		for (int j = 0; j < 4; j++)
		{
			int tx = x + dx[j], ty = y + dy[j];
			if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if (s[x][y] == s[tx][ty] && !vis[tx][ty])
			{
				dis[tx][ty] = dis[x][y] + 1; vis[tx][ty] = 1;
				qx[++len] = tx; qy[len] = ty;
			}
		}
	}
	while (T--)
	{
		read(x); read(y); read(p); int ans;
		if (dis[x][y] == INF || p <= dis[x][y]) ans = s[x][y] - '0';
		else ans = s[x][y] - '0' ^ (p - dis[x][y] & 1);
		if (x + y & 1) ans ^= 1;
		printf("%d\n", ans);
	}
	return 0;
}