#include<bits/stdc++.h>

using namespace std;

const long long N = 3e5 + 7;

long long w[N];
vector<pair<long long, long long> > adj[N];

pair<long long, long long> solve(long long u, long long p = -1)
{
	pair<long long, long long> res;

	res.first = w[u];
	res.second = w[u];

	for(pair<long long, long long> to_pair: adj[u])
	{
		long long to = to_pair.first;
		long long c = to_pair.second;

		if(to == p)
			continue;

		pair<long long, long long> p = solve(to, u);

		res.first = max(res.first, p.first);
		res.first = max(res.first, p.second - c + res.second);
		res.second = max(res.second, w[u] - c + p.second);
	}

	return res;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 1; i <= n; i++)
		cin >> w[i];

	for(long long i = 1; i < n; i++)
	{
		long long u, v, c;

		cin >> u >> v >> c;

		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	cout << solve(1).first << "\n";

	return 0;
}