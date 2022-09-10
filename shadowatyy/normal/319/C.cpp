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

#define N 100007

int n;

ll a[N];
ll b[N];

ll dp[N];

deque<int> Q;

inline double inter(int i, int j)
{
	return double(dp[j]-dp[i])/(b[i]-b[j]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}

	dp[1] = 0;
	Q.pb(1);

	for(int i = 2; i <= n; ++i)
	{
		while(Q.size()>=2 && dp[Q[0]]+a[i]*b[Q[0]]>=dp[Q[1]]+a[i]*b[Q[1]])
			Q.pop_front();

		dp[i] = dp[Q.front()]+a[i]*b[Q.front()];

		while(Q.size()>=2 && inter(Q[Q.size()-2], i)<inter(Q[Q.size()-2], Q[Q.size()-1]))
			Q.pop_back();

		Q.pb(i);
	}

	cout << dp[n];

}