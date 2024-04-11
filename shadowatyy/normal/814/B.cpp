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

#define N 1007

int n, ile, pos1, pos2;

int a[N];
int b[N];

bitset<N> vis;

int res[N];

bool check()
{
	vis.reset();

	for(int i = 1; i <= n; ++i)
	{
		if(vis[res[i]])
			return 0;

		vis[res[i]] = 1;
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		vis[a[i]] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]!=b[i])
		{
			if(ile==0)
				pos1 = i;
			else
				pos2 = i;

			++ile;
		}
	}

	if(ile==1)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(a[i]==b[i])
				cout << a[i] << " ";
			else
			{
				for(int j = 1; j <= n; ++j)
				{
					if(!vis[j])
					{
						cout << j << " ";
						break;
					}
				}
			}
		}
	}
	else
	{
		for(int i = 1; i <= n; ++i)
		{
			if(a[i]==b[i])
				res[i] = a[i];
			else if(i==pos1)
				res[i] = a[i];
			else
				res[i] = b[i];
		}

		if(check())
		{
			for(int i = 1; i <= n; ++i)
			{
				cout << res[i] << " ";
			}
		}
		else
		{
			for(int i = 1; i <= n; ++i)
			{
				if(a[i]==b[i])
					res[i] = a[i];
				else if(i==pos1)
					res[i] = b[i];
				else
					res[i] = a[i];
			}

			for(int i = 1; i <= n; ++i)
			{
				cout << res[i] << " ";
			}
		}
	}	
}