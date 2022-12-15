#include<bits/stdc++.h>

using namespace std;

struct edge
{
	int to, price, ind;
	bool dir;

	edge(int a, int b, int c, bool d)
	{
		to = a;
		price = b;
		ind = c;
		dir = d;
	}
};

const int N = 2e5 + 7;

vector<edge> adj[N];
bool res[N];
bool used[N];

int n, m;

int outflow[N];

void bfs()
{
	queue<int> q;

	q.push(1);

	used[1] = 1;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(int i = 0; i < adj[curr].size(); i++)
		{
			int to = adj[curr][i].to;

			if(!used[to])
			{
				res[adj[curr][i].ind] = adj[curr][i].dir;
				outflow[to] -= 2*adj[curr][i].price;

				if(outflow[to] == 0 && to != n)
				{
					used[to] = 1;
					q.push(to);
				}
			}
		}
	}
}

int main ()
{
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int x, y, z;

		cin >> x >> y >> z;

		adj[x].push_back(edge(y,z,i,0));
		adj[y].push_back(edge(x,z,i,1));

		outflow[x] += z;
		outflow[y] += z;
	}

	bfs();

	for(int i = 0; i < m; i++)
		cout << res[i] << "\n";

	return 0;
}