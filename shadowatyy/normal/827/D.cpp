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

#define N 200007
#define M (1<<18)

int n, m, curr;

int A[N];
int B[N];
int C[N];
int r[N];
VI G[N];
VI e;
bitset<N> ins;
int size[N];
int top[N];
int p[N];
int pos[N];
int sub[2*M];
int load[2*M];
int res[N];
int depth[N];

bool comp(int a, int b)
{
	return C[a]<C[b];
}

int Find(int a)
{
	if(r[a]!=a)
		r[a] = Find(r[a]);

	return r[a];
}

void insert(int a, int b, int c, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || a>r || l>b)
		return;

	if(a<=l && r<=b)
	{
		load[v] = min(load[v], c);
		sub[v] = min(sub[v], c);
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = min(load[v], min(sub[2*v], sub[2*v+1]));
}

int query(int a, int b, int path = inf16, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || a>r || l>b)
		return inf16;

	if(a<=l && r<=b)
		return min(sub[v], path);

	return min(query(a, b, min(path, load[v]), 2*v, l, (l+r)/2), query(a, b, min(path, load[v]), 2*v+1, (l+r)/2+1, r));
}

void dfs(int v)
{
	size[v] = 1;

	for(auto it:G[v])
	{
		if(it!=p[v])
		{
			depth[it] = depth[v]+1;
			p[it] = v;
			dfs(it);
			size[v] += size[it];
		}
	}
}

void hld(int v, int r)
{
	top[v] = r;
	pos[v] = ++curr;

	auto h = mp(-1, -1);

	for(auto it:G[v])
	{
		if(it!=p[v])
			h = max(h, mp(size[it], it));
	}

	if(h.nd!=-1)
	{
		hld(h.nd, r);

		for(auto it:G[v])
		{
			if(it!=p[v] && it!=h.nd)
				hld(it, it);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		r[i] = i;
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> A[i] >> B[i] >> C[i];
		e.pb(i);
	}

	sort(ALL(e), comp);

	for(auto it:e)
	{
		int a = Find(A[it]);
		int b = Find(B[it]);

		if(a!=b)
		{
			r[a] = b;
			G[A[it]].pb(B[it]);
			G[B[it]].pb(A[it]);
			ins[it] = 1;
		}
	}

	dfs(1);
	hld(1, 1);

	memset(sub, inf16, sizeof sub);
	memset(load, inf16, sizeof load);

	for(int i = 1; i <= m; ++i)
	{
		if(!ins[i])
		{
			int a = A[i];
			int b = B[i];

			while(top[a]!=top[b])
			{
				if(pos[a]>pos[b])
					swap(a, b);

				insert(pos[top[b]], pos[b], C[i]);
				b = p[top[b]];
			}

			if(pos[a]>pos[b])
				swap(a, b);

			insert(pos[a]+1, pos[b], C[i]);
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		if(ins[i])
		{
			if(pos[A[i]]>pos[B[i]])
				swap(A[i], B[i]);

			res[i] = query(pos[B[i]], pos[B[i]])-1;

			if(res[i]+1==inf16)
				res[i] = -1;
		}
	}

	memset(sub, inf16, sizeof sub);
	memset(load, inf16, sizeof load);

	for(int i = 1; i <= m; ++i)
	{
		if(ins[i])
			insert(pos[B[i]], pos[B[i]], -C[i]);
	}

	for(int i = 1; i <= m; ++i)
	{
		if(!ins[i])
		{
			res[i] = -inf16;

			int a = A[i];
			int b = B[i];

			while(top[a]!=top[b])
			{
				if(pos[a]>pos[b])
					swap(a, b);

				res[i] = max(res[i], -query(pos[top[b]], pos[b])-1);
				b = p[top[b]];
			}

			if(pos[a]>pos[b])
				swap(a, b);

			res[i] = max(res[i], -query(pos[a]+1, pos[b])-1);
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		cout << res[i] << " ";
	}
}