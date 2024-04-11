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

const int N = 1e5+7;

int n, m;

int t[N];

int deg[N];

queue<int> P, C;

VI G[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		cin >> t[i];
	}

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		G[b].pb(a);
		++deg[a];
	}

	for(int i = 0; i < n; ++i)
	{
		if(!deg[i])
		{
			if(t[i]==0)
				P.push(i);
			else
				C.push(i);
		}
	}

	int ans = 0;

	while(P.size()+C.size())
	{
		while(!P.empty())
		{
			int v = P.front();
			P.pop();

			for(auto it:G[v])
			{
				if(--deg[it]==0)
				{
					if(t[it]==0)
						P.push(it);
					else
						C.push(it);
				}
			}
		}

		if(!C.empty())
			++ans;

		while(!C.empty())
		{
			int v = C.front();
			C.pop();

			for(auto it:G[v])
			{
				if(--deg[it]==0)
				{
					if(t[it]==0)
						P.push(it);
					else
						C.push(it);
				}
			}
		}
	}

	cout << ans;
}