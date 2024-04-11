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

#define N 1007
#define abs(a) ((a)>-(a)?(a):-(a))

int n;

long double res = (long double)10*inf;

long double x[N];
long double y[N];

long double dist(int a, int b, int c)
{
	return abs((y[b]-y[a])*x[c]-(x[b]-x[a])*y[c]+x[b]*y[a]-y[b]*x[a])/sqrt((y[b]-y[a])*(y[b]-y[a])+(x[b]-x[a])*(x[b]-x[a]));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; ++i)
	{
		res = min(res, dist(i, (i+2)%n, (i+1)%n)/2);
	}

	cout << setprecision(10) << fixed << res;
}