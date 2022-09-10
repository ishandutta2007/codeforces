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

const int N = 1e6+7;
const int MOD = 1e9+7;

int n, a;

ll ans;

ll ile[N];
ll dzieli[N];
ll pot[N];
ll res[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	pot[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		pot[i] = 2*pot[i-1]%MOD;
	}

	cin >> n;

	while(n--)
	{
		cin >> a;
		++ile[a];
	}

	for(int i = 1; i < N; ++i)
	{
		for(int j = i; j < N; j += i)
			dzieli[i] += ile[j];
	}

	for(int i = 1; i < N; ++i)
	{
		if(dzieli[i])
			res[i] = dzieli[i]*pot[dzieli[i]-1]%MOD;
	}

	for(int i = N-1; i >= 1; --i)
	{
		for(int j = 2*i; j < N; j += i)
			res[i] -= res[j];

		res[i] %= MOD;
		res[i] += MOD;
		res[i] %= MOD;
	}

	for(int i = 2; i < N; ++i)
	{
		ans += i*res[i];
		ans %= MOD;
	}

	cout << ans;
}