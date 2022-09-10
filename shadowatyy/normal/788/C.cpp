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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 1007

int n, k, a;

bitset<2*N> e, vis;

queue<int> Q;

int dist[2*N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= k; ++i)
	{
		cin >> a;

		e[a-n+N] = 1;
	}

	for(int i = -1000; i <= 1000; ++i)
	{
		dist[i+N] = inf;
	}

	dist[0+N] = 0;
	vis[0+N] = 1;
	Q.push(0);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(int i = -1000; i <= 1000; ++i)
		{
			if(-1000<=v+i && v+i<=1000 && e[i+N])
			{
				if(!vis[v+i+N])
				{
					dist[v+i+N] = dist[v+N]+1;
					vis[v+i+N] = 1;
					Q.push(v+i);
				}
				else if(v+i==0)
				{
					cout << dist[v+N]+1;
					return 0;
				}
			}
		}
	}

	cout << -1;
}