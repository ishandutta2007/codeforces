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

const int N = 1e6+7;

int t, n, curr = 1;

string s;

int trie[N][26];
int depth[N];
int suf[N];

queue<int> Q;

VI G[N];

int dp[N][2];
bitset<N> vis;

void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);
			dp[v][0] += max(dp[it][0], dp[it][1]);
			dp[v][1] += dp[it][0];
		}
	}

	++dp[v][1];
}

void clear()
{
	for(int i = 1; i <= curr; ++i)
	{
		dp[i][0] = dp[i][1] = 0;
		vis[i] = 0;
		G[i].clear();
		suf[i] = 0;
		depth[i] = 0;
		memset(trie[i], 0, sizeof trie[i]);
	}

	curr = 1;
}

void solve()
{
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s;

		int v = 1;

		for(int j = 0; j < s.size(); ++j)
		{
			if(!trie[v][s[j]-'a'])
				trie[v][s[j]-'a'] = ++curr;

			v = trie[v][s[j]-'a'];
			depth[v] = j;
		}
	}	

	Q.push(1);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(int i = 0; i < 26; ++i)
		{
			if(trie[v][i])
			{
				if(v==1)
					suf[trie[v][i]] = 1;
				else
				{
					int u = suf[v];

					while(!trie[u][i] && u!=1)
						u = suf[u];

					if(trie[u][i])
						u = trie[u][i];

					suf[trie[v][i]] = u;
				}

				Q.push(trie[v][i]);
			}
		}
	}

	for(int i = 2; i <= curr; ++i)
	{
		if(suf[i]!=1 && depth[suf[i]]+1==depth[i])
		{
			G[i].pb(suf[i]);
			G[suf[i]].pb(i);
		}
	}

	int ans = 0;

	for(int i = 2; i <= curr; ++i)
	{
		if(!vis[i])
		{
			dfs(i);
			ans += max(dp[i][0], dp[i][1]);
		}
	}

	cout << ans << endl;
	clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
		solve();
}