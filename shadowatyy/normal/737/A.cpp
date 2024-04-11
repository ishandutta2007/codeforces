#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000LL
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 200007

ll n, k, s, t, m;

ll c[N];
ll v[N];

ll p[N];

vector<int> cars;

ll licz(ll a)
{
	ll res = 2*a, b = m;

	b -= a;

	if(b<0)
		return 10*inf;

	res -= b;

	return max(res, a);
}

bool bs()
{
	ll czas = 0;

	for(int i = 0; i <= k; ++i)
	{
		czas += licz(p[i+1]-p[i]);
	}

	return czas<=t;
}

bool comp(int a, int b)
{
	return c[a]<c[b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> s >> t;

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i] >> v[i];

		cars.pb(i);
	}

	for(int i = 1; i <= k; ++i)
	{
		cin >> p[i];
	}

	sort(p+1, p+1+k);

	p[k+1] = s;

	ll l = 0, r = 2*inf;

	while(l<r)
	{
		m = (l+r)/2;

		if(r==m)
			--m;

		if(bs())
			r = m;
		else
			l = m+1;
	}

	sort(cars.begin(), cars.end(), comp);

	for(int i = 0; i < n; ++i)
	{
		if(v[cars[i]]>=l)
		{
			cout << c[cars[i]];
			return 0;
		}
	}

	cout << -1;
}