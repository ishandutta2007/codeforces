#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
using namespace std;

#define N 100007
#define int long long
#define double long double	

int n, A, p;

int a[N], b[N];

bool check(double k)
{
	double d = 0;

	for(int i = 1; i <= n; ++i)
	{
		d += max((double)0, k*a[i]-b[i]);
	}

	return d<=k*p;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> p;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		A += a[i];
	}

	if(A<=p)
	{
		cout << -1;
		return 0;
	}

	double l = 0, r = 1e18;

	for(int i = 1; i <= 100; ++i)
	{
		double m = (l+r)/2;

		if(check(m))
			l = m;
		else
			r = m;
	}

	cout << setprecision(10) << fixed << l;
}