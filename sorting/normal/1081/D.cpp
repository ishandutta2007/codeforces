#include <bits/stdc++.h>

const long long N = 1e5 + 7;
const long long inf = 1e9;

std::vector<std::
pair<long long, long long> > adj[N];
long long special[N];
long long res, n;
bool used[N];

bool check(long long v, long long mx)
{
	std::stack<long long> st;

	for(long long i = 1; i <= n; i++)
		used[i] = false;

	st.push(v);
	used[v] = true;

	while(!st.empty())
	{
		long long x = st.top();
		st.pop();

		for(std::pair<long long, long long> p: adj[x])
			if(p.second <= mx && !used[p.first])
			{
				used[p.first] = true;
				st.push(p.first);
			}
	}

	for(long long i = 1; i <= n; i++)
		if(!used[i] && special[i])
			return 0;

	return 1;
}

long long solve(long long v)
{
	long long l = 1, r = inf, mid;

	while(l != r)
	{
		mid = (l+r) >> 1ll;

		if(check(v, mid))
			r = mid;
		else
			l = mid+1;
	}

	return l;
}

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long m, k;

	std::cin >> n >> m >> k;

	for(long long i = 0; i < k; i++)
	{
		long long x;

		std::cin >> x;
		special[x] = i+1;
	}

	for(long long i = 0; i < m; i++)
	{
		long long u, v, w;

		std::cin >> u >> v >> w;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for(long long i = 1; i <= n; i++)
		if(special[i])
		{
			res = solve(i);
			break;
		}

	for(long long i = 1; i <= k; i++)
		std::cout << res << " ";

	std::cout << "\n";

	return 0;
}