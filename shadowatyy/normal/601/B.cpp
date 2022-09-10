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

#define N 100007

int n, q;

int a[N];
int t[N];
int lewo[N];
int prawo[N];

ll query(int l, int r)
{
	memset(t, 0, sizeof t);

	int d = r-l+1;

	for(int i = 1; i < d; ++i)
	{
		t[i] = abs(a[l+i-1]-a[l+i]);
	}

	lewo[1] = 0;

	for(int i = 2; i < d; ++i)
	{
		int j = i-1;

		while(j>0 && mp(t[i], i)>mp(t[j], j))
			j = lewo[j];

		lewo[i] = j;
	}

	prawo[d-1] = d;

	for(int i = d-2; i >= 1; --i)
	{
		int j = i+1;

		while(j<d && mp(t[i], i)>mp(t[j], j))
			j = prawo[j];

		prawo[i] = j; 
	}

	ll res = 0;

	for(int i = 1; i <= n; ++i)
	{
		int p = lewo[i]+1, q = prawo[i];

		if(p!=q)
			res += (ll)t[i]*(i-p+1)*(q-i);
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
		cin >> a[i];
	}

	while(q--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}