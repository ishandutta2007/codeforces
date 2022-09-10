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

#define int long long
#define double long double

#define N 100007

int n, k, res, Min = inf;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		Min = min(Min, a[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		if((a[i]-Min)%k!=0)
		{
			cout << -1;
			return 0;
		}

		res += (a[i]-Min)/k;
	}

	cout << res;
}