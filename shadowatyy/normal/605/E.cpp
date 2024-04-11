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

const int N = 1e3+7;
const double eps = 1e-6;

int n;

double p[N][N];
double zaden[N];
double curr[N];
double ans[N];

bitset<N> vis;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			int w;
			cin >> w;
			p[i][j] = (double)w/100;
		}

		zaden[i] = 1;
	}

	for(int i = 1; i <= n-1; ++i)
	{
		ans[i] = inf;
	}

	while(vis.count()<n)
	{
		int v = -1;

		for(int i = 1; i <= n; ++i)
		{
			if(!vis[i] && (v==-1 || ans[v]>ans[i]))
				v = i;
		}

		vis[v] = 1;

		for(int i = 1; i <= n; ++i)
		{
			if(!vis[i])
			{
				curr[i] += (ans[v]+1)*p[i][v]*zaden[i];
				zaden[i] *= (1-p[i][v]);

				if(zaden[i]+eps>1)
					ans[i] = inf;
				else
					ans[i] = 1/(1-zaden[i])*(zaden[i]+curr[i]);
			}
		}
	}

	cout << fixed << setprecision(10) << ans[1];
}