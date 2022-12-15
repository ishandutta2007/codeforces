#include<bits/stdc++.h>

using namespace std;

const long long N = 3e5 + 7;
const long long inf = 1e18;

struct edge
{
	long long to, w;
	long long ind;
};

vector<edge> adj[N];
vector<long long> res;
long long dist[N], pr[N];

struct cmp
{
	bool operator()(pair<long long, long long> u, pair<long long, long long> v)
	{
		return u.second > v.second;
	}
};

void dijkstra(long long n, long long m, long long k)
{
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, cmp> q;

	q.push({1, 0});
	dist[1] = 0;
	pr[1] = -1;

	for(long long i = 2; i <= n; i++)
		dist[i] = inf;

	while(!q.empty() && k)
	{
		pair<long long, long long> z = q.top();
		q.pop();

		long long v = z.first;

		//cout << v << " " << dist[v] << endl;

		if(z.second > dist[v])
			continue;


		if(pr[v] != -1)
		{
			res.push_back(pr[v]);
			k--;
		}

		for(edge e: adj[v])
		{
			long long to = e.to;

			if(dist[v] + e.w < dist[to])
			{
				dist[to] = dist[v] + e.w;
				pr[to] = e.ind;

				q.push({to, dist[to]});
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, k;
	edge e;

	cin >> n >> m >> k;

	for(long long i = 0; i < m; i++)
	{
		long long u, v, w;

		cin >> u >> v >> w;

		e.to = v;
		e.w = w;
		e.ind = i+1;

		adj[u].push_back(e);

		e.to = u;

		adj[v].push_back(e);
	}

	dijkstra(n, m, k);

	cout << res.size() << "\n";

	for(long long i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	cout << "\n";

	return 0;
}