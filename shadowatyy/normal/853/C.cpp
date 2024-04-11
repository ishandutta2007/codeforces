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
#define SIZE(x) (int)(x).size()
using namespace std;

const int N = 2e5+7;

int n, q;

int y[N];
int x[N];

int p[N];

int l[N];
int r[N];
int u[N];
int d[N];

ll ans[N];

int fen[N];

VI kiedy[N];

void add(int a)
{
	while(a<=n)
	{
		++fen[a];
		a += a&-a;
	}
}

int que(int a, int b)
{
	int res = 0;
	--a;

	while(a)
	{
		res -= fen[a];
		a -= a&-a;
	}

	while(b)
	{
		res += fen[b];
		b -= b&-b;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		x[i] = i;
		y[i] = p[i];
	}

	for(int i = 1; i <= q; ++i)
	{
		cin >> l[i] >> d[i] >> r[i] >> u[i];
		ans[i] = (ll)n*(n-1)/2;
		ans[i] -= (ll)(l[i]-1)*(l[i]-2)/2;
		ans[i] -= (ll)(n-r[i])*(n-r[i]-1)/2;
		ans[i] -= (ll)(d[i]-1)*(d[i]-2)/2;
		ans[i] -= (ll)(n-u[i])*(n-u[i]-1)/2;
	}

	for(int i = 1; i <= q; ++i)
	{
		kiedy[l[i]].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:kiedy[i])
		{
			ll q = que(1, d[it]-1);
			ans[it] += q*(q-1)/2;
			q = que(u[it]+1, n);
			ans[it] += q*(q-1)/2;
		}

		add(p[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		kiedy[i].clear();
	}

	memset(fen, 0, sizeof fen);

	for(int i = 1; i <= q; ++i)
	{
		kiedy[r[i]].pb(i);
	}

	for(int i = n; i >= 1; --i)
	{
		for(auto it:kiedy[i])
		{
			ll q = que(1, d[it]-1);
			ans[it] += q*(q-1)/2;
			q = que(u[it]+1, n);
			ans[it] += q*(q-1)/2;
		}

		add(p[i]);
	}

	for(int i = 1; i <= q; ++i)
	{
		cout << ans[i] << endl;
	}
}