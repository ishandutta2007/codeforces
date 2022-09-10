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

string s;

int x, y, n;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x >> y >> s;
	s = '#' + s;

	int ile = 1;
	int zer = s[1]=='0';

	for(int i = 2; i <= n; ++i)
	{
		if(s[i]!=s[i-1])
		{
			++ile;

			if(s[i]=='0')
				++zer;
		}
	}

	if(2*y<=x)
		cout << zer*y << endl;
	else
	{
		int ans = 0;

		while(zer)
		{
			if(ile>=4)
			{
				ile -= 2;
				zer -= 1;
				ans += min(x, y);
			}
			else if(ile==3)
			{
				if(s[1]=='0')
				{
					ans += min(x+y, 2*y);
					zer = 0;
				}
				else
				{
					ans += y;
					zer = 0;
				}
			}
			else
			{
				ans += y;
				zer = 0;
			}
		}

		cout << ans << endl;
	}
}