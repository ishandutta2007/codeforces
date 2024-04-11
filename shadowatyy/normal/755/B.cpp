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

int n, m, b;

string s;

set<string> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s;
		S.insert(s);
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> s;
		S.insert(s);
	}

	b = n+m-S.size();
	n -= b;
	m -= b;

	for(int t = 1; ; ++t)
	{
		if(t%2==1)
		{
			if(b>0)
				--b;
			else if(n>0)
				--n;
			else
			{
				cout << "NO";
				return 0;
			}
		}
		else
		{
			if(b>0)
				--b;
			else if(m>0)
				--m;
			else
			{
				cout << "YES";
				return 0;
			}
		}
	}
}