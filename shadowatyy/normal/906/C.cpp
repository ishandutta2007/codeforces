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

int n, m;

int G[22];
int dp[1<<22];
int skad[1<<22];
int czym[1<<22];

VI ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	if(m==n*(n-1)/2)
	{
		cout << 0;
		return 0;
	}

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a] |= 1<<b;
		G[b] |= 1<<a;
	}

	for(int i = 0; i < 1<<n; ++i)
	{
		dp[i] = inf;
	}

	for(int i = 0; i < n; ++i)
	{
		dp[1<<i] = 0;
	}

	for(int i = 0; i < 1<<n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(!(i&(1<<j)))
				continue;

			if(dp[i|G[j]]>dp[i]+1)
			{
				dp[i|G[j]] = dp[i]+1;
				skad[i|G[j]] = i;
				czym[i|G[j]] = j;
			}
		}
	}

	int curr = (1<<n)-1;

	while(dp[curr])
	{
		ans.pb(czym[curr]);
		curr = skad[curr];
	}

	cout << ans.size() << endl;

	for(auto it:ans)
		cout << it+1 << " ";
}