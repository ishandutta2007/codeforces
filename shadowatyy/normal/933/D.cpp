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

#define y0 abababba
#define y1 ababbababa
#define int long long
const int MOD = 1e9+7;
const int N = 1e6+7;

int m, ans;

int y0[N];
int y1[N];
int y2[N];
int y3[N];

int pot(int a, int b)
{
	a %= MOD;
	int res = 1;

	while(b--)
		res = res*a%MOD;

	return res;
}

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

	cin >> m;

	int z = m%MOD;

	ans += z*(z+1)%MOD*(z+2)%MOD;

	for(int x = 1; x*x <= m; ++x)
	{
		int L = x*x%MOD;
		ans += 4*(2*pot(L, 3)%MOD-3*(z+2)%MOD*pot(L, 2)%MOD+(3*z+4)*L%MOD+z*(z+1)%MOD*(z+2)%MOD);
	}

	for(int y = 1; y*y <= m; ++y)
	{
		y0[y] = y0[y-1]+1;
		y1[y] = (y1[y-1]+pot(y, 2))%MOD;
		y2[y] = (y2[y-1]+pot(y, 4))%MOD;
		y3[y] = (y3[y-1]+pot(y, 6))%MOD;
	}

	int y = 1;

	while((y+1)*(y+1)<=m)
		++y;

	for(int x = 1; x*x <= m; ++x)
	{
		while(x*x+y*y>m)
			--y;

		int L0 = y0[y];
		int L1 = (pot(x, 2)*y0[y]%MOD+y1[y])%MOD;
		int L2 = (pot(x, 4)*y0[y]%MOD+2*pot(x, 2)*y1[y]%MOD+y2[y])%MOD;
		int L3 = (pot(x, 6)*y0[y]%MOD+3*pot(x, 4)*y1[y]%MOD+3*pot(x, 2)%MOD*y2[y]%MOD+y3[y])%MOD;

		ans += 4*L0%MOD*z%MOD*(z+1)%MOD*(z+2);
		ans += 4*L1%MOD*(3*z+4);
		ans += 4*L2%MOD*-3*(z+2)%MOD;
		ans += 4*L3*2%MOD;
		ans %= MOD;
	}

	ans *= fpow(6, MOD-2);
	ans %= MOD;

	cout << ans << endl;
}