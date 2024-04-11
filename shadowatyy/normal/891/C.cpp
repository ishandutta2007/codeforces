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
using namespace std;

const int N = 5e5+7;

int n, m, q;

int a[N];
int b[N];
int w[N];

VI E[N];

int A[N];
int B[N];
int rA[N];
int rB[N];

map<int, VI> zbiory[N];

bitset<N> zle;

int Find(int a, int *p)
{
	if(p[a]!=a)
		p[a] = Find(p[a], p);

	return p[a];
}

bool Union(int a, int b, int *p, int *r)
{
	a = Find(a, p);
	b = Find(b, p);

	if(a==b)
		return 0;

	if(r[a]<r[b])
		swap(a, b);
	
	p[b] = a;
	r[a] += r[b];

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i] >> w[i];
		E[w[i]].pb(i);
	}

	cin >> q;

	for(int i = 1; i <= q; ++i)
	{
		int k;
		cin >> k;

		while(k--)
		{
			int nr;
			cin >> nr;
			zbiory[w[nr]][i].pb(nr);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		A[i] = i;
		rA[i] = 1;
	}

	for(int i = 1; i < N; ++i)
	{
		for(auto z:zbiory[i])
		{
			int que = z.st;

			for(auto it:z.nd)
			{
				Find(a[it], A);
				Find(b[it], A);

				B[a[it]] = A[a[it]];
				B[b[it]] = A[b[it]];
				rB[a[it]] = rA[a[it]];
				rB[b[it]] = rA[b[it]];

				B[Find(a[it], A)] = A[Find(a[it], A)];
				B[Find(b[it], A)] = A[Find(b[it], A)];
				rB[Find(a[it], A)] = rA[Find(a[it], A)];
				rB[Find(b[it], A)] = rA[Find(b[it], A)];
			}

			for(auto it:z.nd)
			{
				if(!Union(a[it], b[it], B, rB))
					zle[que] = 1;
			}
		}

		for(auto it:E[i])
		{
			Union(a[it], b[it], A, rA);
		}
	}

	for(int i = 1; i <= q; ++i)
	{
		if(!zle[i])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}