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

const int N = 1e5+7;

int q;

VI divs[N];

struct node
{
	node* e0;
	node* e1;
	int sub;

	node()
	{
		e0 = e1 = NULL;
		sub = inf;
	}
};

node* trie[N];

bitset<N> juz;

void insert(int r, int x)
{
	auto curr = trie[r];

	vector<node*> vis;

	for(int i = 16; i >= 0; --i)
	{
		vis.pb(curr);

		if(x&(1<<i))
		{
			if(!curr->e1)
				curr->e1 = new node();

			curr = curr->e1;
		}
		else
		{
			if(!curr->e0)
				curr->e0 = new node();

			curr = curr->e0;
		}
	}

	curr->sub = x;

	reverse(ALL(vis));

	for(auto it:vis)
	{
		it->sub = inf;

		if(it->e0)
			it->sub = min(it->sub, it->e0->sub);

		if(it->e1)
			it->sub = min(it->sub, it->e1->sub);
	}
}

int find(int r, int x, int mx)
{
	auto curr = trie[r];

	for(int i = 16; i >= 0; --i)
	{
		if(x&(1<<i))
		{
			if(curr->e0 && curr->e0->sub<=mx)
				curr = curr->e0;
			else if(curr->e1 && curr->e1->sub<=mx)
				curr = curr->e1;
			else
				return -1;
		}
		else
		{
			if(curr->e1 && curr->e1->sub<=mx)
				curr = curr->e1;
			else if(curr->e0 && curr->e0->sub<=mx)
				curr = curr->e0;
			else
				return -1;
		}
	}

	return curr->sub;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i < N; ++i)
	{
		for(int j = i; j < N; j += i)
		{
			divs[j].pb(i);
		}

		trie[i] = new node();
	}

	cin >> q;

	while(q--)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int u;
			cin >> u;

			if(juz[u])
				continue;

			juz[u] = 1;

			for(auto it:divs[u])
				insert(it, u);
		}
		else
		{
			int x, k, s;
			cin >> x >> k >> s;

			if(x%k!=0)
				cout << -1 << endl;
			else
				cout << find(k, x, s-x) << endl;
		}
	}
}