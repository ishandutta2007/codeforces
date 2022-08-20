#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 100005;

int n, m, Q, mx, hed[MAXN], p[MAXN], v[MAXN], w[MAXN], f[MAXN];
vector <int> d[MAXN];
LL dis[MAXN], INF;
bool vis[MAXN];

inline void Dijkstra()
{
	priority_queue <pair <LL, int>, vector <pair <LL, int>>, greater <pair <LL, int>>> q;
	mset(dis, 0x3f); INF = dis[0];
	dis[1] = 0; q.push(mp(0, 1));
	while (!q.empty())
	{
		int x = q.top().yy; q.pop();
		if (vis[x])
			continue;
		vis[x] = 1;
		for (int i = hed[x]; i; i = v[i])
			if (dis[p[i]] > dis[x] + w[i])
				dis[p[i]] = dis[x] + w[i], q.push(mp(dis[p[i]], p[i]));
	}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), Q = Read();
	for (int i = 1, x, y; i <= m; i ++)
		x = Read(), y = Read(), w[i] = Read(), p[i] = y, v[i] = hed[x], hed[x] = i;
	Dijkstra();
	while (Q --)
		if (Read() == 1)
		{
			int x = Read();
			if (dis[x] >= INF)
				puts("-1");
			else
				printf("%I64d\n", dis[x]);
		}
		else
		{
			for (int x = Read(); x; x --)
				w[Read()] ++;
			mset(f, 0x3f);
			mx = f[1] = 0; d[0].pb(1);
			for (int i = 0; i <= mx; i ++)
				for (int j = 0; j < d[i].size(); j ++)
				{
					int x = d[i][j];
					if (i > f[x])
						continue;
					for (int k = hed[x]; k; k = v[k])
						if (f[p[k]] > f[x] + dis[x] + w[k] - dis[p[k]])
						{
							f[p[k]] = f[x] + dis[x] + w[k] - dis[p[k]];
							if (f[p[k]] <= n)
								d[f[p[k]]].pb(p[k]), mx = max(mx, f[p[k]]);
						}
				}
			for (int i = 0; i <= mx; i ++)
				d[i].clear();
			for (int i = 1; i <= n; i ++)
				if (dis[i] < INF)
					dis[i] += f[i];
		}
	return 0;
}