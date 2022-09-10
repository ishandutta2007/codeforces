#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 5e5+7;
#define int long long

int n, k, d;

int a[N];
int dp[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> d;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	sort(a+1, a+1+n);

	dp[0] = 1;

	int curr = 1;

	for(int i = 1; i <= n; ++i)
	{
		while(abs(a[i]-a[curr])>d)
			++curr;

		if(i-k>=0 && i-k>=curr-2 && dp[i-k]-(curr-2==-1?0:dp[curr-2])>0)
			dp[i] = 1;
		else
			dp[i] = 0;

		dp[i] += dp[i-1];
	}	

	if(dp[n]-dp[n-1])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}