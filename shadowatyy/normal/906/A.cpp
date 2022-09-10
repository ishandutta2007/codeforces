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

int n, mini = -1, cnt;

bitset<26> vis;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	int poss = (1<<26)-1;

	while(n--)
	{
		char t;
		cin >> t;

		int m = 0;

		if(t=='.' || t=='!')
		{
			string s;
			cin >> s;

			vis.reset();

			for(auto it:s)
			{
				vis[it-'a'] = 1;
			}

			for(int i = 0; i < 26; ++i)
			{
				if(vis[i])
					m ^= 1<<i;
			}
		}

		if(t=='.')
		{
			poss &= ~m;

			if(__builtin_popcount(poss)==1 && mini==-1)
				mini = cnt;
		}
		else if(t=='!')
		{
			++cnt;

			poss &= m;

			if(__builtin_popcount(poss)==1 && mini==-1)
				mini = cnt;
		}
		else if(t=='?')
		{
			++cnt;
			char c;
			cin >> c;

			poss &= ~(1<<(c-'a'));

			if(__builtin_popcount(poss)==1 && mini==-1)
				mini = cnt;
		}
	}

	--cnt;

	if(mini==-1)
		cout << 0;
	else
		cout << cnt-mini;
}