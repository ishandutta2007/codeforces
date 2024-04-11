#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1201111;
const int Inf = 0x3f3f3f3f;

struct Edge
{
	int v;
	int id;
	int color;
	int w;
	Edge() { }
	Edge(int v, int color, int id) : v(v), color(color), id(id) { }
};
vector <Edge> edges[N];
vector <int> c_edges[N];

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
		for(int i = 0; i < c_edges[cur].size(); i ++)
		{
			int v = c_edges[cur][i];
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

int w[N];
bool check(int limit, int n, int m)
{
	for(int i = 0; i < n; i ++)
		if(w[i] > limit)
			c_edges[(i << 1) + 1].push_back(i << 1);

	bool ret = true;
	Tarjan :: tarjan(2 * m);
	for(int i = 0; i < m; i ++)
		if(Tarjan :: scc[2 * i] == Tarjan :: scc[2 * i + 1])
			ret = false;

	for(int i = 0; i < n; i ++)
		if(w[i] > limit)
			c_edges[(i << 1) + 1].pop_back();
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		int u, v, c;
		cin >> u >> v >> c >> w[i];
		edges[u].push_back(Edge(v, c, i));
		edges[v].push_back(Edge(u, c, i));
	}

	bool flag = true;
	int edge_cnt = m;
	for(int i = 1; i <= n; i ++)
	{
		map <int, int> mp;
		vector <int> vec;
		bool found_pair = false;
		for(int j = 0; j < edges[i].size(); j ++)
		{
			int c = edges[i][j].color;
			int id = edges[i][j].id;
			if(mp.find(c) == mp.end())
				mp[c] = id;
			else
			{
				if(found_pair)
					flag = false;
				found_pair = true;
				c_edges[id << 1].push_back((mp[c] << 1) + 1);
				c_edges[mp[c] << 1].push_back((id << 1) + 1);
			}
			vec.push_back(id);
		}

		for(int j = 0; j < vec.size(); j ++)
		{
			c_edges[(vec[j] << 1) + 1].push_back(((edge_cnt + j) << 1) + 1);
			c_edges[(edge_cnt + j) << 1].push_back(vec[j] << 1);
			if(j > 0)
			{
				c_edges[((edge_cnt + j - 1) << 1) + 1].push_back(((edge_cnt + j) << 1) + 1);
				c_edges[(edge_cnt + j) << 1].push_back((edge_cnt + j - 1) << 1);
			
				c_edges[((edge_cnt + j - 1) << 1) + 1].push_back(vec[j] << 1);
				c_edges[(vec[j] << 1) + 1].push_back((edge_cnt + j - 1) << 1);
			}
		}
		edge_cnt += vec.size();
	}

	if(!flag)
		cout << "No\n";
	else
	{
		int left = 0, right = Inf;
		while(left + 1 < right)
		{
			int mid = (left + right) >> 1;
			if(check(mid - 1, m, edge_cnt))
				right = mid;
			else
				left = mid;
		}

		if(check(left, m, edge_cnt))
		{
			cout << "Yes\n";
			vector <int> vec;
			for(int i = 0; i < m; i ++)
				if(Tarjan :: scc[2 * i] > Tarjan :: scc[2 * i + 1])
					vec.push_back(i);
			cout << left << ' ' << vec.size() << '\n';
			for(int i = 0; i < vec.size(); i ++)
				cout << vec[i] + 1 << ' ';
			cout << '\n';
		}
		else
			cout << "No\n";
	}
	return 0;
}