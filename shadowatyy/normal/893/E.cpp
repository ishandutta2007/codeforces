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

const int N = 2e6+7;
const int MOD = 1e9+7;

int q, x, y;

int sito[N];
ll fact[N];
ll inv[N];
ll dp[2][N];

ll dwumian(int n, int k)
{
	return fact[n]*inv[k]%MOD*inv[n-k]%MOD;
}

ll fpow(ll a, int b)
{
	ll res = 1;

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

	for(int i = 2; i < N; ++i)
	{
		if(!sito[i])
		{
			for(int j = i; j < N; j += i)
			{
				sito[j] = i;
			}
		}
	}

	fact[0] = inv[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%MOD;
		inv[i] = fpow(fact[i], MOD-2);
	}

	dp[0][0] = 1;

	for(int i = 1; i < N; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			dp[j][i] = (dp[j^1][i-1]+dp[j][i-1])%MOD;
		}
	}

	cin >> q;

	while(q--)
	{
		cin >> x >> y;

		ll res = dp[0][y];

		while(x>1)
		{
			int curr = sito[x], cnt = 0;

			while(x%curr==0)
			{
				++cnt;
				x /= curr;
			}

			res *= dwumian(cnt+y-1, cnt);
			res %= MOD;
		}

		cout << res << endl;
	}
}