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
#define flush fflush(stdout)
using namespace std;

#define N 100007
#define S 317
#define M (1<<17)
#define cerr if(0)cout

int n, m, q, a, b;

int t[N][11];

struct dsu
{
	int ile, l[11], r[11], p, q;
};

dsu load[2*M];

int p[11*N];
bitset<11*N> vis;

int Find(int a)
{
	if(p[a]!=a)
		p[a] = Find(p[a]);

	return p[a];
}

dsu merge(const dsu &a, const dsu &b)
{
	dsu c;
	c.ile = 0;
	c.p = 0;
	c.q = 0;
	memset(c.l, 0, sizeof c.l);
	memset(c.r, 0, sizeof c.r);

	if(!a.ile || !b.ile)
		return c;

	for(int i = 1; i <= n; ++i)
	{
		p[ a.l[i] ] = a.l[i];
		p[ b.l[i] ] = b.l[i];
		p[ a.r[i] ] = a.r[i];
		p[ b.r[i] ] = b.r[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		vis[ a.l[i] ] = 0;
		vis[ b.l[i] ] = 0;
		vis[ a.r[i] ] = 0;
		vis[ b.r[i] ] = 0;
	}

	int przed = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[ a.l[i] ]) ++przed;
			vis[ a.l[i] ] = 1;

		if(!vis[ b.l[i] ]) ++przed;
			vis[ b.l[i] ] = 1;

		if(!vis[ a.r[i] ]) ++przed;
			vis[ a.r[i] ] = 1;

		if(!vis[ b.r[i] ]) ++przed;
			vis[ b.r[i] ] = 1;	
	}

	for(int i = 1; i <= n; ++i)
	{
		cerr << Find(a.r[i]) << " ";
	}

	cerr << endl;

	for(int i = 1; i <= n; ++i)
	{
		cerr << Find(b.l[i]) << " ";
	}

	cerr << endl << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(t[a.q][i]==t[b.p][i] && Find(a.r[i])!=Find(b.l[i]))
		{
			cerr << i << endl;

			if(rand()&1)
				p[Find(a.r[i])] = Find(b.l[i]);
			else
				p[Find(b.l[i])] = Find(a.r[i]);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cerr << Find(a.r[i]) << " ";
	}

	cerr << endl;

	for(int i = 1; i <= n; ++i)
	{
		cerr << Find(b.l[i]) << " ";
	}

	cerr << endl;

	for(int i = 1; i <= n; ++i)
	{
		vis[ Find(a.l[i]) ] = 0;
		vis[ Find(b.l[i]) ] = 0;
		vis[ Find(a.r[i]) ] = 0;
		vis[ Find(b.r[i]) ] = 0;
	}

	int po = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[ Find(a.l[i]) ]) ++po;
			vis[ Find(a.l[i]) ] = 1;
		
		if(!vis[ Find(b.l[i]) ]) ++po;
			vis[ Find(b.l[i]) ] = 1;

		if(!vis[ Find(a.r[i]) ]) ++po;
			vis[ Find(a.r[i]) ] = 1;

		if(!vis[ Find(b.r[i]) ]) ++po;
			vis[ Find(b.r[i]) ] = 1;
	}

	c.ile = a.ile+b.ile+po-przed;
	c.p = a.p;
	c.q = b.q;

	for(int i = 1; i <= n; ++i)
	{
		c.l[i] = Find(a.l[i]);
		c.r[i] = Find(b.r[i]);
	}

	return c;
}	

int query(int a, int b)
{
	a += M;
	b += M;

	VI A, B;

	A.pb(a);

	if(a!=b)
		B.pb(b);

	while(a<b-1)
	{
		if(a%2==0)
			A.pb(a+1);

		if(b%2==1)
			B.pb(b-1);

		a /= 2;
		b /= 2;
	}

	reverse(ALL(B));
	A.insert(A.end(), ALL(B));

	dsu res = load[A[0]];

	for(int i = 1; i < A.size(); ++i)
	{
		res = merge(res, load[A[i]]);
	}

	return res.ile;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	srand(time(NULL));

	cin >> n >> m >> q;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> t[j][i];
		}
	}

	for(int a = 1; a <= m; ++a)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(t[a][i]!=t[a][i-1])
			{
				++load[a+M].ile;
				load[a+M].l[i] = load[a+M].r[i] = a*n+i;
			}
			else
				load[a+M].l[i] = load[a+M].r[i] = load[a+M].r[i-1];

			load[a+M].p = load[a+M].q = a;
		}
	}

	for(int i = M-1; i >= 1; --i)
	{
		load[i] = merge(load[2*i], load[2*i+1]);
	}

	while(q--)
	{
		cin >> a >> b;

		cout << query(a, b) << endl;
	}
}