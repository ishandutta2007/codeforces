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

const int N = 3e5+7;

int n, m, ans;

string s;

VI G[N];

int l[N];
int deg[N];

queue<int> Q;

VI topo;

int dp[N][26];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> s;

	for(int i = 0; i < n; ++i)
	{
		l[i+1] = s[i];
	}

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		++deg[b];
	}

	for(int i = 1; i <= n; ++i)
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

	if(topo.size()<n)
	{
		cout << -1 << endl;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[i][l[i]-'a'] = 1;
	}

	for(int i = n-1; i >= 0; --i)
	{
		int v = topo[i];

		for(auto it:G[v])
		{
			for(int c = 0; c < 26; ++c)
			{
				if('a'+c==l[v])
					dp[v][c] = max(dp[v][c], 1+dp[it][c]);
				else
					dp[v][c] = max(dp[v][c], dp[it][c]);
			}
		}

		for(int c = 0; c < 26; ++c)
		{
			ans = max(ans, dp[v][c]);
		}
	}

	cout << ans << endl;
}