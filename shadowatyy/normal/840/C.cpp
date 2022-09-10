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

const int N = 307;
const int MOD = 1e9+7;

int n, curr;

ll res = 1;

int cnt[N];

ll dp[N][N];

ll dwumian[N][N];

ll a[N];

map<ll, int> klasa;
map<ll, int> ile;

VI licznosci[N];

bool check(ll k)
{
	ll s = sqrt(k);

	return s*s==k || (s+1)*(s+1)==k || (s-1)*(s-1)==k;
}

ll silnia(ll k)
{
	if(k==0)
		return 1;

	return k*silnia(k-1)%MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		++ile[a[i]];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!klasa[a[i]])
		{
			klasa[a[i]] = ++curr;
			licznosci[curr].pb(ile[a[i]]);

			for(int j = i+1; j <= n; ++j)
			{
				if(!klasa[a[j]] && check(a[i]*a[j]))
				{
					klasa[a[j]] = curr;
					licznosci[curr].pb(ile[a[j]]);
				}
			}
		}
	}

	for(int i = 1; i <= curr; ++i)
	{
		int sum = 0;

		for(auto it:licznosci[i])
		{
			sum += it;
		}
		
		res = res*silnia(sum)%MOD;
	}

	for(int i = 1; i <= n; ++i)
	{
		++cnt[klasa[a[i]]];
	}

	for(int i = 0; i <= n; ++i)
	{
		dwumian[i][0] = 1;

		for(int j = 1; j <= i; ++j)
		{
			dwumian[i][j] = (dwumian[i-1][j]+dwumian[i-1][j-1])%MOD;
		}
	}

	dp[0][0] = 1;	

	int gaps = 1;

	for(int i = 0; i < curr; ++i)
	{	
		for(int j = 0; j <= gaps; ++j)
		{
			for(int k = 0; k <= j; ++k)
			{
				for(int l = 0; l <= gaps-j && l+k <= cnt[i+1]; ++l)
				{
					dp[i+1][j-k+cnt[i+1]-l-k] += dp[i][j]*dwumian[j][k]%MOD*dwumian[gaps-j][l]%MOD*dwumian[cnt[i+1]-1][cnt[i+1]-l-k]%MOD;
					dp[i+1][j-k+cnt[i+1]-l-k] %= MOD;
				}
			}
		}

		gaps += cnt[i+1];
	}	

	cout << res*dp[curr][0]%MOD;
}