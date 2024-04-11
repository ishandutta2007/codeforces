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

#define N 107

int n;

string s[N];

VI G[26];

int deg[26];

queue<int> Q;

VI topo;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];

		for(int j = 1; j <= i-1; ++j)
		{
			bool ok = 0;

			for(int k = 0; k < min(SIZE(s[i]), SIZE(s[j])); ++k)
			{
				if(s[i][k]!=s[j][k])
				{
					G[s[j][k]-'a'].pb(s[i][k]-'a');
					++deg[s[i][k]-'a'];
					ok = 1;
					break;
				}
			}

			if(!ok && SIZE(s[j])>SIZE(s[i]))
			{
				cout << "Impossible";
				return 0;
			}
		}
	}

	for(int i = 0; i < 26; ++i)
	{
		if(!deg[i])
			Q.push(i);
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		topo.pb(v);

		for(auto it:G[v])
		{
			if(--deg[it]==0)
				Q.push(it);
		}
	}

	if(SIZE(topo)==26)
	{
		for(auto it:topo)
			cout << char('a'+it);
	}
	else
		cout << "Impossible";

}