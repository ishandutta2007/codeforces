#include <cstdio>

using namespace std;

const int N = 1e5 + 5;
const int L = 30;

int n, m, q;
int f[L][N], g[L][N];
int u[N], v[N], w[N];

int getf(int k, int u)
{
	return f[k][u] ? f[k][u] = getf(k, f[k][u]) : u;
}

int solve(int u, int v)
{
	for (int i = 0; i < L; i++)
		if (getf(i, u) == getf(i, v))
			return 0;
	for (int i = 0; i < L; i++)
		if (g[i][getf(i, u)])
			return 1;
	return 2;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		for (int j = 0; j < L; j++)
			if (w[i] & (1 << j))
				if (getf(j, u[i]) != getf(j, v[i]))
					f[j][getf(j, u[i])] = v[i];
	}
	for (int i = 1; i <= m; i++)
		if (w[i] & 1 ^ 1)
			for (int j = 1; j < L; j++)
			{
				g[j][getf(j, u[i])] = 1;
				g[j][getf(j, v[i])] = 1;
			}
	scanf("%d", &q);
	while (q--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", solve(u, v));
	}
	return 0;
}