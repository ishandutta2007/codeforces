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

#define N 8007
#define M1 1000000007
#define M2 1000000009
#define M3 1000696969
#define P1 29
#define P2 31
#define P3 37

int n;

string s;

int ile[N][N];

ll pot1[N];
ll pot2[N];
ll pot3[N];
ll h1[N];
ll h2[N];
ll h3[N];

int dp[N][N];
int d[N];
int ans[N];

bool equal(int a, int b, int c, int d)
{
	int r = rand()%3;

	if(r==0)
		return ((h1[b]-h1[a-1]+M1)%M1*pot1[d-b])%M1==(h1[d]-h1[c-1]+M1)%M1 && ((h2[b]-h2[a-1]+M2)%M2*pot2[d-b])%M2==(h2[d]-h2[c-1]+M2)%M2;
	else if(r==1)
		return ((h1[b]-h1[a-1]+M1)%M1*pot1[d-b])%M1==(h1[d]-h1[c-1]+M1)%M1 && ((h3[b]-h3[a-1]+M3)%M3*pot3[d-b])%M3==(h3[d]-h3[c-1]+M3)%M3;
	else if(r==2)
		return ((h2[b]-h2[a-1]+M2)%M2*pot2[d-b])%M2==(h2[d]-h2[c-1]+M2)%M2 && ((h3[b]-h3[a-1]+M3)%M3*pot3[d-b])%M3==(h3[d]-h3[c-1]+M3)%M3;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	srand(time(NULL));

	pot1[0] = pot2[0] = pot3[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		d[i] = d[i/10]+1;
		pot1[i] = (pot1[i-1]*P1)%M1;
		pot2[i] = (pot2[i-1]*P2)%M2;
		pot3[i] = (pot3[i-1]*P3)%M3;
	}

	cin >> s;
	n = s.size();
	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		h1[i] = (h1[i-1]+s[i]*pot1[i])%M1;
		h2[i] = (h2[i-1]+s[i]*pot2[i])%M2;
		h3[i] = (h3[i-1]+s[i]*pot3[i])%M3;
	}

	for(int i = n; i >= 1; --i)
	{
		for(int j = 1; i+j-1 <= n; ++j)
		{
			if(i+j-1+j<=n && equal(i, i+j-1, i+j, i+j-1+j))
				dp[i][j] = dp[i+j][j]+1;
			else
				dp[i][j] = 1;
		}
	}

	memset(ans, inf16, sizeof ans);

	ans[0] = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 1; i+j <= n; ++j)
		{
			for(int k = 1; k <= dp[i+1][j] && i+j*k<=n; ++k)
			{
				ans[i+j*k] = min(ans[i+j*k], ans[i]+j+d[k]);
			}
		}
	}

	cout << ans[n];
}