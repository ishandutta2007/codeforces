#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int N = 211 * 8;
const int M = 211 * 211 * 4;
int type[N];

vector <int> edges[N];

namespace Tarjan
{
	int scc[N];
	int low[N], dfn[N];
	bool vis[N], ins[N];

	int dfs_id;
	int scc_id;
	stack <int> sta;

	void dfs(int cur)
	{
		sta.push(cur);
		vis[cur] = ins[cur] = true;
		low[cur] = dfn[cur] = dfs_id ++;
		for(int i = 0; i < edges[cur].size(); i ++)
		{
			int v = edges[cur][i];
			if(!vis[v])
			{
				dfs(v);
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
				scc[sta.top()] = scc_id;
				ins[sta.top()] = false;
				if(sta.top() == cur)
					flag = false;
				sta.pop();
			}
			scc_id ++;
		}
	}

	void tarjan(int n)
	{
		dfs_id = 0;
		scc_id = 0;
		memset(vis, 0, sizeof(vis));
		memset(ins, 0, sizeof(ins));
		while(!sta.empty())
			sta.pop();
		for(int i = 0; i < n; i ++)
			if(!vis[i])
				dfs(i);
	}
}

int p1[M], t1[M], p2[M], t2[M];

bool check(int n, int m, int k, string str)
{
	for(int i = 0; i < 2 * n; i ++)
		edges[i].clear();

	for(int i = 0; i < m; i ++)
	{
		edges[p1[i] * 2 + t1[i]].push_back(p2[i] * 2 + t2[i]);
		edges[(p2[i] * 2 + t2[i]) ^ 1].push_back((p1[i] * 2 + t1[i]) ^ 1);
	}

	for(int i = 0; i < k; i ++)
		if(type[str[i] - 'a'] == 0)
			edges[2 * i + 1].push_back(2 * i);
		else
			edges[2 * i].push_back(2 * i + 1);

	Tarjan :: tarjan(2 * n);
	for(int i = 0; i < n; i ++)
		if(Tarjan :: scc[2 * i] == Tarjan :: scc[2 * i + 1])
			return false;
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);
	string tmp;
	cin >> tmp;
	int l = tmp.size();
	for(int i = 0; i < l; i ++)
		type[i] = (tmp[i] == 'V' ? 0 : 1);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		char c1, c2;
		cin >> p1[i] >> c1 >> p2[i] >> c2;
		p1[i] --;
		p2[i] --;
		t1[i] = (c1 == 'V' ? 0 : 1);
		t2[i] = (c2 == 'V' ? 0 : 1);
	}

	string old;
	cin >> old;

	if(check(n, m, n, old))
	{
		cout << old << '\n';
		return 0;
	}

	for(int i = n - 1; i >= 0; i --)
	{
		bool use[2] = {false, false};
		for(char j = old[i] + 1; j < l + 'a'; j ++)
			if(!use[type[j - 'a']])
			{
				use[type[j - 'a']] = true;
				string now = old;
				now[i] = j;
				if(check(n, m, i + 1, now))
				{
					bool flag = true;
					for(int k = i + 1; k < n; k ++)
					{
						bool u[2] = {false, false};
						bool tt = false;
						for(char t = 'a'; t < l + 'a'; t ++)
							if(!u[type[t - 'a']])
							{
								u[type[t - 'a']] = true;
								now[k] = t;
								if(check(n, m, k + 1, now))
								{
									tt = true;
									break;
								}
							}
						flag &= tt;
					}
					if(flag)
					{
						cout << now << '\n';
						return 0;
					}
				}
			}
	}

	cout << -1 << '\n';
	return 0;
}