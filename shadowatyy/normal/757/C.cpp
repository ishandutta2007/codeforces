#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
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

#define N 1000007
#define MOD 1000000007

int n, m, g, a, ile;

ll res = 1;

VPII wyst[N];

VI wej[N];

VI v;

bool comp(int a, int b)
{
	return wyst[a]<wyst[b];
}

ll fact(ll a)
{
	if(a==0 || a==1)
		return 1;

	return (a*fact(a-1))%MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> g;

		while(g--)
		{
			cin >> a;

			wej[i].pb(a);
		}

		sort(ALL(wej[i]));

		a = wej[i][0];

		ile = 1;

		for(int j = 1; j < wej[i].size(); ++j)
		{
			if(wej[i][j]==wej[i][j-1])
				++ile;
			else
			{
				wyst[a].eb(i, ile);

				a = wej[i][j];

				ile = 1;
			}
		}

		wyst[a].eb(i, ile);
	}

	for(int i = 1; i <= m; ++i)
	{
		v.pb(i);
	}

	sort(ALL(v), comp);

	ile = 1;

	for(int i = 1; i < m; ++i)
	{
		if(wyst[v[i]]==wyst[v[i-1]])
			++ile;
		else
		{
			res = (res*fact(ile))%MOD;
			ile = 1;
		}
	}

	res = (res*fact(ile))%MOD;

	cout << res;
}