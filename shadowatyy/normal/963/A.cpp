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
const int MOD = 1e9+9;

int n, a, b, k;

string s;

int fpow(int a, int b)
{
	int res = 1;

	for(int i = 0; i < 30; ++i)
	{
		if(b&(1<<i))
		{
			res *= a;
			res %= MOD;
		}

		a *= a;
		a %= MOD;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b >> k >> s;

	int cA = fpow(a, n);
	int cB = 1;

	int f = 0;

	for(int i = 0; i < k; ++i)
	{	
		if(s[i]=='+')
			f += cA*cB%MOD;
		else
			f -= cA*cB%MOD;

		f %= MOD;

		cA *= fpow(a, MOD-2);
		cA %= MOD;
		cB *= b;
		cB %= MOD;
	}

	int q = fpow(b, k)*fpow(fpow(a, MOD-2), k)%MOD;

	if(q==1)
	{
		int ans = f*((n+1)/k)%MOD;

		ans %= MOD;
		ans += MOD;
		ans %= MOD;

		cout << ans << endl;
		return 0;
	}

	int ans = f*(1-fpow(q, (n+1)/k))%MOD*fpow(1-q, MOD-2)%MOD;

	ans %= MOD;
	ans += MOD;
	ans %= MOD;

	cout << ans << endl;
}