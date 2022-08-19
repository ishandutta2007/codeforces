#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 105
#define ll long long
#define ld double
using namespace std;
ld dp[maxn][maxn * 10];
struct th
{
	int a;
	int p;
	bool operator < (const th &x)const
	{
		return a > x.a;
	}
}p[maxn];
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		ld c, t;
		scanf("%lf%lf", &c, &t);
		for(int j = 1; j <= n; j++)
			scanf("%d%d", &p[j].a, &p[j].p);
		sort(p + 1, p + n + 1);
		for(int i = 0; i < maxn; i++)
			for(int j = 0; j < maxn * 10; j++)
				dp[i][j] = c * ((t + 1 / c) * (t + 1 / c)) * 10;	
				
		dp[0][0] = 0;
		for(int j = n; j >= 1; j--)
			for(int s = n - j + 1; s >= 0; s--)
				for(int m = 10 * s; m >= 0; m--)
				{
					if(s >= 1 && m >= p[j].p)
						dp[s][m] = min(dp[s][m], 
									   p[j].a / 0.9 + (dp[s - 1][m - p[j].p] / 0.9));
				}
		for(int m = 10 * n; m >= 0; m--)
		{
			int fl = 0;
			for(int j = 0; j <= n; j++)
			{
				ld pls = 10 * j - 1 / c;
				ld mns = 1 / c + dp[j][m] ;
				if(dp[j][m] * c >= 1)
					mns = 2 * sqrt(dp[j][m] / c);
				if(pls + mns < t) 
				{
					fl = 1;
					break;
				}
			}
			if(fl)
			{
				printf("%d\n", m);
				break;
			}
		}
	}
	return 0;
}