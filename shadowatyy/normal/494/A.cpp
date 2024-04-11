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

#define N 100007

string s;

int n, d, last = -1;

int ans[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();
	s = '$'+s;

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='(')
			++d;
		else if(s[i]==')')
			--d;
		else
			last = i;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='#')
		{
			if(i==last)
				ans[i] = d;
			else
			{
				ans[i] = 1;
				--d;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='#' && ans[i]<1)
		{
			cout << -1;
			return 0;
		}
	}

	int curr = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='(')
			++curr;
		else if(s[i]==')')
			--curr;
		else
			curr -= ans[i];

		if(curr<0)
		{
			cout << -1;
			return 0;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='#')
			cout << ans[i] << endl;
	}
}