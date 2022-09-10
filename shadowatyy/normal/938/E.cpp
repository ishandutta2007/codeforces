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
const int N = 1e6+7;

int n, f = 1, ans;

int a[N];

map<int, int, greater<int> > M;

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

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		++M[x];
		f *= i;
		f %= MOD;
	}

	int cnt = 0;

	for(auto it:M)
	{
		ans += it.st*f%MOD*it.nd%MOD*fpow(cnt+it.nd, MOD-2)%MOD;
		ans %= MOD;
		cnt += it.nd;
	}

	ans -= f*(*M.begin()).st%MOD;
	ans += MOD;
	ans %= MOD;

	cout << ans << endl;
}