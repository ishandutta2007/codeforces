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

#define double long double
const int N = 53;

int n, R, sum;

int f[N];
int s[N];
double p[N];

double dp[N][N*100+107];

double depe(double ans)
{
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j < N*100+107; ++j)
		{
			dp[i][j] = ans;
		}
	}

	for(int i = 0; i <= R; ++i)
	{
		dp[n][i] = 0; 
	}

	for(int i = n-1; i >= 0; --i)
	{
		for(int j = 0; j <= R; ++j)
		{
			double yolo = p[i+1]*(f[i+1]+dp[i+1][j+f[i+1]])+(1-p[i+1])*(s[i+1]+dp[i+1][j+s[i+1]]);
			
			if(i==0)
				dp[i][j] = yolo;
			else
				dp[i][j] = min(yolo, ans);
		}
	}

	return dp[0][0];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> R;

	for(int i = 1; i <= n; ++i)
	{
		cin >> f[i] >> s[i] >> p[i];
		p[i] /= 100;
	}

	double l = 0, r = 1e18;

	for(int i = 1; i <= 100; ++i)
	{
		double m = (l+r)/2;

		if(depe(m)>m)
			l = m;
		else
			r = m;
	}

	cout << fixed << setprecision(15) << l;
}