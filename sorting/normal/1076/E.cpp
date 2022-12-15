#include<bits/stdc++.h>

using namespace std;

const long long N = 3e5 + 7;

vector<long long> adj[N];
vector<pair<long long, long long> > q[N];
long long depth[N], len[N], fen[N];
long long n;
long long final_res[N];

void update(long long ind, long long val)
{
	for(; ind <= n; ind += (ind &(-ind)) )
		fen[ind] += val;
}

long long query(long long ind)
{
	long long res = 0;

	for(; ind >= 1; ind -= (ind &(-ind)) )
		res += fen[ind];

	return res;
}

void dfs(long long v, long long p = -1)
{
	//cout << v << " dfs\n";

	depth[v] = 1;
	if(v == 1)
		len[v] = 1;
	else
		len[v] = len[p] + 1;

	for(long long to: adj[v])
	{
		if(to == p)
			continue;

		dfs(to, v);
		depth[v] = max(depth[v], depth[to]+1);
	}
}

void solve(long long v, long long p = -1)
{
	//cout << v << " v\n";

	for(pair<long long, long long> r: q[v])
	{
		//cout << r.first << " " << r.second << endl;
		update(r.first, r.second);
	}

	//cout << len[v] << "len[v]" << endl;
	final_res[v] = query(n) - query(len[v]-1);

	for(long long to: adj[v])
	{
		if(to == p)
			continue;

		solve(to, v);
	}

	for(pair<long long, long long> r: q[v])
	{
		//cout << r.first << " " << r.second << endl;
		update(r.first, -r.second);
	}

}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(long long i = 0; i < n-1; i++)
	{
		long long x, y;

		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1);

	long long m;

	cin >> m;

	for(long long i = 0; i < m; i++)
	{
		long long v, d, x;

		cin >> v >> d >> x;

		q[v].push_back(make_pair(min(d+len[v], n), x));
		//cout << q[v].back().first << endl;
	}

	solve(1);

	for(long long i = 1; i <= n; i++)
		cout << final_res[i] << " ";

	cout << "\n";

	return 0;
}