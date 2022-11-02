#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 5111;
const int Inf = 0x3f3f3f3f;

vector <int> edges[N];

int deg[N];
int size[N];
int f[N][N][2];

int g[N][N][2];

void update(int &a, int b)
{
	if(b < a)
		a = b;
}

void dfs(int cur, int last = 0)
{
	size[cur] = 1;
	if(deg[cur] == 1)
	{
		f[cur][1][0] = 0;
		f[cur][0][1] = 0;
	}
	else
	{
		vector <pair <int, int> > vec;
		for(int i = 0; i < edges[cur].size(); i ++)
		{
			int v = edges[cur][i];
			if(v == last)
				continue;

			dfs(v, cur);
			size[cur] += size[v];
			vec.push_back(make_pair(size[v], v));
		}


		sort(vec.begin(), vec.end());
		int sum = 0;
		
		//g[0][0][0] = 0;
		//g[0][0][1] = 0;

		for(int i = 0; i < vec.size(); i ++)
		{
			int v = vec[i].second;
			int old_sum = sum;
			sum += vec[i].first;

			//cout << v << ' ' << size[v] << '\n';
			if(i == 0)
			{
				for(int k = 0; k <= vec[i].first; k ++)
				{
					g[i + 1][k][0] = min(f[v][k][0], f[v][k][1] + 1);
					g[i + 1][k][1] = min(f[v][k][1], f[v][k][0] + 1);
				}
			}
			else
				for(int j = 0; j <= sum; j ++)
				{
					g[i + 1][j][0] = Inf;
					g[i + 1][j][1] = Inf;

					for(int k = 0; k <= vec[i].first; k ++)
						if(j - k >= 0 && j - k <= old_sum)
						{
							//cout << i << ' ' << j << ' ' << k << '\n';
							//cout << g[i + 1][j][0] << ' ' << g[i][j - k][0] << ' ' << f[v][k][0] << '\n';
							//cout << g[i + 1][j][0] << ' ' << g[i][j - k][0] << ' ' << f[v][k][1] << '\n';
							update(g[i + 1][j][0], g[i][j - k][0] + f[v][k][0]);
							update(g[i + 1][j][0], g[i][j - k][0] + f[v][k][1] + 1);
							update(g[i + 1][j][1], g[i][j - k][1] + f[v][k][1]);
							update(g[i + 1][j][1], g[i][j - k][1] + f[v][k][0] + 1);
							//cout << g[i + 1][j][0] << ' ' << g[i + 1][j][1] << '\n';
							//cout << "------\n";
						}
				}
		}

		for(int i = 0; i <= sum; i ++)
		{
			//cout << vec.size() + 1 << ' ' << i << '\n';
			//cout << g[vec.size() + 1][i][0] << ' ' << g[vec.size() + 1][i][1] << '\n';
			f[cur][i][0] = g[vec.size()][i][0];
			f[cur][i][1] = g[vec.size()][i][1];
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		deg[u] ++;
		deg[v] ++;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	if(n == 2)
		cout << 1 << '\n';
	else
	{
		int root = -1;
		int leaf_cnt = 0;
		for(int i = 1; i <= n; i ++)
			if(deg[i] != 1)
				root = i;
			else
				leaf_cnt ++;

		memset(f, 0x3f, sizeof(f));
		dfs(root);

		/*
		for(int i = 1; i <= n; i ++)
			for(int j = 0; j <= size[i]; j ++)
				cout << i << ' ' << j << ' ' << f[i][j][0] << ' ' << f[i][j][1] << '\n';
		*/
		//cout << root << '\n';
		cout << min(f[root][leaf_cnt / 2][0], f[root][leaf_cnt / 2][1]) << '\n';
	}
	return 0;
}