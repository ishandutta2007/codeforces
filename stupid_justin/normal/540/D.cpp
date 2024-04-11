#include<bits/stdc++.h>
using namespace std;
const int N=105;
double dp[N][N][N],rwin,swin,pwin;
int r,s,p,tot;

int main()
{
    cin>>r>>s>>p;
    int tot;
    dp[r][s][p]=1.0;
    int i,j,k;
    for(i=r;i>=0;i--)
    	for(j=s;j>=0;j--)
    		for(k=p;k>=0;k--)
    		{
    		    tot=i*j+j*k+k*i;
				if(i&&k) dp[i-1][j][k]+=1.0*dp[i][j][k]*k*i/tot;
				if(j&&i) dp[i][j-1][k]+=1.0*dp[i][j][k]*i*j/tot;
				if(k&&j) dp[i][j][k-1]+=1.0*dp[i][j][k]*j*k/tot;
				if(!j&&!k&&i) rwin+=dp[i][j][k];
				if(!i&&!k&&j) swin+=dp[i][j][k];
				if(!i&&!j&&k) pwin+=dp[i][j][k];
  		   }
    printf("%.9lf %.9lf %.9lf\n",rwin,swin,pwin);
}