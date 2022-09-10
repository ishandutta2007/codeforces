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
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 200007
#define M (1<<19)

int n, m, q;

int load[2][2*M];
int x[N];
int y[N];
char t[N];

VI p;

void insert(int i, int a, int b, int v)
{
	a = lower_bound(ALL(p), a)-p.begin();
	b = upper_bound(ALL(p), b)-p.begin()-1;

	if(a>b)
		return;

	a += M;
	b += M;

	load[i][a] = max(load[i][a], v);
	load[i][b] = max(load[i][b], v);

	while(a<b-1)
	{
		if(a%2==0)
			load[i][a+1] = max(load[i][a+1], v);

		if(b%2==1)
			load[i][b-1] = max(load[i][b-1], v);

		a /= 2;
		b /= 2;
	}
}

int query(int i, int a)
{
	a = lower_bound(ALL(p), a)-p.begin();

	int res = 0;

	a += M;

	while(a>=1)
	{
		res = max(res, load[i][a]);
		a /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> x[i] >> y[i] >> t[i];
		p.pb(x[i]);
		p.pb(y[i]);
	}

	sort(ALL(p));
	p.erase(unique(ALL(p)), p.end());

	for(int i = 1; i <= q; ++i)
	{
		if(t[i]=='U')
		{
			int g = query(0, x[i]);
			cout << y[i]-g << endl;
			insert(1, g+1, y[i], x[i]);
			insert(0, x[i], x[i], y[i]);
		}
		else
		{
			int g = query(1, y[i]);
			cout << x[i]-g << endl;
			insert(0, g+1, x[i], y[i]);
			insert(1, y[i], y[i], x[i]);
		}
	}
}