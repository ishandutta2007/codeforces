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

const int N = 107;

int n, m;

int deg[N];

int dp[2][26][N][N];

vector<pair<int, char> > G[N];

queue<int> Q;

VI topo;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	while(m--)
	{
		int a, b;
		char c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
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
			if(--deg[it.st]==0)
				Q.push(it.st);
		}
	}

	for(int i = n-1; i >= 0; --i)
	{
		for(int j = n-1; j >= 0; --j)
		{
			int u = topo[i], v = topo[j];

			for(int l = 0; l < 26; ++l)
			{
				dp[0][l][u][v] = 1;

				for(auto it:G[u])
				{
					if(it.nd>='a'+l && dp[1][it.nd-'a'][it.st][v]==0)
						dp[0][l][u][v] = 0;
				}

				dp[1][l][u][v] = 0;

				for(auto it:G[v])
				{
					if(it.nd>='a'+l && dp[0][it.nd-'a'][u][it.st]==1)
						dp[1][l][u][v] = 1;
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(dp[0][0][i][j]==0)
				cout << 'A';
			else
				cout << 'B';
		}

		cout << endl;
	}
}