#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define mod 998244353

using namespace std;
int a[maxn];
int dp[maxn][205][2]; // 1 : need 0 : not need
int cal(int i, int j, int k, int l)
{
	int nd = 0;
	if(l > j) nd = 1;
	int nans = dp[i + 1][l][nd];
	if(k && l < j) return 0;
	return nans;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int mxs = 200;
	for(int i = n + 1; i >= 1; i--)
		for(int j = mxs; j >= 0; j--)
			for(int k = 0; k < 2; k++)
			{
				if(i == n + 1)
				{
					if(k == 0) dp[i][j][k] = 1;
					else dp[i][j][k] = 0;
				}
				else 
				{
					if(a[i] != -1)
						dp[i][j][k] = cal(i, j, k, a[i]);
					else
					{
						if(j == mxs)
							for(int l = 1; l <= mxs; l++)
								dp[i][j][k] = (dp[i][j][k] + cal(i, j, k, l)) % mod;
						else
						{
							dp[i][j][k] = dp[i][j + 1][k];
							for(int l = j; l <= j + 1; l++)
								dp[i][j][k] -= cal(i, j + 1, k, l), 
								dp[i][j][k] += cal(i, j, k, l), 
								dp[i][j][k] %= mod;
							if(dp[i][j][k] < 0) dp[i][j][k] += mod;
						}
					}
				}
			//	cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
			}
	printf("%d\n", dp[1][0][0]);
	return 0;
}