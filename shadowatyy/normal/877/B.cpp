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
using namespace std;

const int N = 5007;

int n;

string s, t;

short dp[N][3*N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();
	s = '#'+s;
	t = '#';

	for(int i = 1; i <= n; ++i)
	{
		t += 'a';
	}

	for(int i = 1; i <= n; ++i)
	{
		t += 'b';
	}

	for(int i = 1; i <= n; ++i)
	{
		t += 'a';
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= 3*n; ++j)
		{
			if(s[i]==t[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[n][3*n];
}