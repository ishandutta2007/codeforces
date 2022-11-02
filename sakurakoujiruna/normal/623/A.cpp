#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 511;

bool e[N][N];

vector <int> edges[N];
int ans[N];
bool vis[N];

void dfs(int cur, int color)
{
	ans[cur] = color;
	vis[cur] = true;
	for(auto &v : edges[cur])
		if(!vis[v])
		{
			dfs(v, 1 - color);
		}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		int u, v;
		cin >> u >> v;
		e[u][v] = e[v][u] = true;
	}
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++)
			if(!e[i][j])
			{
				//cout << i << ' ' << j << '\n';
				edges[i].push_back(j);
				edges[j].push_back(i);
			}

	bool flag = true;
	for(int i = 1; i <= n; i ++)
		ans[i] = 2;

	for(int i = 1; i <= n; i ++)
		if(!vis[i] && edges[i].size() != 0)
			dfs(i, 0);
		/*
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << '\n';
*/
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++)
			if(ans[i] + ans[j] == 1 && ans[i] < 2 && ans[j] < 2)
			{
				if(e[i][j])
				{
					//cout << i << ' ' << j << '\n';
					flag = false;
				}
			}
			else if(!e[i][j])
			{
				//cout << i << ' ' << j << '\n';
				flag = false;
			}

	if(flag)
	{
		cout << "Yes\n";
		for(int i = 1; i <= n; i ++)
			if(ans[i] == 2)
				cout << 'b';
			else if(ans[i] == 1)
				cout << 'c';
			else
				cout << 'a';
		cout << '\n';
	}
	else
		cout << "No\n";
	return 0;
}