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

const int N = 1e5+7;
const int S = 320;

int n, q;

string s[N];

int l[N];
int r[N];
int k[N];

int L[N];
int R[N];

int gdzie[N];

ll res[N];

VI queries[N];

struct aho
{
	int trie[N][26];
	int suf[N];
	int term[N];
	int ile[N];
	int sum[N];
	int root = 1, curr = 1;

	int add(string &t)
	{
		int s = root;

		for(auto it:t)
		{
			if(!trie[s][it-'a'])
				trie[s][it-'a'] = ++curr;

			s = trie[s][it-'a'];
		}

		++ile[s];
		term[s] = s;
		return s;
	}

	void bfs()
	{
		queue<int> Q;
		suf[root] = root;
		Q.push(root);

		while(!Q.empty())
		{
			int s = Q.front();
			Q.pop();

			if(!term[s])
				term[s] = term[suf[s]];

			for(int i = 0; i < 26; ++i)
			{
				if(trie[s][i])
				{
					if(s==root)
						suf[trie[s][i]] = s;
					else
					{
						int kand = suf[s];

						while(kand!=root && !trie[kand][i])
							kand = suf[kand];

						if(trie[kand][i])
							kand = trie[kand][i];

						suf[trie[s][i]] = kand;
					}
					
					ile[trie[s][i]] += ile[suf[trie[s][i]]];
					Q.push(trie[s][i]);
				}
			}
		}
	}

	void feed(string &t, int k)
	{
		int s = root;

		for(auto it:t)
		{
			s = trie[s][it-'a'];

			int u = s;

			while(u)
			{
				sum[u] += k;
				u = term[suf[u]];
			}
		}
	}

	int search(string t)
	{
		int s = root, res = 0;

		for(auto it:t)
		{
			while(s!=root && !trie[s][it-'a'])
				s = suf[s];

			if(trie[s][it-'a'])
				s = trie[s][it-'a'];

			res += ile[s];
		}

		return res;
	}

	void clear()
	{
		memset(ile, 0, sizeof ile);
	}

	aho()
	{
		for(int i = 0; i < N; ++i)
			memset(trie[i], 0, sizeof trie[i]);

		memset(suf, 0, sizeof suf);
		memset(ile, 0, sizeof ile);
		memset(sum, 0, sizeof sum);
		memset(term, 0, sizeof term);
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];
	}

	for(int i = 1; i <= q; ++i)
	{
		cin >> l[i] >> r[i] >> k[i];
		L[i] = inf;
	}

	for(int b = 1; b <= (n+S-1)/S; ++b)
	{
		aho bucket;

		for(int i = S*(b-1)+1; i <= min(n, S*b); ++i)
		{
			bucket.add(s[i]);
		}

		bucket.bfs();

		for(int i = 1; i <= q; ++i)
		{
			if(l[i] <= S*(b-1)+1 && S*b <= r[i])
			{
				res[i] += bucket.search(s[k[i]]);
				L[i] = min(L[i], S*(b-1)+1);
				R[i] = max(R[i], S*b);
			}
				
		}
	}

	aho all;

	for(int i = 1; i <= n; ++i)
	{
		gdzie[i] = all.add(s[i]);
	}

	all.bfs();
	all.clear();

	for(int i = 1; i <= q; ++i)
	{
		queries[k[i]].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		all.feed(s[i], 1);

		for(auto it:queries[i])
		{
			if(L[it]==inf)
			{
				for(int j = l[it]; j <= r[it]; ++j)
					res[it] += all.sum[gdzie[j]];
			}
			else
			{
				for(int j = l[it]; j < L[it]; ++j)
					res[it] += all.sum[gdzie[j]];

				for(int j = R[it]+1; j <= r[it]; ++j)
					res[it] += all.sum[gdzie[j]];
			}
		}

		all.feed(s[i], -1);
	}

	for(int i = 1; i <= q; ++i)
		cout << res[i] << endl;
}