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

const int N = 2e5+7;

int n, m, s, chce, cnt;

VI G[N];

int vis[N][2];
int skad[N][2];

queue<PII> Q;

VI ok;
int deg[N];

queue<int> X;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;

		while(x--)
		{
			int y;
			cin >> y;
			G[i].pb(y);
		}
	}

	cin >> s;
	vis[s][0] = 1;
	Q.emplace(s, 0);

	while(!Q.empty())
	{
		int v = Q.front().st;
		int p = Q.front().nd;
		Q.pop();

		for(auto it:G[v])
		{
			if(!vis[it][p^1])
			{
				vis[it][p^1] = 1;
				skad[it][p^1] = v;
				Q.emplace(it, p^1);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(G[i].empty() && vis[i][1])
		{
			cout << "Win" << endl;

			VI ans;

			int curr = i, p = 1;

			ans.pb(curr);

			while(curr!=s || p)
			{
				curr = skad[curr][p];
				p ^= 1;
				ans.pb(curr);
			}

			reverse(ALL(ans));

			for(auto it:ans)
				cout << it << " ";

			exit(0);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(vis[i][0] || vis[i][1])
		{
			++chce;

			for(auto it:G[i])
			{
				++deg[it];
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if((vis[i][0] || vis[i][1]) && !deg[i])
		{
			X.push(i);
		}
	}

	while(!X.empty())
	{
		int v = X.front();
		X.pop();
		++cnt;

		for(auto it:G[v])
		{
			if(--deg[it]==0)
			{
				X.push(it);
			}
		}
	}

	if(cnt!=chce)
	{
		cout << "Draw" << endl;
		exit(0);
	}

	cout << "Lose" << endl;
}