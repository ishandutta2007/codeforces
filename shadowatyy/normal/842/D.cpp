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

const int N = 3e5+7;

int n, m, curr = 1, y;

VI val;

int trie[32*N][2];
int sub[32*N];

void add(int v)
{
	int s = 1;

	for(int i = 30; i >= 0; --i)
	{
		if(v&(1<<i))
		{
			if(!trie[s][1])
				trie[s][1] = ++curr;

			s = trie[s][1];
			++sub[s];
		}
		else
		{
			if(!trie[s][0])
				trie[s][0] = ++curr;

			s = trie[s][0];
			++sub[s];
		}
	}
}

int ask(int v)
{
	int res = 0, s = 1;

	for(int i = 30; i >= 0; --i)
	{
		if(v&(1<<i))
		{
			if(sub[trie[s][1]]<(1<<i))
				s = trie[s][1];
			else
			{
				s = trie[s][0];
				res += (1<<i);
			}
		}
		else
		{
			if(sub[trie[s][0]]<(1<<i))
				s = trie[s][0];
			else
			{
				s = trie[s][1];
				res += (1<<i);
			}
		}
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		val.pb(a);
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	for(auto it:val)
		add(it);

	while(m--)
	{
		int x;
		cin >> x;
		y ^= x;
		cout << ask(y) << endl;
	}
}