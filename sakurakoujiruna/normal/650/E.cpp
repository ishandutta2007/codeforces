#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <numeric>
using namespace std;

const int N = 500011;

struct DisjointSet
{
	int p[N];
	void init()
	{
		iota(p, p + N, 0);
	}
	int find(int x)
	{
		if(p[x] == x)
			return x;
		return p[x] = find(p[x]);
	}
	bool query(int a, int b)
	{
		return find(a) == find(b);
	}
	void merge(int a, int b)
	{
		p[find(a)] = find(b);
	}
}ds;

vector <int> edges[2][N];
set <int> st[N];

int par[N];
void dfs1(int cur, int last)
{
	for(auto &v : edges[1][cur])
		if(v != last)
		{
			par[v] = cur;
			dfs1(v, cur);
		}
}

void dfs0(int cur, int last, vector <pair <int, int> > &ans0, vector <pair <int, int> > &ans1)
{
	for(auto &v : edges[0][cur])
		if(v != last)
		{
			dfs0(v, cur, ans0, ans1);
			ans0.push_back({v, cur});
			ans1.push_back({v, par[v]});
		}
}

int main()
{
	//ios :: sync_with_stdio(false);
	int n;
	//cin >> n;
	scanf("%d", &n);
	set <pair <int, int> > st0, st1;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		//cin >> u >> v;
		scanf("%d%d", &u, &v);
		if(u > v)
			swap(u, v);
		st0.insert({u, v});
	}
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		//cin >> u >> v;
		scanf("%d%d", &u, &v);
		if(u > v)
			swap(u, v);
		st1.insert({u, v});
	}

	ds.init();
	for(auto &p : st0)
		if(st1.find(p) != st1.end())
			ds.merge(ds.find(p.first), ds.find(p.second));

	map <pair <int, int>, pair <int, int> > old[2];
	for(auto &p : st0)
		if(!ds.query(p.first, p.second))
		{
			int a = ds.find(p.first);
			int b = ds.find(p.second);
			edges[0][a].push_back(b);
			edges[0][b].push_back(a);
			//cout << a << ' ' << b << '\n';
			if(a < b)
				old[0][{a, b}] = p;
			else
				old[0][{b, a}] = p;
		}
	for(auto &p : st1)
		if(!ds.query(p.first, p.second))
		{
			int a = ds.find(p.first);
			int b = ds.find(p.second);
			st[a].insert(b);
			st[b].insert(a);
			edges[1][a].push_back(b);
			edges[1][b].push_back(a);
			//cout << a << ' ' << b << '\n';
			if(a < b)
				old[1][{a, b}] = p;
			else
				old[1][{b, a}] = p;
		}

	vector <pair <int, int> > ans[2];
	for(int i = 1; i <= n; i ++)
		if(ds.find(i) == i)
		{
			dfs1(i, -1);
			dfs0(i, -1, ans[0], ans[1]);
			break;
		}
	
	for(int i = 0; i < 2; i ++)
		for(auto &p : ans[i])
		{
			if(p.first > p.second)
				swap(p.first, p.second);
			p = old[i][p];
		}
	//cout << ans[0].size() << '\n';
	printf("%d\n", (int)ans[0].size());
	for(int i = 0; i < ans[0].size(); i ++)
		//cout << ans[0][i].first << ' ' << ans[0][i].second << ' ' <<
			//ans[1][i].first << ' ' << ans[1][i].second << '\n';
		printf("%d %d %d %d\n", ans[0][i].first, ans[0][i].second,
			ans[1][i].first, ans[1][i].second);
			
			
	return 0;
}