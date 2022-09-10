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

int x, k, n, q, cnt, dim, curr = 1;

int c[9];

map<int, int> s_nr, nr_s, w;

VI subs;

ll dp[2][70];

ll na_pozycje[70][70];

struct mat
{
	ll t[70][70];
};

mat G;

mat operator*(mat &a, mat &b)
{
	mat res;

	for(int i = 0; i < cnt; ++i)
	{
		for(int j = 0; j < cnt; ++j)
		{
			res.t[i][j] = INF;
		}
	}

	for(int i = 0; i < cnt; ++i)
	{
		for(int j = 0; j < cnt; ++j)
		{
			for(int k = 0; k < cnt; ++k)
			{
				res.t[i][j] = min(res.t[i][j], a.t[i][k]+b.t[k][j]);
			}
		}
	}

	return res;
}

mat pot(mat a, int p)
{
	mat res;

	for(int i = 0; i < cnt; ++i)
	{
		for(int j = 0; j < cnt; ++j)
		{
			res.t[i][j] = INF;
		}
	}

	for(int i = 0; i < cnt; ++i)
	{
		res.t[i][i] = 0;
	}

	for(int i = 0; i < 30; ++i)
	{
		if(p&(1<<i))
			res = res*a;
		
		a = a*a;
	}

	return res;
}

void przejscie(int moge)
{
	auto go = pot(G, moge);

	for(int i = 0; i < cnt; ++i)
	{
		for(int j = 0; j < cnt; ++j)
		{
			dp[dim^1][j] = min(dp[dim^1][j], dp[dim][i]+go.t[i][j]);
		}
	}

	for(int i = 0; i < cnt; ++i)
	{
		dp[dim][i] = INF;
	}

	dim ^= 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> x >> k >> n >> q;

	for(int i = 1; i <= k; ++i)
	{
		cin >> c[i];
	}

	for(int i = 1; i <= q; ++i)
	{
		int p, wp;
		cin >> p >> wp;
		w[p] = wp;
	}

	for(int s = 0; s < 1<<k; ++s)
	{
		if(__builtin_popcount(s)==x)
		{
			s_nr[s] = cnt;
			nr_s[cnt++] = s;
			subs.pb(s);
		}
	}

	for(int i = 0; i < cnt; ++i)
	{
		for(int j = 0; j < cnt; ++j)
		{
			G.t[i][j] = INF;
		}
	}

	for(auto maska:subs)
	{
		if(maska&1)
		{
			for(int i = 0; i < k; ++i)
			{
				int nowa = maska>>1;

				if(!(nowa&(1<<i)))
				{
					nowa |= 1<<i;
					na_pozycje[s_nr[maska]][s_nr[nowa]] = i;
					G.t[s_nr[maska]][s_nr[nowa]] = c[i+1];
				}
			}
		}
		else
		{
			int nowa = maska>>1;
			na_pozycje[s_nr[maska]][s_nr[nowa]] = -inf;
			G.t[s_nr[maska]][s_nr[nowa]] = 0;
		}

	}

	int start = 0;

	for(int i = 0; i < x; ++i)
	{
		start |= (1<<i);
	}

	for(int i = 0; i < cnt; ++i)
	{
		dp[dim][i] = INF;
		dp[dim^1][i] = INF;
	}

	dp[dim][s_nr[start]] = 0;

	for(int q = 2; q <= n-x+1; ++q)
	{	
		int moge = 0;

		if(w.lower_bound(q)==w.end())
			moge = n-x+1-q;
		else
			moge = max(0, (*w.lower_bound(q)).st-k-q);

		if(moge)
			przejscie(moge);

		q += moge;

		for(int i = 0; i < cnt; ++i)
		{
			for(int j = 0; j < cnt; ++j)
			{
				if(w.find(q+na_pozycje[i][j])==w.end())
					dp[dim^1][j] = min(dp[dim^1][j], dp[dim][i]+G.t[i][j]);
				else
					dp[dim^1][j] = min(dp[dim^1][j], dp[dim][i]+G.t[i][j]+w[q+na_pozycje[i][j]]);
			}
		}

		for(int i = 0; i < cnt; ++i)
		{
			dp[dim][i] = INF;
		}

		dim ^= 1;
	}

	cout << dp[dim][s_nr[start]];
}