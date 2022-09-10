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

#define int long long
const int MOD = 1e9+7;
const int N = 1e5+7;

int n, m, ans;

int a[N];
int b[N];
int p[N];

int fpow(int a, int b)
{
	int res = 1;

	for(int i = 0; i < 30; ++i)
	{
		if(b&(1<<i))
			res = res*a%MOD;

		a = a*a%MOD;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(!a[i])
			++p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];

		if(!b[i])
			++p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		p[i] += p[i-1];
	}

	int curr = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(!a[i] && b[i])
		{
			ans += curr*(m-b[i])%MOD*fpow(m, p[n]-p[i])%MOD;
			ans %= MOD;
		}
		else if(a[i] && !b[i])
		{
			ans += curr*(a[i]-1)%MOD*fpow(m, p[n]-p[i])%MOD;
			ans %= MOD;
		}
		else if(a[i] && b[i])
		{
			if(a[i]>b[i])
			{
				ans += curr*fpow(m, p[n]-p[i])%MOD;
				ans %= MOD;
			}
		
			if(a[i]!=b[i])
				curr = 0;
		}
		else if(!a[i] && !b[i])
		{
			ans += curr*(m*(m-1)/2%MOD)%MOD*fpow(m, p[n]-p[i])%MOD;
			ans %= MOD;
			curr *= m;
			curr %= MOD;
		}
	}

	cout << (ans*fpow(fpow(m, p[n]), MOD-2))%MOD << endl;
}