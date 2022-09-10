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

#define N 4007
#define K 807

#define getchar_unlocked getchar
#define putchar_unlocked putchar

int n, k;

int a[N][N];

int c[N][N];

int dp[K][N];

void dq(int p, int a, int b, int l, int r)
{
	int m = (a+b)/2, op = -1;

	for(int i = l; i <= min(m, r); ++i)
	{
		if(dp[p][m]>dp[p-1][i-1]+c[i][m])
		{
			op = i;
			dp[p][m] = dp[p-1][i-1]+c[i][m];
		}
	}

	if(a<=m-1)
		dq(p, a, m-1, l, op);

	if(m+1<=b)
		dq(p, m+1, b, op, r);
}

inline int read()
{
	register char buff[10];
	register int f = 1;
	register int w = 1;
	register int res = 0;

	buff[f] = getchar_unlocked();

	while(buff[f]<='9' && buff[f]>='0')
	{
		buff[++f] = getchar_unlocked();
	}

	--f;

	while(f)
	{
		res += (buff[f--]-'0')*w;
		w *= 10;
	}

	return res;
}

inline void write(int a)
{
	if(!a)
	{
		putchar_unlocked('0');
		return;
	}

	register char buff[17];
	register int f = 0;

	while(a)
	{
		buff[++f] = a%10+48;
		a /= 10;
	}

	while(f)
	{
		putchar_unlocked(buff[f--]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	n = read();
	k = read();

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			a[i][j] = read();
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			a[i][j] += a[i-1][j];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			a[i][j] += a[i][j-1];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			c[i][j] = (a[j][j]+a[i-1][i-1]-a[i-1][j]-a[j][i-1])/2;
		}
	}

	for(int i = 0; i <= k; ++i)
	{
		fill(dp[i]+1, dp[i]+N, inf);
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[1][i] = c[1][i];
	}

	for(int i = 2; i <= k; ++i)
	{
		dq(i, 1, n, 1, n);
	}

	write(dp[k][n]);
}