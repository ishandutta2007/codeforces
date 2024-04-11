#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

vector<int> adj[N];
int lvl[N];

void dfs(int u, int level)
{
	lvl[u] = level;

	for(auto to: adj[u])
		if(!lvl[to])
			dfs(to, level+1);

	return;
}

int main ()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n-1; i++)
	{
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	long double res = 0;

	for(int i = 1; i <= n; i++)
		res += (long double)1.0/lvl[i];

	cout << setprecision(7) << fixed << res << "\n";

	return 0;
}