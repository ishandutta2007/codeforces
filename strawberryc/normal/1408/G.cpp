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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 1505, M = N << 1, EI = 998244353, jly = 1e9 + 9, INF = 0x3f3f3f3f;

int n, a[N][N], val[N][N], ha[N][N], hb[N][N], cnt[N][N], mx[N][N], mn[N][N],
f[M][N], Root, tot, sze[M], tmp[N], pa[N], pb[N];
bool son[M][M];
std::vector<int> con[N];

void dfs(int u)
{
	sze[u] = 0;
	for (int v = 1; v <= tot; v++)
		if (son[u][v])
		{
			dfs(v);
			memset(tmp, 0, sizeof(tmp));
			if (sze[u]) for (int i = 1; i <= sze[u]; i++)
				for (int j = 1; j <= sze[v]; j++)
					tmp[i + j] = (1ll * f[u][i] * f[v][j] + tmp[i + j]) % EI;
			else for (int i = 1; i <= sze[v]; i++) tmp[i] = f[v][i];
			sze[u] += sze[v];
			for (int i = 1; i <= sze[u]; i++) f[u][i] = tmp[i];
		}
	if (!sze[u]) sze[u]++;
	f[u][1] = (f[u][1] + 1) % EI;
}

int main()
{
	read(n); memset(mn, INF, sizeof(mn));
	pa[0] = pb[0] = 1;
	for (int i = 1; i <= n; i++)
		pa[i] = 2048ll * pa[i - 1] % EI, pb[i] = 2084ll * pb[i - 1] % jly;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) read(val[i][j]), a[i][j] = j;
		std::sort(a[i] + 1, a[i] + n + 1, [&](int x, int y)
			{return val[i][x] < val[i][y];});
		for (int j = 1; j <= n; j++)
			ha[i][j] = (ha[i][j - 1] + pa[a[i][j]]) % EI,
			hb[i][j] = (hb[i][j - 1] + pb[a[i][j]]) % jly;
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp = INF; val[i][0] = INF;
		for (int j = 1; j <= n; j++)
		{
			tmp = Min(tmp, a[i][j]);
			if (ha[tmp][j] == ha[i][j] && hb[tmp][j] == hb[i][j])
				cnt[tmp][j]++, mx[tmp][j] = Max(mx[tmp][j], val[i][a[i][j]]),
					mn[tmp][j] = Min(mn[tmp][j], val[i][a[i][j + 1]]);
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (cnt[i][j] == j && mx[i][j] < mn[i][j])
		{
			tot++; if (j == n) Root = tot; sze[tot] = j;
			for (int k = 1; k <= j; k++)
				con[a[i][k]].push_back(tot);
		}
	for (int i = 1; i <= n; i++)
	{
		std::sort(con[i].begin(), con[i].end(), [&](int x, int y)
			{return sze[x] < sze[y];});
		for (int j = 0; j + 1 < ((int) con[i].size()); j++)
			son[con[i][j + 1]][con[i][j]] = 1;
	}
	dfs(Root);
	for (int i = 1; i <= n; i++) printf("%d ", f[Root][i]);
	return puts(""), 0;
}