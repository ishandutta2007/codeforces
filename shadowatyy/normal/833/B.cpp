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

#define N 35007
#define K 57
#define M (1<<16)

int n, k;

int a[N];

int lewo[N];
int last[N];

int dp[K][N];

int sub[2*M];
int load[2*M];

void insert(int a, int b, int c, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || a>r || l>b)
		return;

	if(a<=l && r<=b)
	{
		sub[v] += c;
		load[v] += c;
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = load[v]+max(sub[2*v], sub[2*v+1]);
}

int query(int a, int b, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || a>r || l>b)
		return -inf;

	if(a<=l && r<=b)
		return sub[v];

	int res = load[v]+max(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r));
	sub[v] = load[v]+max(sub[2*v], sub[2*v+1]);
	return res;
}	

void build(int l)
{
	for(int i = 0; i < 2*M; ++i)
	{
		load[i] = 0;
		sub[i] = -inf;
	}

	for(int i = 0; i <= n; ++i)
	{
		sub[i+M] = dp[l][i];
	}

	for(int i = M-1; i >= 1; --i)
	{
		sub[i] = max(sub[2*i], sub[2*i+1]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		lewo[i] = last[a[i]];
		last[a[i]] = i;
	}

	for(int i = 0; i <= k; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			dp[i][j] = -inf;
		}
	}

	dp[0][0] = 0;

	for(int l = 1; l <= k; ++l)
	{	
		build(l-1);

		for(int i = 1; i <= n; ++i)
		{
			insert(lewo[i], i-1, 1);
			dp[l][i] = query(0, i-1);
		}
	}

	cout << dp[k][n];
}