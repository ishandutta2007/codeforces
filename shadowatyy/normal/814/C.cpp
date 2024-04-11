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

#define N 1507

int n, q, m;

char c;

string s;

int ok[N][26];

int ile[N][26];

int solve(int m, char c)
{
	int j = 1, res = 1;

	for(int i = 1; i <= n; ++i)
	{
		while(j<n && ile[j+1][c-'a']-ile[i-1][c-'a']+m>=j+1-i+1)
			++j;

		res = max(res, j-i+1);
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		++ile[i][s[i]-'a'];

		for(int j = 0; j < 26; ++j)
		{
			ile[i][j] += ile[i-1][j];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		memset(ok[i], -1, sizeof ok[i]);
	}

	cin >> q;

	while(q--)
	{
		cin >> m >> c;

		if(ok[m][c-'a']!=-1)
			cout << ok[m][c-'a'] << endl;
		else
			cout << (ok[m][c-'a'] = solve(m, c)) << endl;
	}
}