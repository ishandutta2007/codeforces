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

const int N = 32*100007;

int q, c = 1, t, p, l;

int trie[2][N];
int sub[N];

void add(int p)
{
	int s = 1;

	for(int i = 30; i >= 0; --i)
	{
		++sub[s];

		if(p&(1<<i))
		{
			if(!trie[1][s])
				trie[1][s] = ++c;

			s = trie[1][s];
		}
		else
		{
			if(!trie[0][s])
				trie[0][s] = ++c;

			s = trie[0][s];
		}
	}

	++sub[s];
}

void del(int p)
{
	int s = 1;

	for(int i = 30; i >= 0; --i)
	{
		--sub[s];

		if(p&(1<<i))
			s = trie[1][s];
		else
			s = trie[0][s];
	}

	--sub[s];
}

int que(int p, int l)
{
	int s = 1, res = 0, ile = 0;

	for(int i = 30; i >= 0; --i)
	{
		if(!s)
			return res;

		if(p&(1<<i))
		{
			if(ile+(1<<i)<l)
			{
				ile += (1<<i);
				res += sub[trie[1][s]];
				s = trie[0][s];
			}
			else
				s = trie[1][s];
		}
		else
		{
			if(ile+(1<<i)<l)
			{
				ile += (1<<i);
				res += sub[trie[0][s]];
				s = trie[1][s];
			}
			else
				s = trie[0][s];
		}
	}

	return sub[s]+res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> q;

	while(q--)
	{
		cin >> t;

		if(t==1)
		{
			cin >> p;
			add(p);
		}
		else if(t==2)
		{
			cin >> p;
			del(p);
		}
		else if(t==3)
		{
			cin >> p >> l;
			cout << que(p, l) << endl;
		}
	}
}