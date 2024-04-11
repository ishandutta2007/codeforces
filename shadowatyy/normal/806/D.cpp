#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
using namespace std;

#define N 2007
#define int long long

int n, res, Min = inf;

int G[N][N];

int dist[N];

struct comp
{
	bool operator()(const int &a, const int &b)
	{
		if(dist[a]==dist[b])
			return a<b;

		return dist[a]<dist[b];
	}
};	

set<int, comp> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			cin >> G[i][j];
			G[j][i] = G[i][j];
			Min = min(Min, G[i][j]);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		dist[i] = INF;
	}

	for(int i = 1; i <= n; ++i)
	{
		G[i][i] = inf;

		for(int j = i+1; j <= n; ++j)
		{
			if(G[i][j]==Min)
			{
				dist[i] = dist[j] = (n-1)*Min;
				S.insert(i);
				S.insert(j);
			}
		}
	}

	while(!S.empty())
	{
		int v = *S.begin();
		S.erase(S.begin());

		for(int i = 1; i <= n; ++i)
		{
			if(dist[i]>dist[v]+G[v][i]-Min)
			{
				dist[i] = dist[v]+G[v][i]-Min;
				S.insert(i);
			}

			if(dist[i]>2*(G[v][i]-Min)+(n-1)*Min)
			{
				dist[i] = 2*(G[v][i]-Min)+(n-1)*Min;
				S.insert(i);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << dist[i] << endl;
	}

}