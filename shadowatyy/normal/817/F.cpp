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

#define M (1<<18)

int q;

int sum[2*M];
int lazy[2*M];

int t[M];
ll l[M];
ll r[M];

VLL val;

void shift(int v, int l, int r)
{
	if(lazy[v]==1)
	{
		sum[2*v] = sum[2*v+1] = (r-l+1)/2;

		if(2*v<M)
			lazy[2*v] = lazy[2*v+1] = 1;
	}
	else if(lazy[v]==2)
	{
		sum[2*v] = sum[2*v+1] = 0;

		if(2*v<M)
			lazy[2*v] = lazy[2*v+1] = 2;
	}
	else if(lazy[v]==3)
	{
		sum[2*v] = (r-l+1)/2-sum[2*v];
		sum[2*v+1] = (r-l+1)/2-sum[2*v+1];

		if(2*v<M)
		{
			if(lazy[2*v]==0)
				lazy[2*v] = 3;
			else if(lazy[2*v]==1)
				lazy[2*v] = 2;
			else if(lazy[2*v]==2)
				lazy[2*v] = 1;
			else if(lazy[2*v]==3)
				lazy[2*v] = 0;

			if(lazy[2*v+1]==0)
				lazy[2*v+1] = 3;
			else if(lazy[2*v+1]==1)
				lazy[2*v+1] = 2;
			else if(lazy[2*v+1]==2)
				lazy[2*v+1] = 1;
			else if(lazy[2*v+1]==3)
				lazy[2*v+1] = 0;
		}
	}

	lazy[v] = 0;
}

void insert(int a, int b, int t, int v = 1, int l = 0, int r = M-1)
{
	if(a>r || l>b)
		return;

	shift(v, l, r);

	if(a<=l && r<=b)
	{
		if(t==1)
			sum[v] = r-l+1;
		else if(t==2)
			sum[v] = 0;
		else if(t==3)
			sum[v] = r-l+1-sum[v];

		if(v<M)
			lazy[v] = t;

		return;
	}

	insert(a, b, t, 2*v, l, (l+r)/2);
	insert(a, b, t, 2*v+1, (l+r)/2+1, r);
	sum[v] = sum[2*v]+sum[2*v+1];
}

int query(int v = 1, int l = 0, int r = M-1)
{
	if(l==r)
		return l;

	shift(v, l, r);

	if(sum[2*v]!=(r-l+1)/2)
		return query(2*v, l, (l+r)/2);
	else
		return query(2*v+1, (l+r)/2+1, r);

	sum[v] = sum[2*v]+sum[2*v+1];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> t[i] >> l[i] >> r[i];
		
		if(l[i]!=1)
			val.pb(l[i]-1);

		val.pb(r[i]+1);
		val.pb(l[i]);
		val.pb(r[i]);
	}

	val.pb(1);
	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	for(int i = 1; i <= q; ++i)
	{
		insert(lower_bound(ALL(val), l[i])-val.begin(), lower_bound(ALL(val), r[i])-val.begin(), t[i]);
		cout << val[query()] << endl;
	}
}