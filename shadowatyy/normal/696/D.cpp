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

const int N = 207;

int n, curr = 1;

ll l;

string s[N];
int a[N];
int trie[N][26];
int suf[N];
int sum[N];

queue<int> Q;
VI rev;

struct mat
{
	ll m[N][N];

	mat()
	{
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				m[i][j] = -INF;
			}
		}
	}
};

mat operator*(const mat &a, const mat &b)
{
	mat res;

	for(int i = 1; i <= curr; ++i)
	{
		for(int j = 1; j <= curr; ++j)
		{
			for(int k = 1; k <= curr; ++k)
			{
				res.m[i][j] = max(res.m[i][j], a.m[i][k]+b.m[k][j]);
			}
		}
	}

	return res;
}

mat pot[67];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> l;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];

		int st = 1;

		for(int j = 0; j < s[i].size(); ++j)
		{
			if(!trie[st][s[i][j]-'a'])
				trie[st][s[i][j]-'a'] = ++curr;

			st = trie[st][s[i][j]-'a'];
		}

		sum[st] += a[i];
	}

	suf[1] = 1;
	Q.push(1);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		rev.pb(v);

		for(int i = 0; i < 26; ++i)
		{
			if(trie[v][i])
			{
				if(v==1)
					suf[trie[v][i]] = 1;
				else
				{
					int u = suf[v];

					while(u!=1 && !trie[u][i])
						u = suf[u];
					
					if(trie[u][i])
						u = trie[u][i];

					suf[trie[v][i]] = u;
				}

				sum[trie[v][i]] += sum[suf[trie[v][i]]];
				Q.push(trie[v][i]);
			}
		}
	}

	for(int i = 1; i <= curr; ++i)
	{
		for(int j = 0; j < 26; ++j)
		{
			int u = i;

			while(u!=1 && !trie[u][j])
				u = suf[u];

			if(trie[u][j])
				u = trie[u][j];

			pot[0].m[i][u] = sum[u];
		}		
	}

	for(int i = 1; i <= 47; ++i)
	{
		pot[i] = pot[i-1]*pot[i-1];
	}

	mat res;

	for(int i = 1; i <= curr; ++i)
	{
		res.m[i][i] = 0;
	}

	for(int i = 0; i <= 47; ++i)
	{
		if(l&(1ll<<i))
			res = res*pot[i];
	}

	ll ans = 0;

	for(int i = 1; i <= curr; ++i)
	{
		ans = max(ans, res.m[1][i]);
	}

	cout << ans;
}