#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define M 5000000

int t, a, b;

int sito[M+1];
int dp[M];

int main()
{
	for(int i = 2; i <= M; ++i)
	{
		if(!sito[i])
		{
			sito[i] = i;

			for(int j = i; j <= M; j += i)
			{
				sito[j] = i;
			}
		}	
	}

	dp[1] = 0;

	for(int i = 2; i <= M; ++i)
	{
		dp[i] = dp[i/sito[i]]+1;
	}

	for(int i = 1; i <= M; ++i)
	{
		dp[i] += dp[i-1];
	}

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d%d", &b, &a);

		printf("%d\n", dp[b]-dp[a]);
	}
}