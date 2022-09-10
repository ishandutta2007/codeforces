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

#define N 10007

int n;

string s;

int dp[N][5];

vector<string> res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();
	s = '#'+s+"#######";

	if(n>=7)
		dp[n-1][2] = 1;

	if(n>=8)
		dp[n-2][3] = 1;

	for(int i = n-1; i >= 6; --i)
	{
		if(dp[i+2][2] && s.substr(i, 2)!=s.substr(i+2, 2))
			dp[i][2] = 1;

		if(dp[i+2][3])
			dp[i][2] = 1;

		if(dp[i+3][3] && s.substr(i, 3)!=s.substr(i+3, 3))
			dp[i][3] = 1;

		if(dp[i+3][2])
			dp[i][3] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(dp[i][3])
			res.pb(s.substr(i, 3));

		if(dp[i][2])
			res.pb(s.substr(i, 2));
	}

	sort(ALL(res));
	res.erase(unique(ALL(res)), res.end());

	cout << res.size() << endl;

	for(auto it:res)
		cout << it << endl;
}