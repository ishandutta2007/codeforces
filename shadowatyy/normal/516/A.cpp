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

int n;

string s;

int f[10][4];

map<VI, int> dp;

VI c(4), ans;

void solve(VI c)
{
	dp[c] = -inf;

	if(c[0]+c[1]+c[2]+c[3]==0)
	{
		dp[c] = 0;
		return;
	}

	for(int i = 9; i >= 2; --i)
	{
		VI curr = c;

		for(int k = i; k >= 2; --k)
		{
			for(int j = 0; j < 4; ++j)
			{
				curr[j] -= f[k][j];
			}
		}

		if(curr[0]>=0 && curr[1]>=0 && curr[2]>=0 && curr[3]>=0)
		{
			if(dp.find(curr)==dp.end())
				solve(curr);

			dp[c] = max(dp[c], dp[curr]+1);
		}		
	}
}

void znajdz(VI c)
{	
	if(c[0]+c[1]+c[2]+c[3]==0)
		return;

	for(int i = 9; i >= 2; --i)
	{
		VI curr = c;

		for(int k = i; k >= 2; --k)
		{
			for(int j = 0; j < 4; ++j)
			{
				curr[j] -= f[k][j];
			}
		}

		if(curr[0]>=0 && curr[1]>=0 && curr[2]>=0 && curr[3]>=0 && dp[curr]+1==dp[c])
		{
			znajdz(curr);
			ans.pb(i);
			return;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	f[2][0] = 1;
	f[3][1] = 1;
	f[4][0] = 2;
	f[5][2] = 1;
	f[6][0] = 1;
	f[6][1] = 1;
	f[7][3] = 1;
	f[8][0] = 3;
	f[9][1] = 2;

	cin >> n >> s;

	for(auto it:s)
	{
		for(int i = it-'0'; i >= 2; --i)
		{
			c[0] += f[i][0];
			c[1] += f[i][1];
			c[2] += f[i][2];
			c[3] += f[i][3];
		}
	}

	solve(c);
	znajdz(c);

	reverse(ALL(ans));

	for(auto it:ans)
		cout << it;
}