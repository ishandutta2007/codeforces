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
#define flush fflush(stdout)
using namespace std;

#define M (1<<17)

int m, t, p;

int x[M];

int lazy[2*M];
int sub[2*M];

void shift(int v)
{
	if(v<M)
	{
		lazy[2*v] += lazy[v];
		lazy[2*v+1] += lazy[v];
		sub[2*v] += lazy[v];
		sub[2*v+1] += lazy[v];
		lazy[v] = 0;
	}
}

void insert(int a, int b, int c, int v = 1, int l = 1, int r = M)
{
	if(a>r || l>b)
		return;

	shift(v);

	if(a<=l && r<=b)
	{
		lazy[v] += c;
		sub[v] += c;
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = max(sub[2*v], sub[2*v+1]);
}

int find(int v = 1, int l = 1, int r = M)
{
	if(l==r)
		return l;

	shift(v);

	if(sub[2*v+1]>0)
		return find(2*v+1, (l+r)/2+1, r);
	else if(sub[2*v]>0)
		return find(2*v, l, (l+r)/2);
	else
		return -1;

	sub[v] = max(sub[2*v], sub[2*v+1]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> p >> t;

		if(t==0)
			insert(1, p, -1);
		else
		{
			cin >> x[p];
			insert(1, p, 1);
		}

		int q = find();

		if(q==-1)
			cout << q << endl;
		else
			cout << x[q] << endl;
	}
}