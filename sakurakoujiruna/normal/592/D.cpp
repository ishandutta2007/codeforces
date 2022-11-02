#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 131111;

vector <int> edges[N];
bool human[N];

bool dfs1(int cur, int last, bool has_human, int &sum_edges)
{
	bool ret = false;
	if(human[cur])
	{
		ret = true;
		has_human = true;
	}
	for(auto v: edges[cur])
	{
		if(v != last)
		{
			bool tmp = dfs1(v, cur, has_human, sum_edges);
			if(tmp && has_human)
				sum_edges ++;
			ret |= tmp;
		}
	}
	return ret;
}

int f[N];
int g[N];
void dfs2(int cur, int last)
{
	if(human[cur])
		f[cur] = 0;
	for(auto v: edges[cur])
		if(v != last)
		{
			dfs2(v, cur);
			if(f[v] != -1)
			{
				if(f[v] + 1 >= f[cur])
				{
					g[cur] = f[cur];
					f[cur] = f[v] + 1;
				}
				else if(f[v] + 1 > g[cur])
					g[cur] = f[v] + 1;

			}
		}
}
int dp[N];
void dfs3(int cur, int last, int old)
{
	if(old == -1)
		dp[cur] = f[cur];
	else
		dp[cur] = max(f[cur], old);
	for(auto v: edges[cur])
		if(v != last)
		{
			int tt = -1;
			if(f[cur] == f[v] + 1)
				tt = max(g[cur], old);
			else
				tt = max(f[cur], old);
			if(tt != -1)
				tt ++;
			dfs3(v, cur, tt);
		}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int sp_city = -1;
	for(int i = 0; i < m; i ++)
	{
		int tmp;
		cin >> tmp;
		human[tmp] = true;
		sp_city = tmp;
	}

	int sum_edges = 0;
	dfs1(sp_city, -1, false, sum_edges);
	sum_edges *= 2;

	memset(f, -1, sizeof(f));
	memset(g, -1, sizeof(g));
	dfs2(1, -1);
	/*
	for(int i = 1; i <= n; i ++)
		cout << i << ' ' << f[i] << ' ' << g[i] << '\n';
	*/
	dfs3(1, -1, -1);

	int del = 0;
	int del_pos = 0;
	if(m == 1)
	{
		cout << sp_city << '\n';
		cout << 0 << '\n';
	}
	else
	{
		for(int i = 1; i <= n; i ++)
			if(human[i] && dp[i] > del)
			{
				del = dp[i];
				del_pos = i;
			}
		cout << del_pos << '\n';
		cout << sum_edges - del << '\n';
	}
	return 0;
}