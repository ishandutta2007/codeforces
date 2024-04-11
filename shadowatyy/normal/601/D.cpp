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

#define N 300007

int n, res, cnt;

string s;

int c[N];

VI G[N];

bitset<N> vis;

struct node
{
	node* e[26];
	int	sub;

	node()
	{
		for(int i = 0; i < 26; ++i)
			e[i] = NULL;

		sub = 1;
	}
};

node* merge(node* v, node* u)
{		
	for(int i = 0; i < 26; ++i)
	{
		if(u->e[i]==NULL)
			v->e[i] = v->e[i];
		else if(v->e[i]==NULL)
		{
			v->e[i] = u->e[i];
			v->sub += v->e[i]->sub;
		}
		else
		{
			v->sub -= v->e[i]->sub;
			v->e[i] = merge(v->e[i], u->e[i]);
			v->sub += v->e[i]->sub;
		}
	}

	return v;
}

node* trie[N];

void dfs(int v)
{
	vis[v] = 1;

	trie[v] = new node();
	node* foo = new node();
	trie[v]->e[s[v]-'a'] = foo;
	trie[v]->sub += trie[v]->e[s[v]-'a']->sub;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);

			node* foo = new node();

			for(int i = 0; i < 26; ++i)
			{
				if(trie[it]->e[i]!=NULL)
				{
					trie[it]->sub -= trie[it]->e[i]->sub;
					foo->e[i] = trie[it]->e[i];
					trie[it]->e[i] = NULL;
					foo->sub += foo->e[i]->sub;
				}	
			}

			trie[it]->e[s[v]-'a'] = foo;
			merge(trie[v], trie[it]);
		}
	}

	if(c[v]+trie[v]->sub-1==res)
		++cnt;
	else if(c[v]+trie[v]->sub-1>res)
	{
		res = c[v]+trie[v]->sub-1;
		cnt = 1;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;  

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	cin >> s;
	s = '#'+s;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);

	cout << res << endl << cnt << endl;
}