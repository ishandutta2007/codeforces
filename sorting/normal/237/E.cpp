#include<bits/stdc++.h>

using namespace std;

const int N = 1000;
const int inf = 1e9;

int price[N][N], capacity[N][N], flow[N][N];
int dist[N];
bool in_queue[N];
bool adj[N][N];
int come_from[N];
int cnt_v;

int spfa(int from, int to)
{
	for(int i = 1; i <= cnt_v; i++)
		dist[i] = inf;

	dist[from] = 0;

	queue<int> q;

	q.push(from);
	in_queue[from] = true;
	come_from[to] = -1;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		in_queue[u] = false;

		for(int v = 1; v <= cnt_v; v++)
		{
			//if(!adj[u][v])
			//	continue;
			if(capacity[u][v] == flow[u][v])
				continue;

			int w = price[u][v];

			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				come_from[v] = u;

				if(!in_queue[v])
				{
					in_queue[v] = true; 
					q.push(v);
				}
			}
		}
	}

	return dist[to];
}

pair<int, int> max_flow(int from, int to)
{
	int max_flow = 0, min_cost = 0;

	while(true)
	{
		int cost = spfa(from, to);

		if(come_from[to] == -1)
			break;

		int curr_v = to, curr_flow = inf;

		while(curr_v != from)
		{
			int come = come_from[curr_v];

			curr_flow = min(curr_flow, capacity[come][curr_v] - flow[come][curr_v]);
			curr_v = come;
		}

		curr_v = to;

		//cout << to << " ";

		while(curr_v != from)
		{
			int come = come_from[curr_v];

			//cout << come << " ";

			flow[come][curr_v] += curr_flow;
			flow[curr_v][come] -= curr_flow;
			curr_v = come;
		}

		//cout << endl;

		max_flow += curr_flow;
		min_cost += cost*curr_flow;
	}

	return {max_flow, min_cost};
}

int cnt_let[26];

int main ()
{
	string t;
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t >> n;

	cnt_v = n + 28;

	for(int i = 0; i < n; i++)
	{
		string s;
		int a;

		cin >> s >> a;

		adj[1][i+2] = 1;
		capacity[1][i+2] = a;
		price[1][i+2] = i+1;

		for(int j = 0; j < 26; j++)
			cnt_let[j] = 0;

		for(int j = 0; j < s.size(); j++)
			cnt_let[s[j]-'a']++;

		for(int j = 0; j < 26; j++)
		{
			adj[i+2][n+2+j] = 1;
			capacity[i+2][n+2+j] = cnt_let[j];
			price[i+2][n+2+j] = 0;
		}
	}

	for(int j = 0; j < 26; j++)
		cnt_let[j] = 0;

	for(int j = 0; j < t.size(); j++)
		cnt_let[t[j]-'a']++;

	for(int j = 0; j < 26; j++)
	{
		adj[n+2+j][cnt_v] = 1;
		capacity[n+2+j][cnt_v] = cnt_let[j];
		price[n+2+j][cnt_v] = 0;
	}

	pair<int, int> res = max_flow(1, cnt_v);

	if(res.first != t.size())
	{
		cout << "-1\n";

		return 0;
	}

	cout << res.second << "\n";

	return 0;
}