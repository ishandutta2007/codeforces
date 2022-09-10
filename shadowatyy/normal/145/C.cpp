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

#define N 100007
#define M 1107
#define MOD 1000000007

int n, k, m, s;

ll res;

int a[N];
int ile[M];
ll dp[M][M];
ll fact[N];
ll inv[N];

map<int, int> cnt;

ll fpow(ll a, int b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%MOD;

	if(b%2)
		return a*fpow(a, b-1)%MOD;
	else
	{
		ll q = fpow(a, b/2);
		return q*q%MOD;
	}
}

ll dwumian(int n, int k)
{
	if(k>n)
		return 0;

	if(k<0)
		return 0;

	return fact[n]*inv[n-k]%MOD*inv[k]%MOD;
}

bool ciekawa(int a)
{
	while(a)
	{
		if(a%10!=4 && a%10!=7)
			return 0;

		a /= 10;
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = inv[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%MOD;
		inv[i] = fpow(fact[i], MOD-2);
	}

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(ciekawa(a[i]))
			++cnt[a[i]];
	}

	for(auto it:cnt)
	{
		ile[++m] = it.nd;
		s += it.nd;
	}

	dp[0][0] = 1;

	for(int i = 1; i <= m; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			dp[i][j] = dp[i-1][j];

			if(j>0)
				dp[i][j] += dp[i-1][j-1]*ile[i];

			dp[i][j] %= MOD;
		}
	}

	for(int i = 0; i <= m; ++i)
	{
		res += dp[m][i]*dwumian(n-s, k-i);
		res %= MOD;
	}

	cout << res;
}