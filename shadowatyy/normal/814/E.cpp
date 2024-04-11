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

#define N 51
#define M inf

int n;

int d[N];

ll dp[2][N][N][N][N]; //[][p1][p2][c1][c2]

inline void add(ll &a, ll b)
{
	a += b;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> d[i];
	}

	if(d[1]==3 && d[2]==3)
		dp[0][0][1][0][1] = 1;
	else if(d[1]==2 && d[2]==3)
		dp[0][1][0][0][1] = 1;
	else if(d[1]==3 && d[2]==2)
		dp[0][0][1][1][0] = 1;
	else if(d[1]==2 && d[2]==2)
		dp[0][1][0][1][0] = 1;

	for(int v = 2; v < n; ++v)
	{
		int i = v%2;

		for(int p1 = 0; p1 <= v+1; ++p1)
		{
			for(int p2 = 0; p1+p2 <= v+1; ++p2)
			{
				for(int c1 = 0; p1+p2+c1 <= v+1; ++c1)
				{
					for(int c2 = 0; p1+p2+c1+c2 <= v+1; ++c2)
					{
						dp[i^1][p1][p2][c1][c2] = 0;
					}
				}
			}
		}

		for(int p1 = 0; p1 <= v; ++p1)
		{
			for(int p2 = 0; p1+p2 <= v; ++p2)
			{
				for(int c1 = 0; p1+p2+c1 <= v; ++c1)
				{
					for(int c2 = 0; p1+p2+c1+c2 <= v; ++c2)
					{
						ll curr = dp[i][p1][p2][c1][c2]%M;

						if(d[v+1]==3)
						{
							//zostaje w aktualnej grupie

								//zostawiam krawedzie

								if(p1>0) add(dp[i^1][p1-1][p2][c1][c2+1], p1*curr);
								if(p2>0) add(dp[i^1][p1+1][p2-1][c1][c2+1], p2*curr); 

								//jedna krawedz do tej samej grupy

									//do c1

									if(p1>0 && c1>0) add(dp[i^1][p1-1][p2][c1-1+1][c2], p1*c1*curr);
									if(p2>0 && c1>0) add(dp[i^1][p1+1][p2-1][c1-1+1][c2], p2*c1*curr);

									//do c2

									if(p1>0 && c2>0) add(dp[i^1][p1-1][p2][c1+1+1][c2-1], p1*c2*curr);
									if(p2>0 && c2>0) add(dp[i^1][p1+1][p2-1][c1+1+1][c2-1], p2*c2*curr);

								//dwie krawedzie do tej samej grupy

									//do c1

									if(p1>0 && c1>1) add(dp[i^1][p1-1][p2][c1-2][c2], p1*c1*(c1-1)/2*curr);
									if(p2>0 && c1>1) add(dp[i^1][p1+1][p2-1][c1-2][c2], p2*c1*(c1-1)/2*curr);

									//do c2

									if(p1>0 && c2>1) add(dp[i^1][p1-1][p2][c1+2][c2-2], p1*c2*(c2-1)/2*curr);
									if(p2>0 && c2>1) add(dp[i^1][p1+1][p2-1][c1+2][c2-2], p2*c2*(c2-1)/2*curr);

									//po jednej 

									if(p1>0 && c1>0 && c2>0) add(dp[i^1][p1-1][p2][c1-1+1][c2-1], p1*c1*c2*curr);
									if(p2>0 && c1>0 && c2>0) add(dp[i^1][p1+1][p2-1][c1-1+1][c2-1], p2*c1*c2*curr);

							//tworze nowa grupe

							if(p1==0 && p2==0 && c1>0) add(dp[i^1][c1-1][c2][0][1], c1*curr);
							if(p1==0 && p2==0 && c2>0) add(dp[i^1][c1+1][c2-1][0][1], c2*curr);

						}
						else
						{
							//zostaje w aktualnej grupie

								//zostawiam krawedzie

								if(p1>0) add(dp[i^1][p1-1][p2][c1+1][c2], p1*curr);
								if(p2>0) add(dp[i^1][p1+1][p2-1][c1+1][c2], p2*curr); 

								//jedna krawedz do tej samej grupy

									//do c1

									if(p1>0 && c1>0) add(dp[i^1][p1-1][p2][c1-1][c2], p1*c1*curr);
									if(p2>0 && c1>0) add(dp[i^1][p1+1][p2-1][c1-1][c2], p2*c1*curr);

									//do c2

									if(p1>0 && c2>0) add(dp[i^1][p1-1][p2][c1+1][c2-1], p1*c2*curr);
									if(p2>0 && c2>0) add(dp[i^1][p1+1][p2-1][c1+1][c2-1], p2*c2*curr);

							//tworze nowa grupe

							if(p1==0 && p2==0 && c1>0) add(dp[i^1][c1-1][c2][1][0], c1*curr);
							if(p1==0 && p2==0 && c2>0) add(dp[i^1][c1+1][c2-1][1][0], c2*curr);

						}
					}
				}
			}
		}
	}

	cout << dp[n%2][0][0][0][0]%M;
}