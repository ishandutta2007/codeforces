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

int n, m, res;

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

	if(m==1)
		res += n;
	else
	{
		int q = (2*m-1)*fpow(m, MOD-2)%MOD;
		res += fpow(m, n)*(1-fpow(q, n))%MOD*fpow(1-q, MOD-2)%MOD;
	}

	res += fpow(m, n);
	res %= MOD;
	res += MOD;
	res %= MOD;

	cout << res;
}