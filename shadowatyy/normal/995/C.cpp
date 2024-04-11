#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

#define int ll
const int N = 1e5+7;
const int mx = 1e12;

int n;

int x[N];
int y[N];
int rep[N];
int zmien[N];
int ans[N];

VI curr;

inline int sq(int a)
{
	return a*a;
}

void oki(int m)
{
	for(int i = 0; i < curr.size(); ++i)
	{
		if(m&(1<<i))
			ans[curr[i]] = 1;
		else
			ans[curr[i]] = -1;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(rep[i]!=i)
		{
			if(zmien[i])
				ans[i] = -ans[rep[i]];
			else
				ans[i] = ans[rep[i]];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}

	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];
		rep[i] = i;
	}

	for(int i = 1; i <= n; ++i)
	{
		bool ok = 0;

		for(int j = 0; j < curr.size(); ++j)
		{
			int len1 = sq(x[i] + x[curr[j]]) + sq(y[i] + y[curr[j]]);
			int len2 = sq(x[i] - x[curr[j]]) + sq(y[i] - y[curr[j]]);

			if(len1<=mx)
			{
				rep[i] = curr[j];
				x[curr[j]] += x[i];
				y[curr[j]] += y[i];
				ok = 1;
				break;
			}
			else if(len2<=mx)
			{
				rep[i] = curr[j];
				x[curr[j]] -= x[i];
				y[curr[j]] -= y[i];
				zmien[i] = 1;
				ok = 1;
				break;
			}
		}

		if(!ok)
			curr.pb(i);
	}

	for(int m = 0; m < 1<<curr.size(); ++m)
	{
		int sx = 0;
		int sy = 0;

		for(int i = 0; i < curr.size(); ++i)
		{
			if(m&(1<<i))
			{
				sx += x[curr[i]];
				sy += y[curr[i]];
			}
			else
			{
				sx -= x[curr[i]];
				sy -= y[curr[i]];
			}
		}

		if(sq(sx)+sq(sy)<=9*mx/4)
		{
			oki(m);
			return 0;
		}
	}
}