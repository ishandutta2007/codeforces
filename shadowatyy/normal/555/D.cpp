#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
using namespace std;

#define int long long
#define N 200007

int n, m, a, l;

int x[N];

int s[N];
int p[N];

bool comp(int a, int b)
{
	return x[a]<x[b];
}

int query(int v, int d)
{
	bool zle = 0;

	for(int i = 1; ;++i)
	{
		if(i%2)
		{
			int u = upper_bound(x+1, x+n+1, x[v]+d)-x-1;

			if(u==v)
			{
				if(zle)
					break;

				zle = 1;
				continue;
			}

			if(i>2)
			{
				int ile = d/(x[u]-x[v]);
				d -= ile*(x[u]-x[v]);

				if(ile%2)
					v = u;

				i += ile-1;
			}
			else
			{
				d -= (x[u]-x[v]);
				v = u;
			}
		}
		else
		{
			int u = lower_bound(x+1, x+n+1, x[v]-d)-x;

			if(u==v)
			{
				if(zle)
					break;

				zle = 1;
				continue;
			}

			if(i>2)
			{
				int ile = d/(x[v]-x[u]);
				d -= ile*(x[v]-x[u]);

				if(ile%2)
					v = u;

				i += ile-1;
			}
			else
			{
				d -= (x[v]-x[u]);
				v = u;
			}
			
		}
	}

	return v;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i];
		s[i] = i;
	}

	sort(s+1, s+n+1, comp);
	sort(x+1, x+n+1);

	for(int i = 1; i <= n; ++i)
	{
		p[s[i]] = i;
	}

	x[n+1] = INF;
	x[0] = -INF;

	while(m--)
	{
		cin >> a >> l;

		cout << s[query(p[a], l)] << endl;
	}
}