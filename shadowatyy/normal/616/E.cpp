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
#define flush fflush(stdout)
using namespace std;

#define int long long
#define M 1000000007

int n, m, res, last;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i*i <= n; ++i)
	{
		if(i<=m)
			res -= (n/i%M*i)%M;

		last = n/i;
	}

	res *= 2;

	for(int k = 1; k < last; ++k)
	{
		int l = n/(k+1)+1, r = min(n/k, m);

		if(l<=r)
		{
			l %= M;
			r %= M;

			res -= (k%M*((r*(r+1))%M))%M;
			res += (k%M*((l*(l-1))%M))%M;
		}		
	}

	if(res%2)
		res += M;

	res /= 2;
	res += (n%M)*(m%M)%M;
	res = (res%M+M)%M;

	cout << res;
}