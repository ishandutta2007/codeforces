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

#define N 3007

int n, m, a, b, res, A, B, C, D, curr;

VI G[N], T[N];

int dist[N][N];
int distT[N][N];

VI kand[N];
VI kandT[N];

bitset<N> vis;

queue<int> Q;

bool comp(int a, int b)
{
	return dist[curr][a]>dist[curr][b]; 
}

bool compT(int a, int b)
{
	return distT[curr][a]>distT[curr][b]; 
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	while(m--)
	{
		cin >> a >> b;
		G[a].pb(b);
		T[b].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		vis.reset();
		Q.push(i);
		vis[i] = 1;

		while(!Q.empty())
		{
			int v = Q.front();
			Q.pop();

			for(auto it:G[v])
			{
				if(!vis[it])
				{
					dist[i][it] = dist[i][v]+1;
					Q.push(it);
					vis[it] = 1;
				}
			}
		}

		for(int j = 1; j <= n; ++j)
		{
			if(!vis[j])
				dist[i][j] = -inf/3;

			kand[i].pb(j);
		}

		curr = i;
		sort(ALL(kand[i]), comp);

		vis.reset();
		Q.push(i);
		vis[i] = 1;

		while(!Q.empty())
		{
			int v = Q.front();
			Q.pop();

			for(auto it:T[v])
			{
				if(!vis[it])
				{
					distT[i][it] = distT[i][v]+1;
					Q.push(it);
					vis[it] = 1;
				}
			}
		}

		for(int j = 1; j <= n; ++j)
		{
			if(!vis[j])
				distT[i][j] = -inf/3;

			kandT[i].pb(j);
		}

		curr = i;
		sort(ALL(kandT[i]), compT);
	}

	for(int b = 1; b <= n; ++b)
	{
		for(int c = 1; c <= n; ++c)
		{
			int a = 0, d = 0;

			for(auto it:kandT[b])
			{
				if(it!=b && it!=c)
				{
					a = it;
					break;
				}
			}

			for(auto it:kand[c])
			{
				if(it!=b && it!=c && it!=a)
				{
					d = it;
					break;
				}
			}

			if(a && b && c && d && a!=b && a!=c && a!=d && b!=c && b!=d && c!=d && dist[a][b]+dist[b][c]+dist[c][d]>res)
			{
				res = dist[a][b]+dist[b][c]+dist[c][d];
				A = a;
				B = b;
				C = c;
				D = d;
			}

			a = 0, d = 0;

			for(auto it:kand[c])
			{
				if(it!=b && it!=c)
				{
					d = it;
					break;
				}
			}

			for(auto it:kandT[b])
			{
				if(it!=b && it!=c && it!=d)
				{
					a = it;
					break;
				}
			}

			if(a && b && c && d && a!=b && a!=c && a!=d && b!=c && b!=d && c!=d && dist[a][b]+dist[b][c]+dist[c][d]>res)
			{
				res = dist[a][b]+dist[b][c]+dist[c][d];
				A = a;
				B = b;
				C = c;
				D = d;
			}
		}	
	}

	//cout << res;
	cout << A << " " << B << " " << C << " " << D;
}