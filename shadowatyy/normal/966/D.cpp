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

#define ull unsigned ll
const int N = 3e5+7;

int n, m;

VI G[N];

int dist[N];
int skad[N];

int a[N];
int b[N];

queue<int> Q;

VI ans;

ull los[N];
ull hasz[N];

void wypisz()
{
	cout << ans.size()-1 << endl;

	for(auto it:ans)
		cout << it << " ";

	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i];
		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		dist[i] = inf;
	}

	dist[1] = 0;
	Q.push(1);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(auto it:G[v])
		{
			if(dist[it]==inf)
			{
				dist[it] = dist[v]+1;
				skad[it] = v;
				Q.push(it);
			}
		}
	}

	if(dist[n]!=inf)
	{
		int curr = n;

		while(curr)
		{
			ans.pb(curr);
			curr = skad[curr];
		}

		reverse(ALL(ans));
	}

	bool f = 0;

	for(int i = 2; i <= n; ++i)
	{
		if(dist[i]==2 && (ans.size()>5 || ans.empty()))
		{
			ans = {1, skad[i], i, 1, n};
			f = 1;
		}
	}

	if(!f && (ans.size()>6 || ans.empty()))
	{
		for(int i = 1; i <= n; ++i)
		{
			for(auto &it:G[i])
			{	
				if(it==1)
				{
					swap(it, G[i].back());
					G[i].pop_back();
					break;
				}
			}
		}

		G[1].clear();

		for(int i = 1; i <= n; ++i)
		{
			los[i] = (((ll)rand())<<30) ^ rand();
		}

		for(int i = 1; i <= n; ++i)
		{
			for(auto it:G[i])
			{
				hasz[i] ^= los[it];
			}
		}

		for(int i = 1; i <= m; ++i)
		{
			if(dist[a[i]]!=inf && dist[b[i]]!=inf && a[i]!=1 && b[i]!=1 && (hasz[a[i]]^los[b[i]])!=(hasz[b[i]]^los[a[i]]))
			{
				if(G[a[i]].size()<G[b[i]].size())
					swap(a[i], b[i]);

				sort(ALL(G[b[i]]));

				for(auto it:G[a[i]])
				{
					if(it!=b[i] && !binary_search(ALL(G[b[i]]), it))
					{
						ans = {1, it, a[i], b[i], it, n};
						wypisz();
						exit(0);
					}
				}
			}
		}
	}	

	if(ans.size())
		wypisz();
	else
		cout << -1 << endl;
}