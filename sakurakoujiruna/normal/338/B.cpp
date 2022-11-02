#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100011;
const int Inf = 0x3f3f3f3f;

bool use[N];
vector <int> edges[N];

pair <int, int> f[N][2];
#define val first
#define id second
void dfs1(int cur, int last = -1)
{
	f[cur][0] = f[cur][1] = {-1, -1};
	for(auto &v : edges[cur])
		if(v != last)
		{
			dfs1(v, cur);
			if(f[v][0].val != -1)
			{
				if(f[v][0].val + 1 > f[cur][0].val)
				{
					f[cur][1] = f[cur][0];
					f[cur][0].val = f[v][0].val + 1;
					f[cur][0].id = v;
				}
				else if(f[v][0].val + 1 > f[cur][1].val)
				{
					f[cur][1].val = f[v][0].val + 1;
					f[cur][1].id = v;
				}
			}
		}
	if(use[cur])
	{
		if(f[cur][0].val == -1)
			f[cur][0] = {0, cur};
		else if(f[cur][1].val == -1)
			f[cur][1] = {0, cur};
	}
}

int dp[N];
void dfs2(int cur, int up, int last = -1)
{
	//cout << cur << ' ' << up << '\n';
	dp[cur] = max(up, f[cur][0].val);
	for(auto &v : edges[cur])
		if(v != last)
		{
			int tup = up;
			if(v == f[cur][0].id)
				tup = max(tup, f[cur][1].val);
			else
				tup = max(tup, f[cur][0].val);
			if(tup != -1)
				dfs2(v, tup + 1, cur);
			else
				dfs2(v, -1, cur);
		}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, d;
	cin >> n >> m >> d;
	for(int i = 1; i <= m; i ++)
	{
		int x;
		cin >> x;
		use[x] = true;
	}
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs1(1);
	dfs2(1, -1);

	/*
	for(int i = 1; i <= n; i ++)
	{
		cout << i << ' ' << f[i][0].val << ' ' << f[i][0].id;
		cout << ' ' << f[i][1].val << ' ' << f[i][1].id << '\n';
	}
	*/
	/*
	for(int i = 1; i <= n; i ++)
		cout << i << ' ' << dp[i] << '\n';
	*/
	vector <int> ans;
	for(int i = 1; i <= n; i ++)
		if(dp[i] <= d)
			ans.push_back(i);
	cout << ans.size() << '\n';
	/*
	for(auto &x : ans)
		cout << x << ' ';
	cout << '\n';
	*/
	return 0;
}