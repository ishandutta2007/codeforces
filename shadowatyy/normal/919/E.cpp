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
const int P = 1e6+7;

int a, b, p, x, ans;

int lg[P];

int fpow(int a, int b)
{
	int res = 1;

	for(int i = 0; i < 20; ++i)
	{
		if(b&(1<<i))
		{
			res *= a;
			res %= p;
		}

		a *= a;
		a %= p;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> a >> b >> p >> x;

	int curr = a;

	for(int i = 1; i < p; ++i)
	{
		if(!lg[curr])
			lg[curr] = i;

		curr *= a;
		curr %= p;
	}

	for(int q = 1; q < p; ++q)
	{
		int R = b*fpow(q, p-2)%p;

		if(!lg[R])
			continue;

		int n = lg[R];
		int t = (q-n+p)%p*fpow(lg[1], p-2)%p;
		n += lg[1]*t;

		if(n<=x)
		{
			++ans;
			ans += (x-n)/(lg[1]*p/__gcd(lg[1], p));
		}
	}

	cout << ans;
}