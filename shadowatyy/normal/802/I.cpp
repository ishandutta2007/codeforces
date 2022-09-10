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
#define M (1<<17)

int t, n;

ll res;

string s;

VI sa;

PII cmp[N];
int pos[N];
int nast[N];
int lcp[N];
int size[N];

int load[2*M];

void clear()
{
	memset(lcp, 0, sizeof lcp);
	memset(size, 0, sizeof size);
	memset(nast, 0, sizeof nast);
	memset(pos, 0, sizeof pos);
	sa.clear();
	res = 0;
}

bool comp(int a, int b)
{
	return cmp[a]<cmp[b];
}

void build()
{
	memset(load, 0, sizeof load);

	for(int i = 1; i <= n; ++i)
	{
		load[i+M] = i;
	}

	for(int i = M-1; i >= 1; --i)
	{
		if(lcp[load[2*i]]<lcp[load[2*i+1]])
			load[i] = load[2*i];
		else
			load[i] = load[2*i+1];
	}
}

void update(int a)
{
	a += M;
	load[a] = 0;
	a /= 2;

	while(a>=1)
	{	
		if(lcp[load[2*a]]<lcp[load[2*a+1]])
			load[a] = load[2*a];
		else
			load[a] = load[2*a+1];

		a /= 2;
	}
}

int query(int a, int b)
{
	a += M;
	b += M;

	int res = 0;

	if(lcp[load[a]]<lcp[res])
		res = load[a];

	if(lcp[load[b]]<lcp[res])
		res = load[b];

	while(a<b-1)
	{
		if(a%2==0 && lcp[load[a+1]]<lcp[res])
			res = load[a+1];
		
		if(b%2==1 && lcp[load[b-1]]<lcp[res])
			res = load[b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

void solve(int a, int b, int last)
{		
	VI v;

	int q = query(a, b), val = lcp[q];

	if(val==inf)
	{
		res += (ll)(size[a]-last-1);
		return;
	}
	else
	{
		while(lcp[q]==val)
		{
			v.pb(q);
			update(q);
			q = query(a, b);				
		}
	}

	res += (ll)(b-a+1)*(b-a+1)*(val-last-1);

	sort(ALL(v));

	res += (ll)(v[0]-a+1)*(v[0]-a+1);
	solve(a, v[0], lcp[v[0]]);
	res += (ll)(b-v.back())*(b-v.back());
	solve(v.back()+1, b, lcp[v[0]]);

	for(int i = 0; i+1 < v.size(); ++i)
	{
		res += (ll)(v[i+1]-v[i])*(v[i+1]-v[i]);
		solve(v[i]+1, v[i+1], lcp[v[0]]);
	}
}

void test()
{
	cin >> s;
	n = s.size();
	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		sa.pb(i);
		cmp[i] = mp(s[i], -1);
	}

	sort(ALL(sa), comp);

	for(int i = 0; i < n; ++i)
	{
		if(i>0 && cmp[sa[i-1]]==cmp[sa[i]])
			pos[sa[i]] = pos[sa[i-1]];
		else
			pos[sa[i]] = i;
	}

	for(int l = 0; (1<<l)<n; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(i+(1<<l)<=n)
				cmp[i] = mp(pos[i], pos[i+(1<<l)]);
			else
				cmp[i] = mp(pos[i], -1);
		}

		sort(ALL(sa), comp);

		for(int i = 0; i < n; ++i)
		{
			if(i>0 && cmp[sa[i-1]]==cmp[sa[i]])
				pos[sa[i]] = pos[sa[i-1]];
			else
				pos[sa[i]] = i;
		}
	}

	for(int i = 0; i < n-1; ++i)
	{
		nast[sa[i]] = sa[i+1];
	}

	for(int i = 0; i < n; ++i)
	{
		pos[sa[i]] = i;
		size[i+1] = n-sa[i]+1;
	}

	int curr = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(!nast[i])
			continue;

		while(curr+1<=min(n-i+1, n-nast[i]+1) && s[i+curr]==s[nast[i]+curr])
			++curr;

		lcp[pos[i]+1] = curr;

		curr = max(0, curr-1);
	}

	lcp[n] = lcp[0] = inf;

	build();
	solve(1, n, -1);

	cout << res << endl;

	clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
		test();
}