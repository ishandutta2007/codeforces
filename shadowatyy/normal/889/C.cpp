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
using namespace std;

#define int long long
const int N = 1e6+7;
const int MOD = 1e9+7;

int n, k, res;

int fact[N];
int inv[N];
int dp[N];
int pref[N];

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

int dwumian(int n, int k)
{
	return fact[n]*inv[k]%MOD*inv[n-k]%MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = 1;
	inv[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%MOD;
		inv[i] = fpow(fact[i], MOD-2);
	}

	cin >> n >> k;

	dp[1] = 1;
	pref[1] = 1;

	for(int i = 2; i <= n; ++i)
	{
		dp[i] = fact[i-2]*(pref[i-1]-pref[max(0ll, i-k-1)]+MOD)%MOD;
		pref[i] = (pref[i-1]+dp[i]*inv[i-1])%MOD;
	}

	for(int i = 1; i <= n; ++i)
	{
		res += dp[i]*dwumian(n-1, i-1)%MOD*fact[n-i]%MOD;
		res %= MOD;
	}

	cout << (fact[n]-res+MOD)%MOD;

}