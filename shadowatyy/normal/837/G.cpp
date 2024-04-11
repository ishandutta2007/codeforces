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

#define y1 abacabadabacaba
#define N 75007
#define A 200007
#define M (1<<17)
#define S 200

int n, m;

ll ans;

int x1[N];
int x2[N];
int y1[N];
int y2[N];
int a[N];
int b[N];

ll res[A][N/S+7];
ll curr[N];
ll load[N/S+7];

vector<pair<int, PII> > q;

void insert(int a, int v)
{
	load[(a+S-1)/S] -= curr[a];
	curr[a] = v;
	load[(a+S-1)/S] += curr[a];
}

ll query(int l, int r, int x)
{
	ll rst = 0;

	for(int i = l; i <= r; ++i)
	{
		if(i%S==1 && i+S-1<=r)
		{
			rst += res[x][(i+S-1)/S];
			i += S-1;
			continue;
		}

		if(x<=x1[i])
			rst += y1[i];
		else if(x1[i]<x && x<=x2[i])
			rst += (ll)x*a[i]+b[i];
		else
			rst += y2[i];
	}

	return rst;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x1[i] >> x2[i] >> y1[i] >> a[i] >> b[i] >> y2[i];

		q.eb(0, mp(i, y1[i]));
		q.eb(x1[i]+1, mp(i, b[i]));
		q.eb(x2[i]+1, mp(i, y2[i]));
	}

	sort(ALL(q));

	int k = -1;

	for(int i = 0; i < A; ++i)
	{
		while(k+1<q.size() && q[k+1].st==i)
		{
			++k;
			insert(q[k].nd.st, q[k].nd.nd);
		}

		for(int j = 1; j <= (n+S-1)/S; ++j)
		{
			res[i][j] = load[j];
		}
	}

	for(int j = 1; j <= (n+S-1)/S; ++j)
	{
		load[j] = 0;
	}

	q.clear();
	memset(curr, 0, sizeof curr);

	for(int i = 1; i <= n; ++i)
	{
		q.eb(x1[i]+1, mp(i, a[i]));
		q.eb(x2[i]+1, mp(i, 0));
	}

	sort(ALL(q));

	k = -1;

	for(int i = 0; i < A; ++i)
	{
		while(k+1<q.size() && q[k+1].st==i)
		{
			++k;
			insert(q[k].nd.st, q[k].nd.nd);
		}

		for(int j = 1; j <= (n+S-1)/S; ++j)
		{
			res[i][j] += (ll)i*load[j];
		}
	}

	cin >> m;

	while(m--)
	{
		int l, r, x;
		cin >> l >> r >> x;
		x = (x+ans)%(int)1e9;
		cout << (ans = query(l, r, min(x, A-1))) << endl;
	}
}