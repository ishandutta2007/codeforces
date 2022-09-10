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

int n;

string s, ans;

bitset<1<<13> ok;

char best[1<<13];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	if(s.size()==1)
	{
		cout << s << endl;
		return 0;
	}

	n = s.size();
	s = '#'+s;

	int l = 31-__builtin_clz(n);
	int len = n-(1<<l)+1;

	ok[0] = 1;

	for(int i = 1; i <= len; ++i)
	{
		for(int j = 0; j < 1<<l; ++j)
		{
			best[j] = 'z'+1;
		}

		for(int j = 0; j < 1<<l; ++j)
		{
			if(!ok[j])
				continue;

			int m = ~j&((1<<l)-1);

			for(int k = m; ; k = (k-1)&m)
			{
				best[j|k] = min(best[j|k], s[i+j+k]);

				if(!k)
					break;
			}
		}

		char all = 'z';

		for(int j = 0; j < 1<<l; ++j)
		{
			all = min(all, best[j]);
		}

		for(int j = 0; j < 1<<l; ++j)
		{
			if(best[j]==all)
				ok[j] = 1;
			else
				ok[j] = 0;
		}

		ans += all;
	}

	cout << ans << endl;
}