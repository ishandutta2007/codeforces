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

#define M inf
#define int long long
#define N 200007

int n, m, q, t, c;

string s;

int inv[N];
int p[N];
int f[N];
int nq[N];
int mq[N];
int res[N];
int dp[N];
VI que[N];

int fpow(int a, int b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%M;

	if(b%2)
		return (a*fpow(a, b-1))%M;
	else
	{
		int q = fpow(a, b/2);
		return (q*q)%M;
	}
}

int dziel(int a, int b)
{
	return (a*fpow(b%M, M-2))%M;
}

int choose(int a, int b)
{
	return dziel(f[a], f[b]*f[a-b]);
}

void solve(int m)
{
	memset(dp, 0, sizeof dp);

	dp[m] = 1;

	int dwumian = 1;

	for(int i = m+1; i <= 1e5; ++i)
	{
		dwumian = (((dwumian*(i-1))%M)*inv[i-m])%M;
		dp[i] = (26*dp[i-1]+dwumian*p[i-m])%M;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	f[0] = 1;
	p[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		f[i] = (f[i-1]*i)%M;
		p[i] = (25*p[i-1])%M;
		inv[i] = fpow(i, M-2);
	}

	cin >> q >> s;
	m = s.size();

	for(int i = 1; i <= q; ++i)
	{
		cin >> t;

		if(t==1)
		{
			cin >> s;
			m = s.size();
		}
		else
		{
			cin >> n;
			nq[++c] = n;
			mq[c] = m;
			que[m].pb(c);
		}
	}

	for(int i = 1; i <= 1e5; ++i)
	{
		if(!que[i].empty())
			solve(i);

		for(auto it:que[i])
			res[it] = dp[nq[it]];
	}

	for(int i = 1; i <= c; ++i)
	{
		cout << res[i] << endl;
	}
}