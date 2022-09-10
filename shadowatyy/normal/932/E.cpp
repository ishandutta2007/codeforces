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
const int N = 5007;
const int mod = 1e9+7;

int n, k;

int ile[N][N];

int fpow(int a, int b)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = res*a%mod;

		a = a*a%mod;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	ile[0][0] = 1;

	for(int i = 0; i <= k; ++i)
	{
		for(int j = 0; j <= k; ++j)
		{
			ile[i+1][j] += ile[i][j]*j%mod;
			ile[i+1][j] %= mod;

			ile[i+1][j+1] += ile[i][j]*(n-j)%mod;
			ile[i+1][j+1] %= mod;
		}
	}

	int ans = 0;

	for(int r = 1; r <= k; ++r)
	{
		ans += fpow(2, n-r)*ile[k][r]%mod;
		ans %= mod;
	}

	cout << ans << endl;
}