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

#define N 400007
#define M (1<<19)

int n, curr, p, q, d;

ll res = INF, sum;

VPII G[N];

int f[N];
int pre[N];
int cyc[N];
ll l[N];
ll dp[N];
ll pref[N];
ll suf[N];
ll len[N];

map<PII, int> w;

bitset<N> vis;

void dfs(int v)
{
	pre[v] = ++curr;

	for(auto it:G[v])
	{
		if(!pre[it.st])
		{
			f[it.st] = v;
			dfs(it.st);
		}
		else if(it.st!=f[v] && pre[it.st]<pre[v])
		{
			p = it.st;
			q = v;
		}
	}
}

void depe(int v)
{
	vis[v] = 1;

	ll d1 = 0, d2 = 0;

	for(auto it:G[v])
	{
		if(!vis[it.st])
		{
			depe(it.st);
			dp[v] = max(dp[v], dp[it.st]);
			l[v] = max(l[v], l[it.st]+it.nd);

			if(l[it.st]+it.nd>d2)
				d2 = l[it.st]+it.nd;

			if(d1<d2)
				swap(d1, d2);
		}
	}

	dp[v] = max(dp[v], d1+d2);
}

struct tree
{
	pair<ll, int> load[2*M];

	void insert(int a, ll v)
	{
		a += M;
		load[a] = mp(v, a-M);
		a /= 2;

		while(a>=1)
		{
			load[a] = max(load[2*a], load[2*a+1]);
			a /= 2;
		} 
	}

	pair<ll, int> query(int a, int b)
	{
		if(a>b)
			return mp(-INF, -1);

		a += M;
		b += M;

		pair<ll, int> res = max(load[a], load[b]);

		while(a<b-1)
		{
			if(a%2==0)
				res = max(res, load[a+1]);

			if(b%2==1)
				res = max(res, load[b-1]);

			a /= 2;
			b /= 2;
		}

		return res;
	}

	tree(ll *t)
	{
		for(int i = 0; i < 2*M; ++i)
		{
			load[i] = mp(-INF, -1);
		}

		for(int i = 0; i < 2*d; ++i)
		{
			load[i+M] = mp(-t[i]+l[cyc[i%d]], i);
		}

		for(int i = M-1; i >= 1; --i)
		{
			load[i] = max(load[2*i], load[2*i+1]);
		}
	}
};

ll diam(int a, int b, tree &P, tree &S)
{
	if(a>=b)
		return -INF;

	auto q1 = P.query(a, b);
	S.insert(q1.nd, -INF);
	auto q2 = S.query(a, b);
	S.insert(q1.nd, -suf[q1.nd]+l[cyc[q1.nd%d]]);

	auto q3 = S.query(a, b);
	P.insert(q3.nd, -INF);
	auto q4 = P.query(a, b);
	P.insert(q3.nd, -pref[q3.nd]+l[cyc[q3.nd%d]]);

	return max(q1.st+q2.st, q3.st+q4.st)+sum;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);

		w[{a, b}] = w[{b, a}] = c;
	}

	dfs(1);

	while(p!=q)
	{
		cyc[d++] = q;
		q = f[q];
	}

	cyc[d++] = p;

	for(int i = 0; i < d; ++i)
	{
		vis[cyc[i]] = 1;
	}

	for(int i = 0; i < d; ++i)
	{
		depe(cyc[i]);
	}

	for(int i = 0; i < d; ++i)
	{
		len[i] = len[i+d] = dp[cyc[i]];

		if(i>0)
			pref[i] = pref[i+d] = w[{cyc[i], cyc[i-1]}];
	}

	for(int i = d-1; i >= 0; --i)
	{
		if(i<d-1)
			suf[i] = suf[i+d] = w[{cyc[i], cyc[i+1]}];
	}

	pref[d] = suf[d-1] = w[{cyc[d-1], cyc[0]}];

	for(int i = 1; i < 2*d; ++i)
	{
		pref[i] += pref[i-1];
	}

	for(int i = d*2-2; i >= 0; --i)
	{
		suf[i] += suf[i+1];
	}

	sum = pref[2*d-1];

	tree P(pref), S(suf);

	for(int i = 0; i < d; ++i)
	{
		ll q = diam(i+1, i+d, P, S);
		res = min(res, q);
	}

	for(int i = 0; i < d; ++i)
	{
		res = max(res, dp[cyc[i]]);
	}

	cout << res;
}