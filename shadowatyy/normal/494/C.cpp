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

#define Q 5007
#define N 100007
#define L 18

int n, q;

int T[L][N];

int A[N];
int B[N];
double P[N];
double dp[Q][Q];
double curr[Q][Q];
int sub[Q];
bitset<N> vis;

VI seg;

VI G[N];

int query(int a, int b)
{
	int l = 31-__builtin_clz(b-a+1);
	return max(T[l][a], T[l][b-(1<<l)+1]);
}

bool comp(int a, int b)
{
	return B[a]-A[a]<B[b]-A[b];
}

double get(int v, int i)
{
	if(i-sub[v]<0)
		return 0;

	if(i-sub[v]>q)
		return 1;

	return dp[v][i-sub[v]];
}

void dfs(int v)
{
	if(G[v].empty())
	{
		dp[v][0] = (1-P[v]);

		for(int i = 1; i <= q; ++i)
			dp[v][i] = 1;

		return;
	}

	for(int i = 1; i <= q; ++i)
		curr[v][i] = P[v];

	for(auto it:G[v])
	{
		dfs(it);

		for(int i = 0; i <= q; ++i)
		{
			curr[v][i] *= get(it, sub[v]+i-1);
		}
	}

	for(int i = 0; i <= q; ++i)
	{
		dp[v][i] += curr[v][i];
		curr[v][i] = (1-P[v]);
	}
	
	for(auto it:G[v])
	{
		for(int i = 0; i <= q; ++i)
		{
			curr[v][i] *= get(it, sub[v]+i);
		}
	}	

	for(int i = 0; i <= q; ++i)
	{
		dp[v][i] += curr[v][i];
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> T[0][i];
	}

	for(int l = 1; l < L; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(i+(1<<(l-1))<=n)
				T[l][i] = max(T[l-1][i], T[l-1][i+(1<<(l-1))]);
		}
	}

	for(int i = 1; i <= q; ++i)
	{
		cin >> A[i] >> B[i] >> P[i];
		seg.pb(i);
	}

	sort(ALL(seg), comp);

 	seg.pb(++q);
	A[q] = 1;
	B[q] = n;
	P[q] = 0; 

	for(int i = 0; i < q; ++i)
	{
		for(int j = i-1; j >= 0; --j)
		{
			if(!vis[seg[j]] && A[seg[i]]<=A[seg[j]] && B[seg[j]]<=B[seg[i]])
			{
				vis[seg[j]] = 1;
				G[seg[i]].pb(seg[j]);
			}
		}
	}

	for(int i = 1; i <= q; ++i)
	{
		sub[i] = query(A[i], B[i]);
	}

	dfs(q);

	double ans = 0;

	for(int i = 0; i <= q; ++i)
	{
		if(i>0)
			ans += (dp[q][i]-dp[q][i-1])*(sub[q]+i);
		else
			ans += dp[q][i]*(sub[q]+i);
	}

	cout << setprecision(10) << fixed << ans;
}