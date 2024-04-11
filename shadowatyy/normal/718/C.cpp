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
#define M (1<<17)
#define MOD inf

int n, m;

int A[N];

struct mat
{
	ll m[2][2];

	mat()
	{
		m[0][0] = m[1][0] = m[0][1] = m[1][1] = 0;
	}
};

PLL sub[2*M];
mat load[2*M];

mat operator*(mat &a, mat &b)
{
	mat c;

	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				c.m[i][j] += a.m[i][k]*b.m[k][j];
			}

			c.m[i][j] %= MOD;
		}
	}

	return c;
}

PLL operator*(mat &a, PLL &b)
{
	PLL res;

	res.st = (b.st*a.m[0][0]+b.nd*a.m[0][1])%MOD;
	res.nd = (b.st*a.m[1][0]+b.nd*a.m[1][1])%MOD;

	return res;
}

mat pot(mat a, int p)
{
	mat res;

	res.m[0][0] = res.m[1][1] = 1;

	for(int i = 0; i < 30; ++i)
	{
		if(p&(1<<i))
			res = res*a;

		a = a*a;
	}

	return res;
}

void build()
{
	for(int i = 0; i < 2*M; ++i)
	{
		load[i].m[0][0] = load[i].m[1][1] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		mat f;

		f.m[0][0] = 1;
		f.m[0][1] = 1;
		f.m[1][0] = 1;

		f = pot(f, A[i]-1);

		sub[i+M] = mp(f.m[0][0], f.m[1][0]);
	}

	for(int i = M-1; i >= 1; --i)
	{	
		sub[i].st = (sub[2*i].st+sub[2*i+1].st)%MOD;
		sub[i].nd = (sub[2*i].nd+sub[2*i+1].nd)%MOD;
	}	
}

void insert(int a, int b, mat &c, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || a>r || l>b)
		return;

	if(a<=l && r<=b)
	{
		load[v] = load[v]*c;
		sub[v] = c*sub[v];
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v].st = (sub[2*v].st+sub[2*v+1].st)%MOD;
	sub[v].nd = (sub[2*v].nd+sub[2*v+1].nd)%MOD;
	sub[v] = load[v]*sub[v];
}

PLL query(int a, int b, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || a>r || l>b)
		return mp(0, 0);

	if(a<=l && r<=b)
		return sub[v];

	PLL q1 = query(a, b, 2*v, l, (l+r)/2), q2 = query(a, b, 2*v+1, (l+r)/2+1, r);
	q1 = load[v]*q1;
	q2 = load[v]*q2;
	return mp((q1.st+q2.st)%MOD, (q1.nd+q2.nd)%MOD);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}

	build();

	while(m--)
	{
		int t, l, r;

		cin >> t >> l >> r;

		if(t==1)
		{
			int x;
			cin >> x;
			
			mat f;

			f.m[0][0] = 1;
			f.m[0][1] = 1;
			f.m[1][0] = 1;

			f = pot(f, x);

			insert(l, r, f);
		}
		else
			cout << query(l, r).st << endl;
	}
}