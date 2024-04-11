#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;
const int D = N << 1;
const int E = N * N;

int n;
int u[E], v[E], f[E], sz[E];
int h[E], nx[E];
int g[N];
char s[N][N][N];
int th[N], tnx[D], tto[D], et;
int dis[N];

void ae(int u, int v)
{
	et++;
	tto[et] = v;
	tnx[et] = th[u];
	th[u] = et;
}

void dfs(int u, int p = 0)
{
	dis[u] = dis[p] + 1;
	for (int i = th[u]; i; i = tnx[i])
		if (tto[i] != p)
			dfs(tto[i], u);
}

int getf(int u)
{
	return f[u] ? f[u] = getf(f[u]) : u;
}
int getg(int u)
{
	return g[u] ? g[u] = getg(g[u]) : u;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n * n; i++)
		u[i] = v[i] = f[i] = sz[i] = h[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int cur = (i - 1) * n + j;
			u[cur] = i;
			v[cur] = j;
			sz[cur] = 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n - i; j++)
		{
			scanf("%s", s[i][j] + 1);
			for (int k = 1; k <= n; k++)
				if (s[i][j][k] == '1')
				{
					int cu = (min(i, k) - 1) * n + max(i, k);
					int cv = (min(i + j, k) - 1) * n + max(i + j, k);
					cu = getf(cu), cv = getf(cv);
					if (cu == cv)
						continue;
					f[cu] = cv;
					sz[cv] += sz[cu];
				}
		}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int cur = (i - 1) * n + j;
			int p = getf(cur);
			nx[cur] = h[p];
			h[p] = cur;
		}
	for (int i = 1; i <= n * n; i++)
		if (!f[i] && sz[i] == n - 1)
		{
			for (int j = 1; j <= n; j++)
				g[j] = 0;
			int chk = 1;
			for (int j = h[i]; j; j = nx[j])
			{
				chk &= getg(u[j]) != getg(v[j]);
				if (!chk)
					break;
				g[getg(u[j])] = v[j];
			}
			if (!chk)
				continue;
			for (int j = 1; j <= n; j++)
				th[j] = 0;
			et = 0;
			for (int j = h[i]; j; j = nx[j])
			{
				ae(u[j], v[j]);
				ae(v[j], u[j]);
			}
			for (int j = 1; j <= n; j++)
			{
				dfs(j);
				for (int x = 1; x <= n; x++)
					for (int y = x + 1; y <= n; y++)
						chk &= (dis[x] == dis[y]) == (s[x][y - x][j] - '0');
				if (!chk)
					break;
			}
			if (chk)
			{
				printf("Yes\n");
				for (int j = h[i]; j; j = nx[j])
					printf("%d %d\n", u[j], v[j]);
				return;
			}
			//printf("No\n");
			//return;
		}
	printf("No\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}