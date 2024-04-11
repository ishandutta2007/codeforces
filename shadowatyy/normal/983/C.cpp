#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 2007;

int n;

int a[N];
int b[N];

map<pair<PII, VI>, int> dist;
deque<pair<PII, VI> > Q;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		--a[i];
		--b[i];
	}

	dist[mp(mp(0, 0), VI(9, 0))] = 0;
	Q.eb(mp(0, 0), VI(9, 0));

	while(!Q.empty())
	{
		auto v = Q.front();
		Q.pop_front();

		if(v.nd[v.st.nd]>0)
		{
			auto u = v;
			u.nd[u.st.nd] = 0;

			if(dist.find(u)==dist.end())
			{
				dist[u] = dist[v];
				Q.push_front(u);
			}

			continue;
		}

		if(v.st.nd!=8)
		{
			auto u = v;
			++u.st.nd;

			if(dist.find(u)==dist.end())
			{
				dist[u] = dist[v]+1;
				Q.pb(u);
			}
		}

		if(v.st.nd!=0)
		{
			auto u = v;
			--u.st.nd;

			if(dist.find(u)==dist.end())
			{
				dist[u] = dist[v]+1;
				Q.pb(u);
			}
		}

		int ile = 0;

		for(auto it:v.nd)
			ile += it;

		if(ile<4 && v.st.st<n && a[v.st.st+1]==v.st.nd)
		{
			auto u = v;
			++u.nd[b[v.st.st+1]];
			++u.st.st;

			if(dist.find(u)==dist.end())
			{
				dist[u] = dist[v];
				Q.push_front(u);
			}
		}
	}

	int ans = inf;

	for(int i = 0; i < 9; ++i)
	{
		if(dist.find(mp(mp(n, i), VI(9, 0)))!=dist.end())
			ans = min(ans, dist[mp(mp(n, i), VI(9, 0))]);
	}

	cout << ans+2*n << endl;
}