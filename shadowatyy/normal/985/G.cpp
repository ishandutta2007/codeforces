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

typedef unsigned ll ull;
const int S = 400;
const int N = 2e5+7;

int n, m;

VI G[N];

int u[N];
int w[N];

ull ans, A, B, C;

ull sum(int a, int b)
{	
	if(a>b)
		return 0;

	if(a==0)
		++a;

	return (ull)b*(b+1)/2 - (ull)a*(a-1)/2;
}

bitset<N> edge[3*S+7];
bitset<N> curr;

int cnt = 0;
int gdzie[N];

inline void trian(int a, int b, int c)
{
	if(b>c)
		swap(b, c);

	if(a>b)
		return;

	ans -= A * a + B * b + C * c;
}

void trojkaty()
{
	for(int v = 0; v < n; ++v)
	{
		if(G[v].size()>S)
		{
			gdzie[v] = ++cnt;

			for(auto it:G[v])
				edge[cnt][it] = 1;
		}
	}

	for(int v = 0; v < n; ++v)
	{
		if(G[v].size()>S)
		{
			for(int i = 1; i <= m; ++i)
			{
				if(edge[gdzie[v]][u[i]] && edge[gdzie[v]][w[i]])
					trian(v, u[i], w[i]);
			}
		}
		else
		{
			for(int i = 0; i < G[v].size(); ++i)
			{
				if(G[G[v][i]].size()>S)
				{
					for(int j = i+1; j < G[v].size(); ++j)
					{
						if(edge[gdzie[G[v][i]]][G[v][j]])
							trian(v, G[v][i], G[v][j]);
					}
				}
				else
				{
					for(auto it:G[G[v][i]])
						curr[it] = 1;

					for(int j = i+1; j < G[v].size(); ++j)
					{
						if(curr[G[v][j]])
							trian(v, G[v][i], G[v][j]);
					}

					for(auto it:G[G[v][i]])
						curr[it] = 0;
				}
			}
		}
	}
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> A >> B >> C;

	for(int i = 1; i <= m; ++i)
	{
		cin >> u[i] >> w[i];
		G[u[i]].pb(w[i]);
		G[w[i]].pb(u[i]);
	}

	for(int i = 0; i < n; ++i)
	{
		sort(ALL(G[i]));

		ans += A * (n-i-1) * (n-i-2) / 2 * i;
		ans += B * i * (n-i-1) * i;
		ans += C * i * (i-1) / 2 * i;

		ull l = 0, u = 0, sl = 0, su = 0, kl = 0, ku = 0;

		for(auto it:G[i])
		{
			if(it<i)
			{
				ans -= (A*it + B*i) * (n-i-1) + C * sum(i+1, n-1); //1
				++l;
				sl += it;
				kl += (ull)it*it;
			}
			else
			{
				ans -= (C*it + B*i) * i + A * sum(0, i-1); //2
				++u;
				su += it;
				ku += (ull)it*it;
				ans -= A * i * (it-i-1) + C * it * (it-i-1) + B * sum(i+1, it-1); //4 
			}
		}

		ans += A * sl * u + B * i * u * l + C * su * l; //3

		//5

		ans += C * i * l * (l-1) / 2;

		int cnt = 0;

		for(auto it:G[i])
		{
			if(it<i)
			{
				ans += A * it * (l-cnt-1);
				ans += B * it * cnt;
				++cnt;
			}
		}

		//6

		ans += A * i * u * (u-1) / 2;
		
		cnt = 0;

		for(auto it:G[i])
		{
			if(it>i)
			{
				ans += B * it * (u-cnt-1);
				ans += C * it * cnt;
				++cnt;
			}
		}
	}

	//7

	trojkaty();

	cout << ans << endl;
}