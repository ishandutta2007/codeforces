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

int n;

int a[N];
int b[N];
int ile[N];
int fen[N];
int tree[2*M];

void del(int a)
{
	while(a<=n)
	{
		--fen[a];
		a += (a&-a);
	}
}

void add(int a)
{
	while(a<=n)
	{
		++fen[a];
		a += (a&-a);
	}
}

int sum(int a)
{
	int res = 0;

	while(a>=1)
	{
		res += fen[a];
		a -= (a&-a);
	}

	return res;
}

void prep()
{
	memset(fen, 0, sizeof fen);

	for(int i = 1; i <= n; ++i)
	{
		add(i);
	}
}

int query(int a, int b)
{
	++a;
	++b;

	if(a>b)
		return 0;
	else
		return sum(b)-sum(a-1);
}

void sum_del(int a, int v = 1, int l = 0, int r = M-1)
{
	if(l==r)
	{
		--tree[v];
		return;
	}

	if(a<=(l+r)/2)
		sum_del(a, 2*v, l, (l+r)/2);
	else
		sum_del(a, 2*v+1, (l+r)/2+1, r);

	tree[v] = tree[2*v]+tree[2*v+1];
}

int kth(int k, int v = 1, int l = 0, int r = M-1)
{
	if(l==r)
		return l;

	if(tree[2*v]>=k)
		return kth(k, 2*v, l, (l+r)/2);
	else
		return kth(k-tree[2*v], 2*v+1, (l+r)/2+1, r);
}

void build(int v = 1, int l = 0, int r = M-1)
{
	if(l==r)
	{
		tree[v] = 1;
		return;
	}

	build(2*v, l, (l+r)/2);
	build(2*v+1, (l+r)/2+1, r);
	tree[v] = tree[2*v]+tree[2*v+1];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	prep();

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];

		ile[n-i-1] += query(0, a[i]-1);
		del(a[i]+1);
	}

	prep();

	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];

		ile[n-i-1] += query(0, b[i]-1);
		del(b[i]+1);
	}

	for(int i = 0; i < n; ++i)
	{
		if(ile[i]>i)
		{
			ile[i] -= (i+1);
			++ile[i+1];
		}
	}

	build();

	for(int i = n-1; i >= 0; --i)
	{
		int q = kth(ile[i]+1);
		cout << q << " ";
		sum_del(q);
	}
}