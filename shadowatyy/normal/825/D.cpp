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

int n, m, wolne, res;

string s, t;

int ile[256];
int curr[256];

vector<char> add;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s >> t;

	n = s.size();
	m = t.size();

	s = '#'+s;
	t = '#'+t;

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]!='?')
			++ile[s[i]];
	}

	for(int i = 1; i <= n/m+1; ++i)
	{
		memset(curr, 0, sizeof curr);

		for(int j = 1; j <= m; ++j)
		{
			curr[t[j]] += i;
		}

		int used = 0;

		for(int j = 0; j < 256; ++j)
		{
			used += max(curr[j], ile[j]);
		}

		if(used>n)
		{
			res = i-1;
			break;
		}
	}

	memset(curr, 0, sizeof curr);

	for(int i = 1; i <= m; ++i)
	{
		curr[t[i]] += res;
	}

	for(int i = 0; i < 256; ++i)
	{
		while(curr[i]>ile[i])
		{
			--curr[i];
			add.pb(char(i));
		}
	}

	int used = 0;

	for(int j = 0; j < 256; ++j)
	{
		used += ile[j];
	}

	while(used+add.size()<n)
		add.pb('a');

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]!='?')
			cout << s[i];
		else
		{
			cout << add.back();
			add.pop_back();
		}
	}
}