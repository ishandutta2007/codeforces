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

const int N = 1e5+7;

int n, m, q;

int a[N];
int b[N];

VLL val;

ll curr, res;

ll Abs(ll a)
{
	return max(a, -a);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> b[i];
	}

	ll A = 0, B = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(i%2)
		{
			A += a[i];
			B -= b[i];
		}
		else
		{
			A -= a[i];
			B += b[i];
		}
	}

	val.pb(A+B);

	for(int j = 1; j <= m-n; ++j)
	{
		B += b[j];
		B *= -1;

		if(n%2)
			B -= b[n+j];
		else
			B += b[n+j];

		val.pb(A+B);
	}

	sort(ALL(val));

	auto it = lower_bound(ALL(val), -curr);

	if(it==val.end())
		res = Abs(*prev(it)+curr);
	else if(it==val.begin())
		res = Abs(*it+curr);
	else
		res = min(Abs(*prev(it)+curr), Abs(*it+curr));

	cout << res << endl;

	while(q--)
	{
		int l, r, v;
		cin >> l >> r >> v;

		if(l%2==r%2)
		{
			if(l%2)
				curr += v;
			else
				curr -= v;
		}

		auto it = lower_bound(ALL(val), -curr);

		if(it==val.end())
			res = Abs(*prev(it)+curr);
		else if(it==val.begin())
			res = Abs(*it+curr);
		else
			res = min(Abs(*prev(it)+curr), Abs(*it+curr));

		cout << res << endl;
	}
}