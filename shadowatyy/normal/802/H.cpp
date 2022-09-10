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
#define flush fflush(stdout)
using namespace std;

#define N 57
#define int long long

int n;

int dp[N];
int ile[N];

int dwumian(int a, int b)
{
	int res = 1;

	for(int i = a-b+1; i <= a; ++i)
	{
		res *= i;
	}

	for(int i = 1; i <= b; ++i)
	{
		res /= i;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= 20; ++i)
	{
		dp[i] = dwumian(3*i, 3);
	}

	cin >> n;

	for(int i = 20; i >= 1; --i)
	{
		while(n>=dp[i])
		{
			++ile[i];
			n -= dp[i];
		}
	}

	for(int i = 1; i <= 20; ++i)
	{
		cout << "aaa";

		while(ile[i]--)
			cout << "b";
	}

	cout << " aaab";
}