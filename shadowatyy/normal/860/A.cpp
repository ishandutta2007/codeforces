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

const int N = 3007;

int n;

string s;

int dp[N];

bitset<256> bad;

vector<string> res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	bad.set();
	bad['a'] = 0;
	bad['e'] = 0;
	bad['i'] = 0;
	bad['o'] = 0;
	bad['u'] = 0;

	cin >> s;

	n = s.size();
	s = '#'+s;

	memset(dp, inf16, sizeof dp);
	dp[0] = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			if(i+3<=j && bad[s[j]] && bad[s[j-1]] && bad[s[j-2]] && (s[j]!=s[j-1] || s[j-1]!=s[j-2]))
			{
				dp[j-1] = min(dp[j-1], dp[i]+1);
				break;
			}

			dp[j] = min(dp[j], dp[i]+1);
		}
	}

	int curr = n;

	while(curr)
	{
		for(int i = curr-1; i >= 0; --i)
		{
			if(dp[i]+1==dp[curr])
			{
				res.pb(s.substr(i+1, curr-i));
				curr = i;
				break;
			}
		}
	}

	reverse(ALL(res));

	for(auto it:res)
		cout << it << " ";
}