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

const int N = 2e5+7;

int n;

VI G[N];

int l[N];

string s;

ll ans[N];
ll dp[N];

bitset<N> del;

int sub[N];
int max_sub[N];
int maska[N];

VI curr;

int maski[1<<20];

void dfs(int v, int p)
{
	curr.pb(v);
	sub[v] = 1;
	max_sub[v] = 0;

	for(auto it:G[v])
	{
		if(!del[it] && it!=p)
		{
			dfs(it, v);
			sub[v] += sub[it];
			max_sub[v] = max(max_sub[v], sub[it]);
		}
	}
}

void spojna(int v, int p, VI &c)
{
	c.pb(v);

	for(auto it:G[v])
	{
		if(!del[it] && it!=p)
			spojna(it, v, c);
	}
}


void licz_maski(int v, int p)
{
	maska[v] ^= 1<<l[v];

	for(auto it:G[v])
	{
		if(!del[it] && it!=p)
		{
			maska[it] = maska[v];
			licz_maski(it, v);
		}
	}
}

void sumuj(int v, int p)
{
	for(auto it:G[v])
	{
		if(!del[it] && it!=p)
		{
			sumuj(it, v);
			dp[v] += dp[it];
		}
	}
}

void decompo(int s)
{
	curr.clear();
	dfs(s, s);

	for(auto &it:curr)
	{
		max_sub[it] = max(max_sub[it], (int)curr.size()-sub[it]);

		if(max_sub[it]<max_sub[curr[0]])
			swap(it, curr[0]);
	}

	int centro = curr[0];
	del[centro] = 1;

	licz_maski(centro, centro);

	vector<VI> spojne;

	for(auto it:G[centro])
	{
		if(!del[it])
		{
			VI v;
			spojna(it, centro, v);
			spojne.pb(v);
		}
	}

	for(auto s:spojne)
	{
		for(auto v:s)
		{
			dp[v] += maski[maska[v]];
			dp[centro] -= maski[maska[v]];

			for(int i = 0; i < 20; ++i)
			{
				dp[v] += maski[maska[v]^(1<<i)];
				dp[centro] -= maski[maska[v]^(1<<i)];
			}
		}

		for(auto v:s)
		{
			++maski[maska[v]^maska[centro]];
		}
	}

	for(auto s:spojne)
	{
		for(auto v:s)
		{
			--maski[maska[v]^maska[centro]];
		}
	}

	reverse(ALL(spojne));

	for(auto s:spojne)
	{
		for(auto v:s)
		{
			dp[v] += maski[maska[v]];

			for(int i = 0; i < 20; ++i)
			{
				dp[v] += maski[maska[v]^(1<<i)];
			}
		}

		for(auto v:s)
		{
			++maski[maska[v]^maska[centro]];
		}
	}

	for(auto s:spojne)
	{
		for(auto v:s)
		{
			--maski[maska[v]^maska[centro]];
		}
	}

	for(auto v:curr)
	{
		if(__builtin_popcount(maska[v])<=1)
			++dp[v];
	}

	sumuj(centro, centro);

	for(auto it:curr)
	{
		ans[it] += dp[it];
		dp[it] = 0;
		maska[it] = 0;
	}

	for(auto it:G[centro])
	{
		if(!del[it])
			decompo(it);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	cin >> s;
	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		l[i] = s[i]-'a';
	}

	decompo(1);

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}
}