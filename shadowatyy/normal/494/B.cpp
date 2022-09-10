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

#define int long long
#define N 200007
#define MOD inf
#define M (1<<17)

int n, m;

ll ans;

string s, t, k;

int kmp[N];
int wyst[N];
int lewo[N];
ll dp[N];
ll przekaz[N];
ll sum[N];

ll load[2*M];

void insert(int a, ll v)
{	
	load[a+M] = ((n-a+1)*v)%MOD;
	a += M;
	a /= 2;

	while(a>=1)
	{
		load[a] = (load[2*a]+load[2*a+1])%MOD;
		a /= 2;
	}
}

ll query(int a, int b)
{
	if(a>b)
		return 0;

	a += M;
	b += M;

	ll res = 0;

	res += load[a];

	if(a!=b)
		res += load[b];

	while(a<b-1)
	{
		if(a%2==0)
			res += load[a+1];
		
		if(b%2==1)
			res += load[b-1];

		a /= 2;
		b /= 2;
	}

	return res%MOD;
}

ll suma(int a, int b)
{
	if(a>b)
		return 0;

	return (sum[b]-sum[a-1]+MOD)%MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s >> t;

	n = s.size();
	m = t.size();

	k = '#'+t+'$'+s;

	int q = 0;

	for(int i = 2; i <= n+m+1; ++i)
	{
		while(q>0 && k[i]!=k[q+1])
			q = kmp[q];

		if(k[i]==k[q+1])
			++q;

		kmp[i] = q;

		if(kmp[i]==m)
			wyst[i-m-1] = 1;
	}

	lewo[0] = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(wyst[i])
			lewo[i] = i;
		else
			lewo[i] = lewo[i-1];
	}

	dp[0] = 1;
	sum[0] = 1;
	przekaz[1] = dp[0];
	insert(0, dp[0]);

	for(int i = 1; i <= n; ++i)
	{
		dp[i] = przekaz[i];
		dp[i] -= (query(max(lewo[i]-SIZE(t), -1ll)+1, i-1)-suma(max(lewo[i]-SIZE(t), -1ll)+1, i-1)*(n-(i-1)))%MOD;
		dp[i] -= (sum[lewo[i]-SIZE(t)]*(i-lewo[i]+SIZE(t)-1))%MOD;
		dp[i] %= MOD;
		dp[i] += MOD;
		dp[i] %= MOD;

		sum[i] = (sum[i-1]+dp[i])%MOD;
		przekaz[i+1] = (przekaz[i]+sum[i])%MOD;
		insert(i, dp[i]);
	}

	for(int i = 1; i <= n; ++i)
		ans += dp[i];

	cout << ans%MOD;
}