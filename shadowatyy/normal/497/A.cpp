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
#define SIZE(x) (int)(x).size()
using namespace std;

int n, m;

vector<string> v;

int solve(vector<string> v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = i+1; j < v.size(); ++j)
		{
			bool ok = 0;

			for(int k = 0; k < v[i].size(); ++k)
			{
				if(v[i][k]<v[j][k])
					ok = 1;
				else if(v[i][k]>v[j][k] && !ok)
				{
					vector<string> nast;

					for(int l = 0; l < v.size(); ++l)
					{
						nast.pb(v[l].substr(0, k));
						nast.back() += v[l].substr(k+1, inf);
					}

					return solve(nast)+1;
				}
			}
		}
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		v.pb(s);
	}

	cout << solve(v);
}