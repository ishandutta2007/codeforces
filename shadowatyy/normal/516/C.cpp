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

#define N 200007
#define M (1<<18)

int n, m;

ll sum;

ll d[N];
ll h[N];

ll pref[N];
ll suf[N];

pair<ll, int> t[2][2*M];

void insert(int i, int a, ll v)
{
	a += M;
	t[i][a] = mp(v, a-M);
	a /= 2;

	while(a>=1)
	{
		t[i][a] = max(t[i][a*2], t[i][a*2+1]);
		a /= 2;
	}
}

pair<ll, int> query(int i, int a, int b)
{
	a += M;
	b += M;

	pair<ll, int> res = max(t[i][a], t[i][b]);

	while(a<b-1)
	{
		if(a%2==0)
			res = max(res, t[i][a+1]);

		if(b%2==1)
			res = max(res, t[i][b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> d[i];
		d[i+n] = d[i];
		sum += 2*d[i];
	}

	sum -= d[n];

	for(int i = 1; i <= n; ++i)
	{
		cin >> h[i];
		h[i] *= 2;
		h[i+n] = h[i];
	}

	for(int i = 2; i <= 2*n; ++i)
	{
		pref[i] = pref[i-1]+d[i-1];
	}

	for(int i = 2*n-1; i >= 1; --i)
	{	
		suf[i] = suf[i+1]+d[i];
	}

	for(int i = 1; i <= 2*n; ++i)
	{
		insert(0, i, h[i]-pref[i]);
		insert(1, i, h[i]-suf[i]);
	}

	while(m--)
	{
		int a, b, l, r;

		ll res = -INF;

		cin >> a >> b;

		if(a<=b)
			l = b+1, r = n+a-1;
		else
			l = b+1, r = a-1;

		auto q1 = query(0, l, r);
		insert(1, q1.nd, -INF);
		auto q2 = query(1, l, r);
		res = max(res, q1.st+q2.st+sum);
		insert(1, q1.nd, h[q1.nd]-suf[q1.nd]);

		q2 = query(1, l, r);
		insert(0, q2.nd, -INF);
		q1 = query(0, l, r);
		res = max(res, q1.st+q2.st+sum);
		insert(0, q2.nd, h[q2.nd]-pref[q2.nd]);

		cout << res << endl;
	}
}