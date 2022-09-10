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

const int N = 1e5+7;

int n, any0;

int a[N];
int dp[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	sort(a+1, a+1+n);

	for(int i = n; i >= 1; --i)
	{
		if(!dp[i+1])
			dp[i] = 1;

		if(any0)
			dp[i] = 1;

		if(a[i-1]!=a[i] && !dp[i+1])
			any0 = 1;
	}

	if(dp[1])
		cout << "Conan";
	else
		cout << "Agasa";
}