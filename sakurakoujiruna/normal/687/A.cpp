#include <bits/stdc++.h>
using namespace std;

const int N = 100011;

int c[N];
int cnt[2];
vector <int> edges[N];

bool vis[N];
bool dfs(int x)
{
	cnt[c[x]] ++;
	vis[x] = true;
	for(auto &v : edges[x])
		if(!vis[v])
		{
			c[v] = 1 - c[x];
			if(!dfs(v))
				return false;
		}
		else if(c[v] == c[x])
			return false;
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	while(m --)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	bool flag = true;
	for(int i = 1; i <= n; i ++)
		if(!vis[i])
			flag &= dfs(i);

	if(!flag)
	{
		cout << -1 << '\n';
		return 0;
	}

	cout << cnt[0] << '\n';
	for(int i = 1; i <= n; i ++)
		if(c[i] == 0)
			cout << i << ' ';
	cout << '\n';
	cout << cnt[1] << '\n';
	for(int i = 1; i <= n; i ++)
		if(c[i] == 1)
			cout << i << ' ';
	cout << '\n';

	return 0;
}