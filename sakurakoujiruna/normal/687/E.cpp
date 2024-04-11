#include <bits/stdc++.h>
using namespace std;

const int N = 5011;

vector <int> edges[N];
int u[N], v[N];

int scc[N];
int low[N], dfn[N];
bool vis[N], ins[N];

int dfs_id = 0;
int scc_cnt = 0;
stack <int> sta;

void tarjan(int cur)
{
	sta.push(cur);
	vis[cur] = ins[cur] = true;
	low[cur] = dfn[cur] = dfs_id ++;
	for(int i = 0; i < edges[cur].size(); i ++)
	{
		int v = edges[cur][i];
		if(!vis[v])
		{
			tarjan(v);
			low[cur] = min(low[cur], low[v]);
		}
		else if(ins[v])
			low[cur] = min(low[cur], dfn[v]);
	}
	if(dfn[cur] == low[cur])
	{
		bool flag = true;
		while(flag)
		{
			scc[sta.top()] = scc_cnt;
			ins[sta.top()] = false;
			if(sta.top() == cur)
				flag = false;
			sta.pop();
		}
		scc_cnt ++;
	}
}

bool now[N];
int step[N];

vector <int> ne[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		cin >> u[i] >> v[i];
		edges[u[i]].push_back(v[i]);
	}
	for(int i = 1; i <= n; i ++)
		if(!vis[i])
			tarjan(i);

	int ans = n;
	for(int ns = 0; ns < scc_cnt; ns ++)
	{
		memset(now, 0, sizeof(now));
		vector <int> allnow;
		for(int i = 1; i <= n; i ++)
			if(scc[i] == ns)
			{
				now[i] = true;
				allnow.push_back(i);
			}
			/*
		for(auto &x : allnow)
			cout << x << ' ';
		cout << '\n';
		*/

		bool out = false;
		for(int i = 0; i < m; i ++)
			if(now[u[i]] && !now[v[i]])
				out = true;
		//cout << out << '\n';

		if(!out)
		{
			if(allnow.size() == 1)
				continue;
			for(int i = 1; i <= n; i ++)
				ne[i].clear();
			for(int i = 0; i < m; i ++)
				if(now[u[i]] && now[v[i]])
					ne[u[i]].push_back(v[i]);

			int mc = n;
			for(int i = 1; i <= n; i ++)
				if(now[i])
				{
					queue <int> q;
					q.push(i);
					for(auto &nv : allnow)
						step[nv] = -1;
					step[i] = 0;
					while(!q.empty())
					{
						int c = q.front();
						q.pop();
						for(auto &v : ne[c])
							if(step[v] == -1)
							{
								step[v] = step[c] + 1;
								q.push(v);
							}
							else if(v == i)
								mc = min(mc, step[c] + 1);
					}
				}
			ans += 998 * mc + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}