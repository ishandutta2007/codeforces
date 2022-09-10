#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define getchar_unlocked getchar

const int N = 2e5+7;

int n, L;

int a[2*N];
int b[2*N];

VPII segs;
VI S;

struct eve
{
	int d, t, ind;

	inline bool operator<(const eve &x) const
	{
		if(d!=x.d)
			return d<x.d;
		else if(t!=x.t)
			return t<x.t;
		else
			return ind<x.ind;
	}
};

eve E[4*N];

bool check(int k)
{
	S.clear();
	segs.clear();

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]-k>=0 && a[i]+k<L)
		{
			segs.eb(a[i]-k, a[i]+k);
			segs.eb(a[i]-k+L, a[i]+k+L);
		}
		else if(a[i]-k<0)
			segs.eb(a[i]-k+L, a[i]+k+L);
		else
			segs.eb(a[i]-k, a[i]+k);
	}

	for(int i = 0; i < segs.size(); ++i)
	{
		E[i] = {segs[i].nd, 1, i};
	}

	for(int i = 1; i <= 2*n; ++i)
	{
		E[segs.size()+i-1] = {b[i], 0, i};
	}

	int ile = segs.size() + 2*n;

	sort(E, E+ile);

	int x = 0;

	for(int i = 0; i < ile; ++i)
	{
		auto it = E[i];

		if(it.t==0)
			S.pb(b[it.ind]);
		else
		{	
			while(x<S.size() && S[x]<segs[it.ind].st)
				++x;

			if(x==S.size() || S[x]>segs[it.ind].nd)
				return 0;

			++x;
		}
	}

	return 1;
}

inline int read()
{
	register int buff, res = 0;

	buff = getchar_unlocked();

	while(buff<'0' || buff>'9')
		buff = getchar_unlocked();

	while('0'<=buff && buff<='9')
	{
		res = (res<<1)+(res<<3)+buff-'0';
		buff = getchar_unlocked();
	}

	return res;
}

int32_t main()
{
	n = read();
	L = read();

	for(int i = 1; i <= n; ++i)
	{
		a[i] = read();
	}

	for(int i = 1; i <= n; ++i)
	{
		b[i] = read();
		b[i+n] = b[i]+L;
	}

	int l = 0, r = L/2;

	while(l<r)
	{
		int m = (l+r)/2;

		if(m==r)
			--m;

		if(check(m))
			r = m;
		else
			l = m+1;
	}

	printf("%d\n", l);
}