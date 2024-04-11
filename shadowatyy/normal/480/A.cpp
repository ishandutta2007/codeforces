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

int n;

int A[N];
int B[N];

VI v;

bool comp(int a, int b)
{
	return mp(A[a], B[a])<mp(A[b], B[b]);
}

bitset<N> dp;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> A[i] >> B[i];
		v.pb(i);
	}

	v.pb(0);
	sort(ALL(v), comp);

	dp[0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(dp[i-1])
		{	
			if(B[v[i]]>=B[v[i-1]])
				dp[i] = 1;
			else
				dp[i] = 0;
		}
		else
		{
			if(B[v[i]]>=A[v[i-1]])
				dp[i] = 1;
			else
				dp[i] = 0;
		}
	}

	if(dp[n])
		cout << B[v.back()];
	else
		cout << A[v.back()];
}