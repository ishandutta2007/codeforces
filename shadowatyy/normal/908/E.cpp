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
const int N = 1007;

int m, n;

string s[57];

int bino[N][N];
int bell[N];

map<ll, int> cnt;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 0; i < N; ++i)
	{
		bino[i][0] = 1;
	}

	for(int i = 1; i < N; ++i)
	{
		for(int j = 1; j < N; ++j)
		{
			bino[i][j] = (bino[i-1][j-1]+bino[i-1][j])%MOD;
		}
	}

	bell[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			bell[i] += bell[i-j]*bino[i-1][j-1]%MOD;
			bell[i] %= MOD;
		}
	}

	cin >> m >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}	

	for(int j = 0; j < m; ++j)
	{
		ll mask = 0;

		for(int i = 0; i < n; ++i)
		{
			if(s[i][j]=='1')
				mask |= (1ll<<i);
		}

		++cnt[mask];
	}

	ll ans = 1;

	for(auto it:cnt)
	{
		ans *= bell[it.nd];
		ans %= MOD;
	}

	cout << ans;
}