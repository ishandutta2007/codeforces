#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

#define N 1000007

int n, curr;

int p[N];
int ile[N];
int res[N];

VI cyc[N];

bitset<N> vis;
bitset<N> ok;

VI c;

bool comp(int a, int b)
{
	return cyc[a].size()<cyc[b].size();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			int v = i;
			cyc[++curr].pb(v);
			vis[v] = 1;

			while(!vis[p[v]])
			{
				v = p[v];
				cyc[curr].pb(v);
				vis[v] = 1;
			}
		}
	}

	for(int i = 1; i <= curr; ++i)
	{
		++ile[cyc[i].size()];
		c.pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(i%2==0 && ile[i]%2==1)
		{
			cout << -1;
			return 0;
		}
	}

	sort(ALL(c), comp);

	for(int i = 0; i < c.size(); ++i)
	{
		if(cyc[c[i]].size()%2==1)
		{
			int ile = -1;

			if(cyc[c[i]].size()==1)
				ile = 0;
			else
			{
				ile = 1;

				while((ile*2)%cyc[c[i]].size()!=1)
					++ile;
			}

			for(int j = 0; j < cyc[c[i]].size(); ++j)
			{
				res[cyc[c[i]][j]] = cyc[c[i]][(j+ile)%cyc[c[i]].size()];
			}
		}
		else
		{
			for(int j = 0; j < cyc[c[i]].size(); ++j)
			{
				res[cyc[c[i]][j]] = cyc[c[i+1]][j];
				res[cyc[c[i+1]][j]] = cyc[c[i]][(j+1)%cyc[c[i]].size()];
			}

			++i;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}