#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
const int LOGN = 20;

int n;

int fast_log[N];
int lca_table[N][LOGN];

vector<int> adj[N];
vector<int> euler;
int lvl[N], tin[N];

vector<int> to_add;

int min_dist[N];
int curr_dist[N];
bool used[N];

void dfs(int u, int parent)
{
	euler.push_back(u);
	lvl[u] = (parent == -1) ? 0 : lvl[parent] + 1;
	tin[u] = euler.size() - 1;

	for(int to: adj[u])
	{
		if(to == parent)
			continue;

		dfs(to, u);
		euler.push_back(u);
	}
}

void init_lca()
{
	for(int i = 0; i < N; i++)
		fast_log[i] = 0;

	for(int i = 2; i < N; i *= 2)
		fast_log[i] = 1;

	for(int i = 2; i < N; i++)
		fast_log[i] += fast_log[i-1];

	dfs(1, -1);

	for(int i = 0; i < euler.size(); i++)
		lca_table[i][0] = euler[i];

	for(int j = 1; j < LOGN; j++)
		for(int i = 0; i < euler.size(); i++)
		{
			int first = i;
			int second = min((int)euler.size()-1, i + (1 << (j-1)) );

			first = lca_table[first][j-1];
			second = lca_table[second][j-1];

			if(lvl[first] < lvl[second])
				lca_table[i][j] = first;
			else
				lca_table[i][j] = second;
		}

	for(int i = 1; i <= n; i++)
		min_dist[i] = n+1;
}

int lca(int u, int v)
{
	u = tin[u];
	v = tin[v];

	if(u > v)
		swap(u, v);

	//cout << u << " - - " << v << endl;

	int diff = fast_log[v - u + 1];

	int first = u;
	int second = v - (1<<diff) + 1;

	//cout << first << " fs " << second << "\n";

	first = lca_table[first][diff];
	second = lca_table[second][diff];
	
	//cout << first << " fs " << second << "\n";

	if(lvl[first] < lvl[second])
		return first;

	return second;
}

int calc_dist(int u, int v)
{
	int lca_v = lca(u, v);

	//cout << "lca_v: " << lca_v << endl; 

	return lvl[u] + lvl[v] - 2*lvl[lca_v]; 
}


void do_bfs()
{
	queue<int> q;

	for(int i = 1; i <= n; i++)
	{
		used[i] = false;
		curr_dist[i] = n+1;
	}

	for(int x: to_add)
	{
		used[x] = true;
		curr_dist[x] = 0;
		q.push(x);
	}

	to_add.clear();

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		for(int to: adj[x])
		{
			curr_dist[to] = min(curr_dist[to], curr_dist[x] + 1);

			if(!used[to])
			{
				used[to] = true;
				q.push(to); 
			}
		}
	}

	for(int i = 1; i <= n; i++)
		min_dist[i] = min(min_dist[i], curr_dist[i]);
}

int find_min_dist(int u)
{
	int res = min_dist[u];

	//cout << min_dist[u] << " u " << u << "\n";

	for(int v: to_add)
	{
		res = min(res, calc_dist(u, v));
		//cout << calc_dist(u, v) << " " << u << " - " << v << endl;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;

	cin >> n >> m;

	for(int i = 0; i < n-1; i++)
	{
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	init_lca();

	int sqrt_m = sqrt(m);
	if(sqrt_m < 1)
		sqrt_m = 1;

	to_add.push_back(1);

	for(int i = 0; i < m; i++)
	{
		//cout << i << " i\n";

		if(i % sqrt_m == 0)
			do_bfs();

		int type, v;

		cin >> type >> v;

		if(type == 1)
			to_add.push_back(v);
		else
			cout << find_min_dist(v) << "\n";
	}

	return 0;
}