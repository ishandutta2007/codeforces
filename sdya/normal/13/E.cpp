#include <iostream>

using namespace std;

int n, m;
int a[110000];

int type[210000], k;
int v[400][400], len[400];
int jumps[400][400], nt[400][400], pr[400][400];

#define SZ 330

void precalc()
{
	for (int i = 0; i < n; i ++)
	{
		if (i % SZ == 0) k ++;
		type[i] = k;
		len[k] ++;
		v[k][i % SZ] = i;
	}
	k ++;
	for (int i = n; i <= n + n; i ++)
		type[i] = k;

	for (int i = 0; i < k; i ++)
		for (int j = 0; j < len[i]; j ++)
		{
			int s = v[i][j];
			while (true)
			{
				if (type[s + a[s]] > i)
				{
					jumps[i][j] ++;
					nt[i][j] = s + a[s];
					pr[i][j] = s;
					break;
				} else
					s = s + a[s], jumps[i][j] ++;
			}
		}
}

pair < int, int > calc(int f)
{
	pair < int, int > res = make_pair(0, 0);
	int x = type[f], y = f % SZ;
	while (true)
	{
		int z = nt[x][y];
		if (type[z] == k)
		{
			res.first = pr[x][y];
			res.second += jumps[x][y];
			break;
		} else
			res.second += jumps[x][y], x = type[z], y = z % SZ;
	}
	return res;
}

void update(int p, int q)
{
	a[p] = q;
	int x = type[p], y = p % SZ;
	int s = v[x][y];
	jumps[x][y] = 0;
	while (true)
	{
		if (type[s + a[s]] > type[p])
		{
			jumps[x][y] ++;
			nt[x][y] = s + a[s];
			pr[x][y] = s;
			break;
		} else
			s = s + a[s], jumps[x][y] ++;
	}

	for (int i = p; i >= 0; i --)
		if (type[i] == type[p])
		{
			if (type[i + a[i]] > type[p]) continue;
			jumps[type[i]][i % SZ] = jumps[type[i + a[i]]][(i + a[i]) % SZ] + 1;
			nt[type[i]][i % SZ] = nt[type[i + a[i]]][(i + a[i]) % SZ];
			pr[type[i]][i % SZ] = pr[type[i + a[i]]][(i + a[i]) % SZ];
		} else break;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	precalc();
	for (int i = 0; i < m; i ++)
	{
		int mode;
		scanf("%d", &mode);
		if (mode == 0)
		{
			int p, q;
			scanf("%d%d", &p, &q);
			update(p - 1, q);
		} else
		{
			int p;
			scanf("%d", &p);
			pair < int, int > res = calc(p - 1);
			printf("%d %d\n", res.first + 1, res.second);
		}
	}
	return 0;
}