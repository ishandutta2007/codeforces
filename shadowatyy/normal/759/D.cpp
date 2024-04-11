#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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

#define N 5007
#define M inf

int n, c;

int a[N];

string s;

int dp[N][N];

int nast[N][26];

int last[26];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	a[0] = 26;

	cin >> n >> s;

	for(auto it:s)
	{
		if(a[c]!=it-'a')
			a[++c] = it-'a';
	}

	for(int i = c; i >= 1; --i)
	{
		for(int j = 0; j < 26; ++j)
		{
			nast[i][j] = last[j];
		}

		last[a[i]] = i;
	}

	dp[1][0] = 1;

	for(int i = 1; i <= c; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			for(int l = 0; l < 26; ++l)
			{
				if(a[i]==l)
					dp[i][j+1] = (dp[i][j+1]+dp[i][j])%M;
				else if(nast[i][l])
					dp[nast[i][l]][j+1] = (dp[nast[i][l]][j+1]+dp[i][j])%M;
			}
		}
	}

	int res = 0;

	for(int i = 1; i <= c; ++i)
	{
		res = (res+dp[i][n])%M;
	}

	cout << res;
}