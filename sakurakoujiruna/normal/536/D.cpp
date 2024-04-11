#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2011;
typedef long long intl;
const intl Inf = 0x3f3f3f3f3f3f3f3fLL;

vector <pair <int, intl> > edges[N];

struct City
{
	intl ds, dt;
	intl p;
	int id;
	int rid;
	City() { }
}city[2][N];
bool by_ds(City lhs, City rhs)
{
	if(lhs.ds == rhs.ds)
		return lhs.id < rhs.id;
	return lhs.ds < rhs.ds;
}
bool by_dt(City lhs, City rhs)
{
	if(lhs.dt == rhs.dt)
		return lhs.id < rhs.id;
	return lhs.dt < rhs.dt;
}

intl f[N];
bool vis[N];
#define v first
#define w second
void spfa(int s)
{
	queue <int> que;
	memset(f, 0x3f, sizeof(f));
	memset(vis, 0, sizeof(vis));
	f[s] = 0;
	vis[s] = true;
	que.push(s);
	while(!que.empty())
	{
		int cur = que.front();
		que.pop();
		vis[cur] = false;
		for(auto &p : edges[cur])
			if(f[cur] + p.w < f[p.v])
			{
				f[p.v] = f[cur] + p.w;
				if(!vis[p.v])
				{
					vis[p.v] = true;
					que.push(p.v);
				}
			}
	}
}
#undef v
#undef w

intl dp[2][N][N];
intl suf[2][N][N];
int last[2][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	for(int i = 1; i <= n; i ++)
		cin >> city[0][i].p;
	for(int i = 0; i < m; i ++)
	{
		int u, v;
		intl w;
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(v, w));
		edges[v].push_back(make_pair(u, w));
	}

	spfa(s);
	for(int i = 1; i <= n; i ++)
		city[0][i].ds = f[i];
	spfa(t);
	for(int i = 1; i <= n; i ++)
	{
		city[0][i].dt = f[i];
		city[1][i] = city[0][i];
		city[0][i].id = city[1][i].id = i;
	}
	sort(city[0] + 1, city[0] + n + 1, by_dt);
	sort(city[1] + 1, city[1] + n + 1, by_ds);
	for(int i = 1; i <= n; i ++)
	{
		city[0][i].rid = i;
		city[1][i].rid = i;
	}
	sort(city[0] + 1, city[0] + n + 1, by_ds);
	sort(city[1] + 1, city[1] + n + 1, by_dt);
	/*
	for(int t = 0; t < 2; t ++)
	{
		for(int i = 1; i <= n; i ++)
			cout << city[t][i].ds << ' ' << city[t][i].dt << ' ' << city[t][i].p << ' ' << city[t][i].rid << '\n';
		cout << '\n';
	}
	*/
	for(int i = 0; i <= n; i ++)
		last[0][i] = last[1][i] = n;

	for(int i = n - 1; i >= 0; i --)
		for(int j = n - 1; j >= 0; j --)
		{
			suf[0][i][j] = suf[0][i][j + 1];
			suf[1][i][j] = suf[1][i + 1][j];
			
			dp[0][i][j] = -suf[1][i][j];
			dp[1][i][j] = -suf[0][i][j];

			if(city[0][i].rid > j)
				suf[1][i][j] -= city[0][i].p;
			if(city[1][j].rid > i)
				suf[0][i][j] -= city[1][j].p;

			if(city[0][i].rid > j)
			{
				for(int k = last[1][j]; k >= i; k --)
				{
					suf[1][k][j] = suf[1][k + 1][j];
					if(k == 0 || city[0][k].ds != city[0][k + 1].ds)
						suf[1][k][j] = min(suf[1][k][j], dp[1][k][j]);
					if(city[0][k].rid > j)
						suf[1][k][j] -= city[0][k].p;
				}
				last[1][j] = i;
			}
			if(city[1][j].rid > i)
			{
				for(int k = last[1][i]; k >= j; k --)
				{
					suf[0][i][k] = suf[0][i][k + 1];
					if(k == 0 || city[1][k].dt != city[1][k + 1].dt)
						suf[0][i][k] = min(suf[0][i][k], dp[0][i][k]);
					if(city[1][k].rid > i)
						suf[0][i][k] -= city[1][k].p;
				}
				last[1][i] = j;
			}
		}
	//cout << dp[0][0][0] << '\n';
	if(dp[0][0][0] == 0)
		cout << "Flowers\n";
	else if(dp[0][0][0] < 0)
		cout << "Cry\n";
	else
		cout << "Break a heart\n";
	return 0;
}