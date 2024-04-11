#include<bits/stdc++.h>
using namespace std;
double dp[1005][1005];
int n,m,x,y,i,j,t;
int main()
{
	
	cin>>n>>m>>x>>y;
	for(int i=n-1;i>=x;i--)
    {
        int T=100;
        while (T--)
        {
            if (m==1) dp[i][1]=(dp[i][1]+dp[i+1][1])/2.0+1;
            else
            {
                dp[i][1]=(dp[i][1]+dp[i][2]+dp[i+1][1])/3.0+1;
                dp[i][m]=(dp[i][m]+dp[i][m-1]+dp[i+1][m])/3.0+1;
                for (int j=2;j<m;j++) dp[i][j]=(dp[i][j]+dp[i][j-1]+dp[i][j+1]+dp[i+1][j])/4.0+1;
            }
        }
    }
    printf("%.4lf\n",dp[x][y]);
}