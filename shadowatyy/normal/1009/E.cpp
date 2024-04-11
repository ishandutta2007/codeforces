#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

#define int ll
const int mod = 998244353;
const int N = 1e6+7;

int n, sum;

int a[N];
int dp[N];
int kek[N];

int fpow(int a, int b)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = res*a%mod;
		
		b /= 2;
		a = a*a%mod;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] += a[i-1];
		a[i] %= mod;
		kek[i] = a[i]*fpow((mod+1)/2, i)%mod;
		kek[i] += kek[i-1];
		kek[i] %= mod;
	}

	int sum = 0;

	for(int i = 1; i <= n-1; ++i)
	{
		dp[i] = sum;
		dp[i] += a[i];
		dp[i] %= mod;
		dp[i] += kek[i-1]*fpow(2, i-1)%mod;
		dp[i] %= mod;
		sum += dp[i];
		sum %= mod;
	}

	int ans = sum;

	for(int i = 0; i <= n-1; ++i)
	{
		ans += fpow(2, max(0ll, i-1))*a[n-i]%mod;
		ans %= mod;
	}

	cout << ans << endl;
}